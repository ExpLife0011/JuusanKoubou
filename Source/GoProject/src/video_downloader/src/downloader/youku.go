package downloader

import (
    . "ml/strings"
    . "ml/dict"

    "fmt"
    "time"
    "regexp"
    "crypto/des"

    "spew"

    "ml/net/http"
    "ml/encoding/base64"
)

var youkuVideoIdPattern = regexp.MustCompile(`(?U)currentEncodeVid\s*:\s*"(.*)"`)
var youkuVideoIdPattern2 = regexp.MustCompile(`(?U)videoId2\s*=\s*'(.*)';`)

type YoukuVideoInfoSeg struct {
    totalMillisecondsAudio      int64
    totalMillisecondsVideo      int64
    size                        int64
    cdn_url                     String
    fileid                      String
    key                         String
    hd                          int
    container                   String
}

type YoukuVideoInfo struct {
    segs    []YoukuVideoInfoSeg

    //security struct {
    //    sid             String
    //    token           String
    //    encryptString   String
    //    ip              int64
    //}
}

type YoukuDownloader struct {
    *baseDownloader
    vid         String
    videoInfo   YoukuVideoInfo
}

func NewYouku(url String) Downloader {
    d := &YoukuDownloader{
        baseDownloader: newBase(url),
    }

    return d
}

func (self *YoukuDownloader) Analysis() (result AnalysisResult, err error) {
    result = AnalysisNotSupported

    resp, err := self.session.Get(self.url)
    if err != nil {
        return
    }

     content := resp.Text()
     m := youkuVideoIdPattern.FindStringSubmatch(content.String())
     if len(m) == 0 {
         m = youkuVideoIdPattern2.FindStringSubmatch(content.String())
     }

    vid := String(m[1])

    fmt.Println("vid", vid)

    err = self.getVideoInfo(vid)
    if err != nil {
        return
    }

    self.parseVideoInfo()

    return AnalysisSuccess, nil
}

//
// http://k.youku.com/player/getFlvPath/sid/1474526152477 10f8 1137_00/st/mp4/fileid/030008010057E0B89D83C2019C3C1CAEE308CE-FEF5-6CE1-579C-51C872568410
// start=0
// K=dbcbe7f68e9006d7282bbfbe
// hd=1
// myp=0
// ts=68
// ymovie=1
// ypp=0
// ctype=10
// ev=1
// token=0939
// oip=244858955
// ep=p6F36Pjts%2BtCLWpTKCmthZj6RxeWJBP6lq77e%2FGGIqfo1mmyw7J4c2kYmVCZ5DuJFtEHjVM2G9unL9LD4GYQw0Hi%2BuI2jYE4rOI3l9%2BAxO8c8VxcnEnSiNdLuaWLAtdsasw%2FFBjp2uM%3D
// p6F36Pjts+tCLWpTKCmthZj6RxeWJBP6lq77e/GGIqfo1mmyw7J4c2kYmVCZ5DuJFtEHjVM2G9unL9LD4GYQw0Hi+uI2jYE4rOI3l9+AxO8c8VxcnEnSiNdLuaWLAtdsasw/FBjp2uM=
// yxon=1
// special=true
//

func (self *YoukuDownloader) getVideoInfo(vid String) error {
    var info JsonDict

    resp, err := self.session.Get("http://log.mmstat.com/yt.gif")
    if err != nil {
        return err
    }

    var cna String

LOOK_UP_CNA:
    for _, cs := range self.session.AllCookies() {
        for _, c := range cs {
            if c.Name == "cna" {
                cna = String(c.Value)

                nc := *c
                nc.Domain = ".youku.com"

                self.session.SetCookiesEx("http://youku.com", &nc)

                break LOOK_UP_CNA
            }
        }
    }

    if cna.IsEmpty() {
        self.Fatal("can't find cna")
    }

    resp, err = self.session.Get(
                    "http://ups.youku.com/ups/get.json",
                    http.Params(Dict{
                        "vid"       : vid,
                        "ccode"     : "0401",
                        "utid"      : cna,
                        "client_ip" : "192.168.1.1",
                        "client_ts" : time.Now().Unix(),
                    }),
                )
    if err != nil {
        return err
    }

    err = resp.Json(&info)
    if err != nil {
        return err
    }

    self.parseVideoSegs(info)

    //self.videoInfo.security.sid, self.videoInfo.security.token = self.decryptSidAndToken(self.videoInfo.security.encryptString)
    fmt.Printf("%+v\n", spew.Sdump(self.videoInfo))

    return nil
}

func (self *YoukuDownloader) parseVideoSegs(info JsonDict) error {
    data := info.Map("data")

    self.title = data.Map("video").Str("title")

    //security := data.Map("security")
    //self.videoInfo.security.encryptString = security.Str("encrypt_string")
    //self.videoInfo.security.ip = int64(security.Int("ip"))

    stream := data.Array("stream")

    type StreamType struct {
        name        String
        profile     String
        container   String
        priority    int
        hd          int
    }

    getStreamType := func (stream JsonDict) StreamType {
        var st StreamType

        switch t := stream.Str("stream_type"); t {
            case "mp4hd3", "hd3":
                st.priority = -6
                st.profile = "1080P"
                st.container = "flv"
                st.hd = 3

            case "mp4hd2", "hd2":
                st.priority = 5
                st.profile = "超清"
                st.container = "flv"
                st.hd = 2

            case "mp4hd", "mp4":
                st.priority = 4
                st.profile = "高清"
                st.container = "mp4"
                st.hd = 1

            case "flvhd", "flv":
                st.priority = 2
                st.profile = "标清"
                st.container = "flv"
                st.hd = 0

            case "3gphd":
                st.priority = 1
                st.profile = "标清（3GP）"
                st.container = "3gp"
                st.hd = 0

            default:
                self.Critical("unsupported stream type: %v", t)
                panic(nil)
        }

        return st
    }

    var streamType StreamType

    for index := range stream {
        s := stream.Map(index)

        st := getStreamType(s)
        if st.priority < streamType.priority {
            continue
        }

        streamType = st

        segs := s.Array("segs")

        fmt.Printf("stream_type: %+v\n", streamType)

        self.videoInfo.segs = nil

        for index := range segs {
            seg := segs.Map(index)

            self.videoInfo.segs = append(self.videoInfo.segs, YoukuVideoInfoSeg{
                totalMillisecondsAudio  : seg.Int64("total_milliseconds_audio"),
                totalMillisecondsVideo  : seg.Int64("total_milliseconds_video"),
                size                    : seg.Int64("size"),
                cdn_url                 : seg.Str("cdn_url"),
                fileid                  : seg.Str("fileid"),
                key                     : seg.Str("key"),
                hd                      : streamType.hd,
                container               : streamType.container,
            })
        }
    }

    return nil
}

func (self *YoukuDownloader) parseVideoInfo() error {
    for index, seg := range self.videoInfo.segs {
        // com\youku\utils\GetUrl.as

        //url := fmt.Sprintf("http://k.youku.com/player/getFlvPath/sid/%s_00/st/%s/fileid/%s", self.videoInfo.security.sid, seg.container, seg.fileid)
        //resp, err := self.session.Get(
        //                url,
        //                http.Params(Dict{
        //                    "start"     : "0",
        //                    "K"         : seg.key,
        //                    "hd"        : seg.hd,
        //                    "myp"       : "0",
        //                    "ts"        : "64",
        //                    "ypp"       : "0",      // P2PConfig.ypp @ com\youku\P2PConfig.as
        //                    "ctype"     : "10",     // PlayerConstant.CTYPE @ com\youku\data\PlayerConstant.as
        //                    "ev"        : "1",      // PlayerConstant.EV @ com\youku\data\PlayerConstant.as
        //                    "token"     : self.videoInfo.security.token,
        //                    "oip"       : self.videoInfo.security.ip,
        //                    "ep"        : self.encryptEp(self.videoInfo, seg.fileid),
        //                    "yxon"      : "1",
        //                    "special"   : "true",
        //                }),
        //                http.Headers(Dict{
        //                    "X-Requested-With"  : "ShockwaveFlash/25.0.0.171",
        //                    "Accept"            : "*/*",
        //                    "Referer"           : self.url,
        //                }),
        //                http.Ignore404(false),
        //            )
        //if err != nil {
        //    self.Critical("get seg %d failed: %v", index, err)
        //    panic(nil)
        //    return err
        //}

        //var r JsonArray
        //
        //err = resp.Json(&r)
        //if err != nil {
        //    self.Critical("get seg %d failed: %v", index, err)
        //    panic(nil)
        //    return err
        //}

        if len(self.videoInfo.segs) == 1 {
            self.links = append(self.links, DownloadLink{
                url : seg.cdn_url,
                name: String(fmt.Sprintf("%s.%s", self.title, seg.container)),
            })
        } else {
            self.links = append(self.links, DownloadLink{
                url : seg.cdn_url,
                name: String(fmt.Sprintf("%s.part%02d.%s", self.title, index + 1, seg.container)),
            })
        }
    }

    return nil
}

func (self *YoukuDownloader) decryptSidAndToken(encryptString String) (sid, token String) {
    data := base64.DecodeString(encryptString.String())

    cipher, _ := des.NewCipher([]byte("00149ad5"))
    for i := 0; i < len(data); i += cipher.BlockSize() {
        cipher.Decrypt(data[i:], data[i:])
    }

    decrypted := String(data).Split("\x00", 1)[0].Split("_", 1)

    sid = decrypted[0]
    token = decrypted[1]
    return
}

//func (self *YoukuDownloader) encryptEp(info YoukuVideoInfo, fileId String) String {
//    bctime := 0
//    ep := fmt.Sprintf("%v_%v_%v_%v", info.security.sid, fileId, info.security.token, bctime)
//    sum := md5.Sum([]byte(ep + "_kservice"))
//
//    ep = ep + "_" + fmt.Sprintf("%x", sum[:])[:4]
//
//    data := []byte(ep)
//
//    cipher, _ := des.NewCipher([]byte("21dd8110"))
//
//    for len(data) % cipher.BlockSize() != 0 {
//        data = append(data, 0)
//    }
//
//    for i := 0; i < len(data); i += cipher.BlockSize() {
//        cipher.Encrypt(data[i:], data[i:])
//    }
//
//    return base64.EncodeToString(data)
//}
