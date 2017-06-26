#pragma comment(linker,"/SECTION:.text,ERW /MERGE:.rdata=.text /MERGE:.data=.text")
#pragma comment(linker,"/MERGE:.text=.Amano /SECTION:.Amano,ERW")

#pragma comment(lib, "dxguid.lib")

#ifdef MY_DEBUG
#pragma comment(linker,"/ENTRY:DllMain")
#endif

#define DEFAULT_STRUCT_ALIGN 8
#define SUPPORT_AAC_DECODE

#include "eden.h"
#include "vorbishook.cpp"
#include "gal_common.h"
#include "Mem.cpp"

OVERLOAD_CPP_NEW_WITH_HEAP(CMem::GetGlobalHeap())

#ifdef EDEN

//F_GetVolume   GetVolume      = (F_GetVolume)0x4491B0;
//F_DecodePng   DecodePng      = (F_DecodePng)0x440FCC;
F_FreeMemory  FreeMemory     = (F_FreeMemory)0x43F41F;
F_AllocMemory AllocateMemory = (F_AllocMemory)0x43F2D7;
F_AllocateMemoryForImage AllocateMemoryForImage = (F_AllocateMemoryForImage)0x418EA8;

//#define lpfn_NewString    0x406476
//#define lpfn_GameReadFile 0x43E01C
//#define lpfn_DecodePng    (F_DecodePng)0x440FCC

//#define lpfn_ov_clear          (F_ov_clear)0x48F280
//#define lpfn_ov_open_callbacks (F_ov_open_callbacks)0x48F380
//#define lpfn_ov_pcm_seek       (F_ov_pcm_seek)0x4908D0
//#define lpfn_ov_pcm_seek_lap   (F_ov_pcm_seek_lap)0x491790
//#define lpfn_ov_read           (F_ov_read)0x490F80
//#define lpfn_get_vorbis_info   (F_get_vorbis_info)0x41D434

#elif defined(EF_FIRST)

// #define SUPPORT_UCA_PLAY

//F_GetVolume   GetVolume      = (F_GetVolume)0x4847F0;
//F_DecodePng   DecodePng      = (F_DecodePng)0x45FB20;
F_FreeMemory  FreeMemory     = (F_FreeMemory)0x45F6B0;
F_AllocMemory AllocateMemory = (F_AllocMemory)0x45F580;
F_AllocateMemoryForImage AllocateMemoryForImage = (F_AllocateMemoryForImage)0x4220B0;

#define lpfn_GameReadFile 0x45A620
#define lpfn_SetDSVolume  0x483F90
#define lpfn_FillDSBuffer 0x44EB40

#elif defined(EF_LATTER)

// #define SUPPORT_UCA_PLAY

F_GetVolume   GetVolume      = (F_GetVolume)0x45CA5B;
//F_DecodePng   DecodePng      = (F_DecodePng)0x446358;
F_FreeMemory  FreeMemory     = (F_FreeMemory)0x44441A;
F_AllocMemory AllocateMemory = (F_AllocMemory)0x44430B;
F_AllocateMemoryForImage AllocateMemoryForImage = (F_AllocateMemoryForImage)0x41E3F3;

#define lpfn_GameReadFile 0x443039
#define lpfn_SetDSVolume  0x45C33D
#define lpfn_FillDSBuffer 0x43AE48

#elif defined(EF_FD)

//F_DecodePng   DecodePng      = (F_DecodePng)0x43FCC1;
F_FreeMemory  FreeMemory     = (F_FreeMemory)0x47B3E0;
F_AllocMemory AllocateMemory = (F_AllocMemory)0x47B280;
F_AllocateMemoryForImage AllocateMemoryForImage = (F_AllocateMemoryForImage)0x418536;

#define lpfn_DecodePng              (F_DecodePng)0x43FCC1
#define lpfn_AllocateMemory         (F_AllocMemory)0x47B280
#define lpfn_FreeMemory             (F_FreeMemory)0x47B3E0
#define lpfn_AllocateMemoryForImage (F_AllocateMemoryForImage)0x418536
#define lpfn_GameReadFile           0x43D1B2
#define lpfn_NewString              0x401608

#define lpfn_ov_clear          (F_ov_clear)0x477720
#define lpfn_ov_open_callbacks (F_ov_open_callbacks)0x477820
#define lpfn_ov_pcm_seek       (F_ov_pcm_seek)0x478D70
#define lpfn_ov_pcm_seek_lap   (F_ov_pcm_seek_lap)0x479C30
#define lpfn_ov_read           (F_ov_read)0x479420
#define lpfn_get_vorbis_info   (F_get_vorbis_info)0x422263

#endif

Bool   g_bPlayingVoice, g_bDynamicReadMask;
HFONT  g_hFontJP[2];
Char   g_szDefFaceName[LF_FACESIZE];
PByte  g_pbConvert;
DWORD  g_dwConvSize = 0, g_dwQuality;
HANDLE g_hEventNotify;
CRITICAL_SECTION g_csPlayVoice;

#define hInvalidKey ((HKEY)-2)

ASM Bool CDECL OldGetVorbisInfo(SEfFirstMemoryStream *pStream, vorbis_info *vi)
{
    ASM_DUMMY_AUTO();
}

Bool CDECL GetVorbisInfo(SEfFirstMemoryStream *pStream, vorbis_info *vi)
{
    OggVorbis_File *vf;

    INLINE_ASM
    {
#if defined(EDEN)
        lea eax, dword ptr [esi+80h];
#elif defined(EF_FD)
        lea eax, dword ptr [ebx+80h];
#endif
        mov vf, eax;
    }

    if (!IS_OGG_HOOKED(vf))
        return OldGetVorbisInfo(pStream, vi);

    *vi = *vf->vi;

    return True;
}

Bool CDECL GetVorbisInfoEfLatter(SEfFirstMemoryStream *pStream, vorbis_info *vi)
{
    SMinoriMemory *pMemory;
    do
    {
        if (pStream == NULL || vi == NULL)
            break;

        pMemory = pStream->MemoryBuffer;
        if (pMemory == NULL || pMemory->pbBuffer == NULL)
            break;

        if ((*(PLong)pMemory->pbBuffer & 0xFFFFFF) != TAG3('UCA'))
            break;

        vi->rate = 44100;
        vi->channels = 1;

        return True;

    } while (0);

    return OldGetVorbisInfo(pStream, vi);
}

#if defined(lpfn_SetDSVolume) && defined(lpfn_FillDSBuffer)

ASM bool FASTCALL OldPlayGameSound(LPVoid This)
{
    ASM_DUMMY(5);
    ASM_UNIQUE();
}

#define SetDSVolume(This, Volume) \
    ((bool (FASTCALL *)(LPVoid, Int, Int))lpfn_SetDSVolume)(This, 0, Volume)

#define FillDSBuffer(pVorbisPlayer, WaveBuffer, cbSize, Flags) \
    ((Void (FASTCALL *)(LPVoid, Int, LPVoid, Int, UInt))lpfn_FillDSBuffer)((pVorbisPlayer), 0, (WaveBuffer), (cbSize), (Flags))

Bool
PlayGameSoundWorker(
    SEfFirstVorbisPlayer *pVorbisPlayer,
    LPVoid                lpWaveBuffer,
    Int                   WaveLength
)
{
    ULong Status;
    PLong pLong;
    SWaveHeader *pWaveHeader;
    IDirectSoundBuffer  *pDSBuffer;
    SEfFirstDirectSound *pDSObject;

    pWaveHeader = (SWaveHeader *)lpWaveBuffer;

    pVorbisPlayer->IsPlaying = True;
/*
    pVorbisPlayer->fInit = True;
    pVorbisPlayer->fWhat = True;
    pVorbisPlayer->BufferLength = 0;
    pVorbisPlayer->Channels = pWaveHeader->wChannels;
    pVorbisPlayer->SampleRate - pWaveHeader->dwSamplesPerSec;
    pVorbisPlayer->AlwaysEqu16 = 0x10;

    ZeroMemory(&pVorbisPlayer->ogg_sync_state, 
        GetStructMemberOffset(SEfFirstVorbisPlayer, ogg_sync_state, lpWaveBuffer));
*/
    FillDSBuffer(
        pVorbisPlayer, 
        (PByte)pWaveHeader + sizeof(*pWaveHeader), 
        WaveLength - sizeof(*pWaveHeader), 
        0);

    pDSObject = pVorbisPlayer->DirectSoundObject;
    pDSBuffer = pDSObject->pDSBuffer;
    if (pVorbisPlayer->BufferOffset &&
        !pDSObject->bWhatIsThis)
    {
        pDSBuffer->SetCurrentPosition(0);
        SleepEx(50, False);
        pDSBuffer->Play(0, 0, DSBPLAY_LOOPING);
        SleepEx(50, False);
        pDSObject->bWhatIsThis = true;
        pDSObject->IntUnknown = 0;
    }

    do
    {
        pDSBuffer->GetStatus(&Status);
        if (!(Status & DSBSTATUS_PLAYING))
            break;

        ZeroMemory(pVorbisPlayer->lpWaveBuffer, 0x8000);
        pDSObject->IntUnknown3 = (pDSObject->IntUnknown1 - 1) * pDSObject->IntUnknown2;

        while (pDSObject->IntUnknown3 > 0)
        {
            SleepEx(10, False);
            if (pVorbisPlayer->bForceStop)
                break;

            FillDSBuffer(pVorbisPlayer, pVorbisPlayer->lpWaveBuffer, 0x8000, 1);
        }

    } while (0);

    pVorbisPlayer->IsPlaying = False;

    pLong = pVorbisPlayer->pLongUnknown;
    if (pLong)
    {
        ++pLong[1];
        pLong[0] = 0;
        pLong[2] = 0;
    }

    SetDSVolume(pVorbisPlayer->DirectSoundObject, 0);
    pDSBuffer->Stop();
    pDSBuffer->SetCurrentPosition(0);

    pVorbisPlayer->bStopped = true;

    return True;
}

Bool FASTCALL PlayGameSound(SEfFirstVorbisPlayer *pVorbisPlayer)
{
    Int    WaveLength;
    LPVoid lpWaveBuffer;
    SMinoriMemory *pMemory;
    SEfFirstMemoryStream *pStream;

    do
    {
        pStream = pVorbisPlayer->pStreamSecondary;
        if (pStream == NULL)
            break;

        pMemory = pStream->MemoryBuffer;
        if (pMemory == NULL || pMemory->pbBuffer == NULL)
            break;

        if ((*(PUInt)pMemory->pbBuffer & 0xFFFFFF) != TAG3('UCA'))
            break;

        WaveLength = 0;
        if (UCADecode2(pMemory->pbBuffer, pMemory->dwBufferSize, &lpWaveBuffer, &WaveLength, 44100) < 0)
            break;

        pVorbisPlayer->pStreamPrimary = pStream;
        PlayGameSoundWorker(pVorbisPlayer, lpWaveBuffer, WaveLength);

        UCAFree(lpWaveBuffer);

        return True;

    } while (0);

    return OldPlayGameSound(pVorbisPlayer);
}

#endif /* PlayGameSound */

Bool WINAPI DllMain(HINSTANCE hInstance, ULONG ulReason, LPVOID lpReserved)
{
    if (ulReason == DLL_PROCESS_ATTACH)
    {
        Init();
    }

    return True;
}

LSTATUS WINAPI MyRegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult)
{
    LSTATUS Status;

    Status = RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult);
    if (Status == ERROR_SUCCESS)
        return Status;

#ifdef EDEN
    if (!StrICompareA(lpSubKey, "Software\\minori\\eden"))
#elif defined(EF_FIRST)
    if (!StrICompareA(lpSubKey, "Software\\minori\\ef_first"))
#elif defined(EF_LATTER)
        if (!StrICompareA(lpSubKey, "Software\\minori\\ef_latter"))
#elif defined(EF_FD)
    if (!StrICompareA(lpSubKey, "Software\\minori\\ef_fd"))
#endif
    {
        if (phkResult)
            *phkResult = hInvalidKey;
        return ERROR_SUCCESS;
    }

    return Status;
}

LSTATUS WINAPI MyRegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
    LSTATUS Status;

    if (hKey == hInvalidKey)
    {
        PChar pszValuename;

        pszValuename = (PChar)lpValueName;
        Status = StrLengthA(pszValuename);
        if (Status != 10)
            return ERROR_SUCCESS;

        if (
            (*(PUInt64)pszValuename & 0xDFDFDFDFDFDFDFDF) == TAG8('SERI', 'ALCO') &&
            (*(PUInt16)&pszValuename[8] & 0xDFDF) == TAG2('DE')
            )
        {
#if !defined(EF_FIRST)
            if (lpData)
                *(PUInt32)lpData = '---';
#else
            static Char szSerial[] = "11111-11111-11111-11111";
            CopyStruct(lpData, szSerial, sizeof(szSerial));
#endif
        }

        return ERROR_SUCCESS;
    }

    Status = RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);

    return Status;
}

LSTATUS WINAPI MyRegCloseKey(HKEY hKey)
{
    return hKey == hInvalidKey ? ERROR_SUCCESS : RegCloseKey(hKey);
}

HANDLE WINAPI MyCreateFileA(LPSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
    WChar  szFile[MAX_PATH];
    Int32  Length;

    Length = MultiByteToWideChar(CP_ACP, 0, lpFileName, -1, szFile, countof(szFile));
    --Length;

    do
    {
        if (Length < 5                ||
            szFile[Length - 4] != '.' ||
            (*(PUInt64)&szFile[Length - 3] & 0xFFFFFFDFFFDFFFDF) != TAG3W('PAZ') ||
            IsPathExistsW(szFile))
        {
            break;
        }

        *(PUInt64)&szFile[Length - 4] = TAG4W('_sc.');
        *(PUInt64)&szFile[Length - 0] = TAG3W('paz');
        if (IsPathExistsW(szFile))
            break;

#if defined(EDEN)

        PWChar pszFileName;

        pszFileName = findnamew(szFile);
        if ((*(PUInt32)pszFileName & 0xFFDFFFDF) != TAG2W('PM'))
            break;

        Length -= pszFileName - szFile + 4;
        pszFileName += Length + 8;
        for (Int32 Len = Length; Len != 0; --Len)
        {
            --pszFileName;
            *pszFileName = *(pszFileName - 8);
        }

        *(PUInt64)(pszFileName - 8) = TAG4W('eden');
        *(PUInt64)(pszFileName - 4) = TAG4W('_pm\\');

        pszFileName += Length;
        *(PUInt64)pszFileName = TAG4W('.paz');
        pszFileName[4] = 0;
        if (IsPathExistsW(szFile))
            break;

        *(PUInt64)&pszFileName[0] = TAG4W('_sc.');
        *(PUInt64)&pszFileName[4] = TAG3W('paz');

#endif

    } while (0);

    return CreateFileW(szFile, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

HRESULT WINAPI MySHGetPathFromIDListA(PCIDLIST_ABSOLUTE pidl, LPTSTR pszPath)
{
    GetExecuteDirectoryA(pszPath, MAX_PATH);
    return NO_ERROR;
}

int WINAPI MyMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    return MessageBoxA(hWnd, lpText, lpCaption, uType & ~MB_DEFBUTTON2);
}

ASM Void TrimSpceInCharName()
{
    INLINE_ASM
    {

#if defined(EF_FD) || defined(EDEN) || defined(EF_LATTER)
        lea     ecx, dword ptr [edx+esi*2];
        cmp word ptr [ecx], 4081h;
        je  IS_SPACE;
        cmp word ptr [ecx], 0A1A1h;
        jnz TRIM_END;

IS_SPACE:
        mov word ptr [ecx], 2020h;

TRIM_END:
        test ecx, esp;

#elif defined(EF_FIRST)
        cmp word ptr [ecx+eax*2], 4081h;
        je  IS_SPACE;
        cmp word ptr [ecx+eax*2], 0A1A1h;
        je  IS_SPACE;
        ret;

IS_SPACE:
        mov word ptr [ecx+eax*2], 2020h;
#endif
        ret;
    }
}

LRESULT FASTCALL CompareCharNameEfFirst(SMinoriString *pNameInScript, Int, LPVoid, UInt32 LenInScript, PChar pszNameInANI, UInt32 LenInANI)
{
    SMinoriString NameInAni;

    NameInAni.Length = LenInANI;
    NameInAni.pszString = pszNameInANI;
    return CompareCharName(pNameInScript, 0, &NameInAni);
}

#include "NameTable.h"

#define HANDLE_CHAR_HASH(hash, name, id) \
            case hash: \
                pszName = name; \
                ID = id; \
                break

LRESULT FASTCALL CompareCharName(SMinoriString *pNameInScript, Int, SMinoriString *pNameInANI)
{
    PChar    pszName;
    Int32    ID;
    UInt32   Hash;

//    __asm mov pNameInScript, ecx;
    if (pNameInScript->pszString == NULL || pNameInANI->pszString == NULL)
        return 1;

    switch (HashAPI(pNameInANI->pszString))
    {
        default:
            return 1;

#if defined(EF_FD)
        HANDLE_CHAR_HASH(0x281124FA, "�깬", ID_EFFD_AMEMIYA);
        HANDLE_CHAR_HASH(0xF812ABA0, "����", ID_EFFD_AKARI);
        HANDLE_CHAR_HASH(0x9C124872, "ǧѰ", ID_EFFD_CHIHIRO);
        HANDLE_CHAR_HASH(0x0012E05B, "Ϧ", ID_EFFD_HIMURA);
        HANDLE_CHAR_HASH(0x0011A068, "��", ID_EFFD_HIRO);
        HANDLE_CHAR_HASH(0x00118069, "��", ID_EFFD_KEI);
        HANDLE_CHAR_HASH(0xD8124522, "����", ID_EFFD_KUZE);
        HANDLE_CHAR_HASH(0x7811656C, "����", ID_EFFD_KYOUSUKE);
        HANDLE_CHAR_HASH(0x2C0020DC, "����˿", ID_EFFD_ARISU);
        HANDLE_CHAR_HASH(0x63F020CB, "��ϣ", ID_EFFD_MIZUKI);
        HANDLE_CHAR_HASH(0x8812AB8A, "δ��", ID_EFFD_MIRAI);
        HANDLE_CHAR_HASH(0x85C000B6, "����", ID_EFFD_MIYAKO);
        HANDLE_CHAR_HASH(0x001260E2, "�M", ID_EFFD_NAGI);
        HANDLE_CHAR_HASH(0x1412E852, "ˮ��", ID_EFFD_HAYAMA);
        HANDLE_CHAR_HASH(0x00118CA0, "����", ID_EFFD_RENJI);
        HANDLE_CHAR_HASH(0x001200B9, "ʥ", ID_EFFD_SEI);
        HANDLE_CHAR_HASH(0x7F6000ED, "��", ID_EFFD_SUMIRE);
        HANDLE_CHAR_HASH(0x10118BF0, "����", ID_EFFD_YUUKO);
#elif defined(EDEN)
        HANDLE_CHAR_HASH(0x0012E0BA, "��",     ID_EDEN_RYO);
        HANDLE_CHAR_HASH(0x21702014, "ʫ��",   ID_EDEN_SION);
        HANDLE_CHAR_HASH(0x588020C6, "��ά",   ID_EDEN_RAVI);
        HANDLE_CHAR_HASH(0x2C6020CE, "����", ID_EDEN_ERIKA);
        HANDLE_CHAR_HASH(0x8A802006, "��Ŀ",   ID_EDEN_NATSUME);
        HANDLE_CHAR_HASH(0xB812A477, "��Ҷ",   ID_EDEN_INABA);
        HANDLE_CHAR_HASH(0x781288E8, "��ҹ",   ID_EDEN_MAYA);
#elif defined(EF_FIRST)
        HANDLE_CHAR_HASH(0x9C124872, "ǧѰ", ID_EFF_CHIHIRO);
        HANDLE_CHAR_HASH(0x0012E05B, "Ϧ",   ID_EFF_HIMURA);
        HANDLE_CHAR_HASH(0x0011A068, "��",   ID_EFF_HIRO);
        HANDLE_CHAR_HASH(0x001200F2, "Ȫ",   ID_EFF_IZUMI);
        HANDLE_CHAR_HASH(0x00118069, "��",   ID_EFL_KEI);
        HANDLE_CHAR_HASH(0x7811656C, "����", ID_EFF_KYOUSUKE);
        HANDLE_CHAR_HASH(0x63F020CB, "��ϣ", ID_EFF_MIZUKI);
        HANDLE_CHAR_HASH(0x85C000B6, "����", ID_EFF_MIYAKO);
        HANDLE_CHAR_HASH(0x0012A0EA, "ĸ",   ID_EFF_MOM);
        HANDLE_CHAR_HASH(0x001260E2, "�M",   ID_EFF_NAGI);
        HANDLE_CHAR_HASH(0x94126839, "���", ID_EFF_OOMURA);
        HANDLE_CHAR_HASH(0x10118BF0, "����", ID_EFF_YUUKO);
#elif defined(EF_LATTER)
        HANDLE_CHAR_HASH(0x001100A9, "��",     ID_EFL_AKANE);
        HANDLE_CHAR_HASH(0x281124FA, "�깬",   ID_EFL_AMEMIYA);
        HANDLE_CHAR_HASH(0x9C124872, "ǧѰ",   ID_EFL_CHIHIRO);
        HANDLE_CHAR_HASH(0x0012E05B, "Ϧ",     ID_EFL_HIMURA);
        HANDLE_CHAR_HASH(0x00118069, "��",     ID_EFL_KEI);
        HANDLE_CHAR_HASH(0xD8124522, "����",   ID_EFL_KUZE);
        HANDLE_CHAR_HASH(0x63F020CB, "��ϣ",   ID_EFL_MIZUKI);
        HANDLE_CHAR_HASH(0x8812AB8A, "δ��",   ID_EFL_MIRAI);
        HANDLE_CHAR_HASH(0x001260E2, "�M",     ID_EFL_NAGI);
        HANDLE_CHAR_HASH(0x1412E852, "ˮ��",   ID_EFL_HAYAMA);
        HANDLE_CHAR_HASH(0x00118CA0, "����",   ID_EFL_RENJI);
        HANDLE_CHAR_HASH(0x7F6000ED, "��",     ID_EFL_SUMIRE);
        HANDLE_CHAR_HASH(0x10118BF0, "����",   ID_EFL_YUUKO);
        HANDLE_CHAR_HASH(0x3961806C, "Ů����", ID_EFL_ONNANOKO);
#endif
    }
    SCharNameHashMap *pHash = &NameHash[ID];

    Hash = HashAPI(pNameInScript->pszString);

    return !(Hash == pHash->HashShiftJIS ||
             Hash == pHash->HashJPInGB   ||
             Hash == pHash->HashCN);

    SCharNameMap *pMap = &CharName[ID];

    return !(Hash == HashAPI(pMap->NameShiftJIS) || 
             Hash == HashAPI(pMap->NameJPInGB)   || 
             Hash == HashAPI(pMap->NameCN));
}

DWORD CalcANISize(PByte pbBuffer)
{
    DWORD dwSize, dwEntryCount;
    LPSTR lpName;
    PByte pbData;
    SANIHeader *pHeader;
    SANIEntry  *pEntry;
    int w, h;

    pbData = pbBuffer;
    pHeader = (SANIHeader *)pbData;
    pbData += sizeof(*pHeader);

    dwSize = 0;
    dwEntryCount = pHeader->usEntryCount;

    for (int i = 0; i != dwEntryCount; ++i)
    {
        PByte pbStart = pbData;
        DWORD dwStreamCount;

        lpName = (LPSTR)pbData;
        pbData += StrLengthA(lpName) + 1;
        pEntry = (SANIEntry *)pbData;
        pbData += sizeof(*pEntry);

        dwSize += pbData - pbStart;
        UCIDecode(pbData, INT_MAX, NULL, NULL, &w, &h, NULL);
        dwSize += w * h * 4;

        switch (*(LPDWORD)pbData)
        {
            case '3ICU': dwStreamCount = 1; break;
            case '4ICU': dwStreamCount = 2; break;
            case 'TICU': dwStreamCount = 3; break;
            case 'QICU': dwStreamCount = 4; break;
            default: return 0;
        }
        pbData += 0xC;
        while (dwStreamCount--)
            pbData += *(LPDWORD)pbData + 4;
    }

    return dwSize + 0x100;
}

Bool ConvertUNIToANI(LPVoid lpThis, PChar pszFileName)
{
    PChar lpName;
    UInt32 dwANISize, dwBufferSize, dwEntryCount, dwAllocateType;
    PByte pbBuffer, pbSrc, pbDest;//, pbDecode;
    SMinoriMemory *pMemory;
    SANIHeader *pHeader;
    SANIEntry  *pEntry;

#if defined(EDEN) || defined(EF_FD)
    INLINE_ASM
    {
        mov esi, lpThis;
        lea esi, dword ptr [esi+1A4h];
        lodsd;
        mov pMemory, eax;
        lodsd;
        mov pbBuffer, eax;
        lodsd;
        mov dwBufferSize, eax;
    }
#elif defined(EF_FIRST)
    INLINE_ASM
    {
        mov esi, lpThis;
        lea esi, dword ptr [esi+1198h];
        lodsd;
        lea esi, dword ptr [esi+4];
        mov pMemory, eax;
        lodsd;
        mov pbBuffer, eax;
        lodsd;
        mov dwBufferSize, eax;
    }
#elif defined(EF_LATTER)
    INLINE_ASM
    {
        mov esi, lpThis;
        lea esi, dword ptr [esi+1A0h];
        lodsd;
        mov pMemory, eax;
        lodsd;
        mov pbBuffer, eax;
        lodsd;
        mov dwBufferSize, eax;
    }
#endif

    dwANISize = CalcANISize(pbBuffer);
    if (dwANISize == 0)
        return False;

    if (dwANISize > g_dwConvSize)
    {
        PByte pbReAlloc;
        pbReAlloc = (PByte)HeapReAlloc(CMem::GetGlobalHeap(), HEAP_ZERO_MEMORY, g_pbConvert, dwANISize);
        if (pbReAlloc == NULL)
        {
            return False;
        }
        g_pbConvert = pbReAlloc;
        g_dwConvSize = dwANISize;
    }

    pbSrc  = pbBuffer;
    pbDest = g_pbConvert;

    pHeader = (SANIHeader *)pbSrc;
    pbSrc += sizeof(*pHeader);
    dwEntryCount = pHeader->usEntryCount;
    *(SANIHeader *)pbDest = *pHeader;
    pbDest += sizeof(*pHeader);

    for (int i = 0; i != dwEntryCount; ++i)
    {
        Int32 n;
        UCIInfo uci;

        lpName = (LPSTR)pbSrc;
        pbSrc += StrLengthA(lpName) + 1;
        pEntry = (SANIEntry *)pbSrc;
        pEntry->wBPP = 32;
        pbSrc += sizeof(*pEntry);
        n = pbSrc - (PByte)lpName;
        memcpy(pbDest, lpName, n);
        pbDest += n;
/*
        if (UCIDecode((void *)pbSrc, INT_MAX, (void **)&pbDecode, &stride, &w, &h, &bpp) < 0)
        {
            return False;
        }
*/
        if (UCIDecodeEx(pbSrc, INT_MAX, &uci, False) < 0)
            return False;

        if (uci.BitsPerPixel == 32)
        {
//            PByte p = pbDecode + h * stride;
            Int32 BitmapStride;
            PByte p;

            BitmapStride = uci.Width * 4;
            p = uci.pbBuffer + uci.Height * uci.Stride;
            for (int Height = uci.Height; Height; )
            {
                --Height;
                p -= uci.Stride;
                memcpy(pbDest, p, BitmapStride);
                pbDest += BitmapStride;
            }
        }
        else if (uci.BitsPerPixel == 24)
        {
            PByte p;

            for (int Height = uci.Height; Height; )
            {
                --Height;
                p = uci.pbBuffer + Height * uci.Stride;
                for (int b = 0; b != uci.Width; ++b)
                {
                    *(LPDWORD)pbDest = *(LPDWORD)p | 0xFF000000;
                    p += 3;
                    pbDest += 4;
                }
            }
        }
        else
        {
            UCIFreeEx(&uci);
            return False;
        }

        switch (*(LPDWORD)pbSrc)
        {
            case '3ICU': n = 1; break;
            case '4ICU': n = 2; break;
            case 'TICU': n = 3; break;
            case 'QICU': n = 4; break;
            default: return 0;
        }
        pbSrc += 0xC;
        while (n--)
            pbSrc += *(LPDWORD)pbSrc + 4;

        UCIFreeEx(&uci);
    }

    if (dwANISize > pMemory->dwBufferSize)
    {
        dwAllocateType = pMemory->dwAllocteType;
        INLINE_ASM
        {
            mov  ecx, pMemory;
            call FreeMemory;
            mov  ecx, pMemory;
            push dwAllocateType;
            push dwANISize;
            call AllocateMemory;
        }
#if defined(EDEN) || defined(EF_FD)
        *(PByte *)((PByte)lpThis + 0x1A8) = pMemory->pbBuffer;
        *(LPDWORD)((PByte)lpThis + 0x1AC) = pMemory->dwBufferSize;
#elif defined(EF_FIRST)
        *(PByte *)((PByte)lpThis + 0x11A0) = pMemory->pbBuffer;
        *(LPDWORD)((PByte)lpThis + 0x11A4) = pMemory->dwBufferSize;
#elif defined(EF_LATTER)
        *(PByte *)((PByte)lpThis + 0x1A4) = pMemory->pbBuffer;
        *(LPDWORD)((PByte)lpThis + 0x1A8) = pMemory->dwBufferSize;
#endif
    }

    memcpy(pMemory->pbBuffer, g_pbConvert, dwANISize);

    return True;
}

DWORD WINAPI DynamicReadMaskWorker(HANDLE hFile, DWORD origkey)
{
    LONG   key;
    DWORD  dwRead;
    LARGE_INTEGER Pos;
    SDynamicKey *p;
    static SDynamicKey *pDKey;

    if ((ULONG_PTR)hFile & 0xFFFF0000)
        return origkey;

    p = pDKey;
    if (p == NULL)
    {
        p = pDKey = (SDynamicKey *)HeapAlloc(CMem::GetGlobalHeap(), HEAP_ZERO_MEMORY, 0xFFFF * sizeof(*pDKey));
        if (p == NULL)
            return origkey;
    }

    p = &p[(Int_Ptr)hFile];
    if (p->bInit)
    {
        return p->Key;
    }

    Pos.HighPart = 0;
    Pos.LowPart = SetFilePointer(hFile, 0, &Pos.HighPart, FILE_CURRENT);
    if (Pos.LowPart == -1 && GetLastError() != NO_ERROR)
        return origkey;

    do
    {

        if (SetFilePointer(hFile, 0x23, NULL, FILE_BEGIN) == -1)
            break;
        if (ReadFile(hFile, &key, 1, &dwRead, NULL) == False || dwRead != 1)
            break;

        INLINE_ASM
        {
            movzx eax, key;
            mov ah, al;
            mov edx, eax;
            shl eax, 16;
            or  eax, edx;
            mov origkey, eax;
        }

        p->bInit = True;
        p->Key = origkey;

    } while (0);

    SetFilePointer(hFile, Pos.LowPart, &Pos.HighPart, FILE_BEGIN);

    return origkey;
}

ASM DWORD WINAPI DynamicReadMask()
{
    INLINE_ASM
    {
#ifdef EF_FIRST
        and  eax, 0FFh;
        mov  ah, al;
        mov  edx, eax;
        shl  eax, 16;
        or   eax, edx;
        push eax;
        push dword ptr [ebp+8];
        call DynamicReadMaskWorker;
        mov  dword ptr [ebp+8], esi;
#elif defined(EF_LATTER)
        push dword ptr [edi+1C8h];
        push dword ptr [ebp+8];
        call DynamicReadMaskWorker;
#elif defined(EDEN) || defined(EF_FD)
        push dword ptr [esi+1D4h];
        push dword ptr [ebp+8];
        call DynamicReadMaskWorker;
#endif
        ret;
    }
}

#if defined(SUPPORT_AAC_PLAY)

Bool IsBGMPlaying()
{

    CAudioPlayback *p = ap;
    if (p)
        return p->IsPlaying();
    else
        return False;
}

int WINAPI StopBGMWorker()
{
    CAudioPlayback *p = ap;
    if (p)
    {
        p->Stop();
    }

    return 0;
}

ASM Void WINAPI StopBGMBeforeReturn()
{
    __asm
    {
        push ecx;
        call StopBGMWorker;
        pop  ecx;
        ret;
    }
}

ASM Void WINAPI StopBGMBeforeChange()
{
    __asm
    {
        cmp  dword ptr [esi+0F9Ch], ebx;
        jge  NATIVE_BGM;
        push eax;
        call IsBGMPlaying;
        dec  eax;
        jnz  NOT_PLAYING;
        lea  eax, dword ptr [ebp-48h];
        push dword ptr [eax];
        push dword ptr [eax+10h];
        call dword ptr [lstrcmpiA];
        test eax, eax;
        je   SAME_BGM;
        call StopBGMWorker;
        dec  eax;
NOT_PLAYING:
        pop  eax;

NATIVE_BGM:
        ret;
SAME_BGM:
        add  esp, 8;
        mov  eax, 429A0Eh;
        jmp  eax;
    }
}

ASM Void WINAPI StopBGMBeforeConfig()
{
    __asm
    {
        lea  esi, dword ptr [ecx+0F9Ch];
        mov  eax, dword ptr [esi];
        test eax, eax;
        jge  NATIVE_BGM;
        call StopBGMWorker;

NATIVE_BGM:
        ret;
    }
}

#endif /* SUPPORT_AAC_PLAY */

#if defined(SUPPORT_UCA_PLAY)

ASM Void WINAPI AutoModeWaitForVoice()
{
    __asm
    {
        xor  eax, eax;
#if defined(EDEN)
        cmp  dword ptr [esi+0F98h], eax;
#elif defined(EF_FIRST)
        cmp  dword ptr [ebp+0DB8h], eax;
#elif defined(EF_LATTER)
        cmp  dword ptr [esi+0DB8h], eax;
#endif
        jge  ORIG_VOICE;
        cmp  g_bPlayingVoice, eax;
        jnz  ORIG_VOICE;
        dec  eax;

ORIG_VOICE:
        ret;
    }
}

ASM Void WINAPI FixWaitForVoiceStop()
{
    __asm
    {
        mov eax, TRUE;
        cmp g_bPlayingVoice, eax;
        je  NOW_PLAYING;

#if defined(EDEN)
        cmp dword ptr [esi+0F98h], ebx;
#elif defined(EF_FIRST)
        mov eax, dword ptr [ebp+0DB8h];
#elif defined(EF_LATTER)
        cmp dword ptr [esi+0DB8h], ebx
#endif

NOW_PLAYING:
        ret;
    }
}

Bool STDCALL MySetEvent(HANDLE hEvent)
{
    return SetEvent(hEvent);
}

ASM Void WINAPI StopVoiceBeforeNext()
{
    __asm
    {
        cmp  g_bPlayingVoice, TRUE;
        jnz  NOT_PLAYING;
        push g_hEventNotify;
//        call dword ptr [SetEvent];
        call MySetEvent;

NOT_PLAYING:
#if defined(EDEN)
        mov  eax, dword ptr [esi+0F98h];
#elif defined(EF_FIRST)
        mov  eax, dword ptr [esi+0DB8h];
#elif defined(EF_LATTER)
        lea  edi, dword ptr [esi+0DB8h];
        mov  eax, dword ptr [edi];
#endif
        ret;
    }
}
#define StopVoiceBeforeReturn StopVoiceBeforeNext

DWORD WINAPI PlayVoiceThread(LPVOID lpParam)
{
    PByte   pbWave;
    DWORD   dwSize;
    HANDLE  hEvent;
    HRESULT hResult;
    SWaveHeader *pHeader;

    hEvent = g_hEventNotify;
    SetEvent(hEvent);
    EnterCriticalSection(&g_csPlayVoice);
    ResetEvent(hEvent);

    LPVOID               lpLockBuffer;
    WAVEFORMATEX         wfx;
    DSBUFFERDESC         DSBufferDesc;
    DSBPOSITIONNOTIFY    DSPosNotify;
    IDirectSoundNotify  *lpDSNotify;
    IDirectSoundBuffer  *lpDSBuffer;
    IDirectSound *lpDS;

#if defined(EDEN) || defined(EF_FD)
    #error use new hook!
#endif

#if defined(EDEN)
    lpDS = *(IDirectSound **)0x4D2F4C;
#elif defined(EF_FD)
    lpDS = *(IDirectSound **)0x4D3064;
#elif defined(EF_FIRST)
    lpDS = *(IDirectSound **)0x5300D4;
#elif defined(EF_LATTER)
    lpDS = *(IDirectSound **)0x50770C;
#endif

    pbWave  = (PByte)lpParam;
    dwSize  = *(LPDWORD)pbWave;
    pHeader = (SWaveHeader *)pbWave;

    wfx.cbSize = sizeof(wfx);
    wfx.nAvgBytesPerSec = pHeader->dwAvgBytesPerSec;
    wfx.nBlockAlign     = pHeader->wBlockAlign;
    wfx.nChannels       = pHeader->wChannels;
    wfx.nSamplesPerSec  = pHeader->dwSamplesPerSec;
    wfx.wBitsPerSample  = pHeader->wBitsPerSample;
    wfx.wFormatTag      = pHeader->wFormatTag;

    dwSize = dwSize - sizeof(*pHeader);
    ZeroMemory(&DSBufferDesc, sizeof(DSBufferDesc));
    DSBufferDesc.dwSize = sizeof(DSBufferDesc);
    DSBufferDesc.dwFlags = DSBCAPS_GLOBALFOCUS|DSBCAPS_CTRLFREQUENCY|DSBCAPS_CTRLVOLUME|DSBCAPS_CTRLPOSITIONNOTIFY;
    DSBufferDesc.dwBufferBytes = dwSize;
    DSBufferDesc.lpwfxFormat = &wfx;

    hResult = lpDS->CreateSoundBuffer(&DSBufferDesc, &lpDSBuffer, NULL);
    if (FAILED(hResult))
    {
        UCAFree(pbWave);
        LeaveCriticalSection(&g_csPlayVoice);
        return 0;
    }

    do
    {
        DSPosNotify.dwOffset = DSBPN_OFFSETSTOP;
        DSPosNotify.hEventNotify = hEvent;
        hResult = lpDSBuffer->QueryInterface(IID_IDirectSoundNotify, (LPVOID *)&lpDSNotify);
        if (FAILED(hResult))
        {
            break;
        }

        hResult = lpDSNotify->SetNotificationPositions(1, &DSPosNotify);
        lpDSNotify->Release();
        if (FAILED(hResult))
        {
            break;
        }

        hResult = lpDSBuffer->Lock(0, 0, &lpLockBuffer, &dwSize, NULL, NULL, DSBLOCK_ENTIREBUFFER);
        if (FAILED(hResult))
        {
            break;
        }

        memcpy(lpLockBuffer, pbWave + sizeof(*pHeader), DSBufferDesc.dwBufferBytes);
        hResult = lpDSBuffer->Unlock(lpLockBuffer, dwSize, NULL, 0);
        if (FAILED(hResult))
        {
            break;
        }

#ifdef EDEN
        lpDSBuffer->SetVolume(GetVolume(*(LPLONG)0x4D4268));
#elif defined(EF_FIRST)
        lpDSBuffer->SetVolume(GetVolume(*(LPLONG)0x53124C));
#elif defined(EF_LATTER)
        lpDSBuffer->SetVolume(GetVolume(*(LPLONG)0x50897C));
#endif
        lpDSBuffer->SetCurrentPosition(0);
        lpDSBuffer->Play(0, 0, 0);
        g_bPlayingVoice = True;
        WaitForSingleObjectEx(hEvent, INFINITE, False);
        ResetEvent(hEvent);
        lpDSBuffer->Stop();
        g_bPlayingVoice = False;
    } while (0);

    lpDSBuffer->Release();
    UCAFree(pbWave);
    LeaveCriticalSection(&g_csPlayVoice);

    return 0;
}

Bool WINAPI PlayVoice(LPVOID lpThis)
{
    PByte pbBuffer, pbWave;
    DWORD dwSrcLength, dwLength;

#if defined(EDEN) || defined(EF_FD)
    #error use new hook!
    pbBuffer = *(PByte *)((PByte)lpThis + 0x1A8);
#elif defined(EF_FIRST)
    pbBuffer = *(PByte *)((PByte)lpThis + 0x11A0);
#elif defined(EF_LATTER)
    pbBuffer = *(PByte *)((PByte)lpThis + 0x1A4);
#endif

    if (pbBuffer == NULL)
        return False;

#ifdef EDEN
    dwSrcLength = *(LPDWORD)((PByte)lpThis + 0x1AC);
#elif defined(EF_FIRST)
    dwSrcLength = *(LPDWORD)((PByte)lpThis + 0x11A4);
#elif defined(EF_LATTER)
    dwSrcLength = *(LPDWORD)((PByte)lpThis + 0x1A8);
#endif

    if (dwSrcLength == 0)
        return False;

    dwLength = -1;
    if (UCADecode2(pbBuffer, dwSrcLength, (LPVOID *)&pbWave, (int *)&dwLength, 48000) < 0)
        return False;

    *(LPDWORD)pbWave = dwLength;
    CreateThread(NULL, 0, PlayVoiceThread, pbWave, 0, NULL);

    return True;
}

#endif /* SUPPORT_UCA_PLAY */
/*
#define GameReadFile(lpThis, pszFileName) \
    ((bool (FASTCALL *)(LPVoid, Int, PCChar))lpfn_GameReadFile)(lpThis, 0, pszFileName)
*/

#define GameReadFile(lpThis, pszFile) \
            (Bool)OldReadFileFromPaz(lpThis, 0, pszFile)

ASM bool FASTCALL OldReadFileFromPaz(LPVoid lpThis, Int, LPSTR lpFileName)
{
    // 7 bytes
    ASM_DUMMY(7);
    ASM_UNIQUE();
}

Bool FASTCALL ReadFileFromPaz(LPVoid lpThis, Int, LPSTR lpFileName)
{
    Bool   r;
    LPSTR lpExt;
    Char  szFile[MAX_PATH];

//    __asm mov lpThis, ecx;
    if (GameReadFile(lpThis, lpFileName))
        return True;

//    lpExt = PathFindExtensionA(lpFileName);
    lpExt = findexta(lpFileName);
    if (lpExt == lpFileName)
    {
        return False;
    }
    else if (*lpExt == 0)
    {
        DWORD dwLength = lpExt - lpFileName;
        memcpy(szFile, lpFileName, dwLength);
        *(LPDWORD)(szFile + dwLength) = TAG4('.uca');
        szFile[dwLength + 4] = 0;
        lpFileName = szFile;

        r = GameReadFile(lpThis, lpFileName);
#if !defined(SUPPORT_UCA_PLAY)
        return r;
#else
        if (r)
        {
            PlayVoice(lpThis);
        }
#endif
    }
    else
    {
        DWORD dwExtension = *(LPDWORD)(lpExt + 1) & 0xFFDFDFDF;

        switch (dwExtension)
        {
            case TAG3('PNG'):
                *(LPDWORD)(lpExt + 1) = TAG3('uci');
                return GameReadFile(lpThis, lpFileName);
                break;

            case TAG3('ANI'):
                *(LPDWORD)(lpExt + 1) = TAG3('uni');
                if (GameReadFile(lpThis, lpFileName))
                {
                    return ConvertUNIToANI(lpThis, lpFileName);
                }
                break;
#if defined(SUPPORT_AAC_DECODE)
            case TAG3('OGG'):
                *(LPDWORD)(lpExt + 1) = TAG3('m4a');
                return GameReadFile(lpThis, lpFileName);

                CAudioPlayback *p = NULL;
                if (p == NULL)
                    break;
                if (GameReadFile(lpThis, lpFileName))
                {
                    PByte pbBuffer;
                    Large_Integer li;

                    pbBuffer = *(PByte *)((PByte)lpThis + 0x1A8);
                    li.LowPart  = *(LPDWORD)((PByte)lpThis + 0x1AC);
                    li.HighPart = 0;
                    if (p->Open(pbBuffer, True, &li) == False)
                        break;
                    p->SetVolume(*(PLong)0x4D4264);
                    p->Play();
                }
            break;
#endif
        }
    }

    return False;
}

ASM LPVOID WINAPI AllocateImage(LPVOID lpThis, DWORD dwWidth, DWORD dwHeight)
{
    INLINE_ASM
    {
        mov    ecx, dword ptr [esp+4];
        push   32;
        push   dword ptr [esp+10h];
        push   dword ptr [esp+10h];
        call   AllocateMemoryForImage;
        and    eax, 1;
        mov    ecx, dword ptr [esp+4];
        cmovne eax, dword ptr [ecx+64h];
        ret    0Ch;
    }
}

ASM bool CDECL OldDecodePng(LPVOID lpThis, LPVOID lpThis2, DWORD dwVal)
{
    ASM_DUMMY(5);
    ASM_UNIQUE();
}

Bool CDECL DecodePng(LPVOID lpThis, LPVOID lpThis2, DWORD dwVal)
{
    DWORD dwSize;
    PByte pbBuffer, pbSrc, pbDest;
    UCIInfo uci;

#if defined(EDEN) || defined(EF_FD)
    __asm
    {
        mov esi, lpThis2;
        lea esi, dword ptr [esi+1A8h];
        lodsd;
        mov pbBuffer, eax;
        lodsd;
        mov dwSize, eax;
    }
#elif defined(EF_FIRST)
    __asm
    {
        mov esi, lpThis2;
        lea esi, dword ptr [esi+11A0h];
        lodsd;
        mov pbBuffer, eax;
        lodsd;
        mov dwSize, eax;
    }
#elif defined(EF_LATTER)
    __asm
    {
        mov esi, lpThis2;
        lea esi, dword ptr [esi+1A4h];
        lodsd;
        mov pbBuffer, eax;
        lodsd;
        mov dwSize, eax;
    }
#endif

    if (pbBuffer == NULL || (*(LPDWORD)pbBuffer & 0x00FFFFFF) != TAG3('UCI'))
        return OldDecodePng(lpThis, lpThis2, dwVal);

    if (UCIDecodeEx(pbBuffer, dwSize, &uci, False) < 0)
        return False;

    pbBuffer = (PByte)AllocateImage(lpThis, uci.Width, uci.Height);
    if (pbBuffer == NULL)
    {
        UCIFreeEx(&uci);
        return False;
    }

    pbSrc  = uci.pbBuffer;
    pbDest = pbBuffer;
    if (uci.BitsPerPixel == 32)
    {
        int n = uci.Width * 4;
        for (int i = 0; i != uci.Height; ++i)
        {
            memcpy(pbDest, pbSrc, n);
            pbSrc += uci.Stride;
            pbDest += n;
        }
    }
    else if (uci.BitsPerPixel == 24)
    {
        for (int i = 0; i != uci.Height; ++i)
        {
            PByte pbData = pbSrc;
            for (int j = 0; j != uci.Width; ++j)
            {
                *(LPDWORD)pbDest = *(LPDWORD)pbData | 0xFF000000;
                pbData += 3;
                pbDest += 4;
            }
            pbSrc += uci.Stride;
        }
    }

    UCIFreeEx(&uci);

    return True;
}

Bool _IsShiftJIS(UInt uChar)
{
#ifdef EDEN
    static WCHAR spec[] =
    {
        '�', '�', '�', '�', '�', '�', '�', '�', '��', '�',
        '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
        '�', '�', '�', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��',
    };
#elif defined(EF_FIRST)
    static WCHAR spec[] =
    {
        '�M', '�O', '�V', '�e', '�g', '�h', '�i', '�m', '�r', '��',
        '��', '��', '��', '�', '�', '�', '�', '�', '�', '�',
        '�', '�', '�', '�', '�', '�', '�', '�', '�', '��',
        '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
        '�', '�', '�', '�', '�', '�', '�', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��',
    };
#elif defined(EF_LATTER)
    static WCHAR spec[] =
    {
        '�M', '�m', '�~', '��', '��', '�', '�', '�', '�', '�',
        '�', '�', '�', '�', '�', '�', '�', '�', '��', '�',
        '�', '�', '�', '�', '�', '�', '�', '�', '�', '��',
        '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
        '�', '�', '�', '�', '�', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��',
    };
#elif defined(EF_FD)
    static WCHAR spec[] =
    {
        '�A', '�D', '�L', '�M', '�Q', '�S', '�T', '�W', '�Z', '�]',
        '�]', '�^', '�^', '�_', '�e', '�e', '�g', '�h', '�i', '�i',
        '�n', '�o', '�r', '�u', '�x', '�y', '�}', '��', '�', '��',
        '��', '�', '��', '�', '��', '�', '��', '��', '��', '��',
        '�', '�', '�', '�', '�', '��', '�', '�', '�', '�',
        '�', '�', '�', '��', '�', '�', '�', '�', '�', '�',
        '��', '�', '�', '��', '�', '�', '�', '�', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
        '��', '��',
    };
#endif

    for (UInt i = 0, j = uChar; i != countof(spec); ++i)
        if ((WCHAR)j == spec[i])
            return False;

    return IsShiftJISChar(uChar);
}

ASM Void WINAPI FixGlyphAlpha()
{
    INLINE_ASM
    {
        cmp ecx, 0A0000000h;
        jnb _ENOUGH_;
        lea ecx, dword ptr [ecx+040000000h];
_ENOUGH_:
        or ecx, dword ptr [esi+0C8h];
        ret;
    }
}

DWORD
WINAPI
MyGetGlyphOutlineA(
    HDC hDC,
    UINT uChar,
    UINT uFormat,
    LPGLYPHMETRICS lpgm,
    DWORD cbBuffer,
    LPVOID lpvBuffer,
    CONST MAT2 *lpmat2
)
{
    Char cHighByte;
    UInt32 CodePage, wChar;
    HFONT hFont = NULL;
    DWORD dwIndex;
    TEXTMETRICW tm;

    do
    {
        uChar &= 0xFFFF;
        cHighByte = HIBYTE(uChar);
        CodePage = CP_GB2312;

        if (cHighByte < 0)
        {
            if (_IsShiftJIS(uChar))
            {
                GetTextMetricsW(hDC, &tm);
                dwIndex = tm.tmHeight > 10;
                CodePage = CP_SHIFTJIS;
                hFont = g_hFontJP[dwIndex];
                if (hFont)
                    hFont = (HFONT)SelectObject(hDC, hFont);
                uChar = SWAPCHAR(uChar);
            }
            else
            {
                switch (uChar)
                {
                    default:
                        uChar = SWAPCHAR(uChar);
                        goto FORCE_CONVERT;

                    case (UInt16)'��':
//                       uChar = (UInt16)'��';
                        wChar = 0x266A;
                        break;
                }

                GetTextMetricsW(hDC, &tm);
                dwIndex = tm.tmHeight > 10;
                hFont = g_hFontJP[dwIndex];
                if (hFont)
                    hFont = (HFONT)SelectObject(hDC, hFont);

                break;
            }
        }

FORCE_CONVERT:

        MultiByteToWideChar(CodePage, 0, (LPCSTR)&uChar, 2, (LPWSTR)&wChar, 1);

    } while (0);

    CodePage = GetGlyphOutlineW(hDC, wChar, uFormat, lpgm, cbBuffer, lpvBuffer, lpmat2);

    if (hFont)
    {
        SelectObject(hDC, hFont);
    }

    return CodePage;
}

ASM Void WINAPI RederChar(int x, int y, int, int, PByte pbBuffer, Bool)
{
    __asm
    {
        mov  eax, dword ptr [esi+0D0h];
        sub  eax, dword ptr [esi+0CCh];
        sub  dword ptr [esp+8], eax;
        mov  eax, dword ptr [esi+0C0h];
        add  dword ptr [esp+4], eax;
        mov  edi, dword ptr [esi+0C8h];
#if defined(EF_FIRST)
        mov  eax, 44F800h;
#elif defined(EF_LATTER)
        mov  eax, 43B7B8h;
#endif
        jmp  eax;
    }
}

HFONT
WINAPI
MyCreateFontA(
    int cHeight,
    int cWidth,
    int cEscapement,
    int cOrientation,
    int cWeight,
    DWORD bItalic,
    DWORD bUnderline,
    DWORD bStrikeOut,
    DWORD iCharSet,
    DWORD iOutPrecision,
    DWORD iClipPrecision,
    DWORD iQuality,
    DWORD iPitchAndFamily,
    LPCSTR pszFaceName
)
{
    HFONT hFont;
    DWORD dwIndex, dwQulity = g_dwQuality;
    LOGFONTW lf;
    static WChar szDefJPFace[LF_FACESIZE] = L"�ͣ� �Х����å�";

    lf.lfHeight         = cHeight;
    lf.lfWidth          = cWidth;
    lf.lfEscapement     = cEscapement;
    lf.lfOrientation    = cOrientation;
    lf.lfWeight         = cWeight;
    lf.lfItalic         = (Byte)bItalic;
    lf.lfUnderline      = (Byte)bUnderline;
    lf.lfStrikeOut      = (Byte)bStrikeOut;
    lf.lfCharSet        = SHIFTJIS_CHARSET;
    lf.lfQuality        = (Byte)dwQulity;
    lf.lfPitchAndFamily = FIXED_PITCH;
    CopyStruct(lf.lfFaceName, szDefJPFace, sizeof(szDefJPFace));

    dwIndex = cHeight > 10;
    hFont = g_hFontJP[dwIndex];
    if (hFont)
        DeleteObject(hFont);

    g_hFontJP[dwIndex] = CreateFontIndirectW(&lf);

    lf.lfCharSet = GB2312_CHARSET;
    MultiByteToWideChar(CP_ACP, 0, pszFaceName, StrLengthA(pszFaceName) + 1, lf.lfFaceName, countof(lf.lfFaceName));

    return CreateFontIndirectW(&lf);
}

int WINAPI MyShowCursor(BOOL bShow)
{
    return True;
}

LANGID WINAPI MyGetSystemDefaultLangID()
{
    return 0x411;
}

Void WINAPI MyGetLocalTime(LPSYSTEMTIME lpSystemTime)
{
    memset(lpSystemTime, 0x7F, sizeof(*lpSystemTime));
}

DWORD WINAPI MyGetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation)
{
//    DWORD r = GetTimeZoneInformation(lpTimeZoneInformation);

    lpTimeZoneInformation->Bias = -9 * 60;
    return TIME_ZONE_ID_STANDARD;
//    return r;
}

Bool WINAPI MyPeekMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg)
{
    Bool bResult = PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
    static Bool bFree = False;

    switch (lpMsg->message)
    {
#if defined(EDEN)
        case WM_KEYDOWN:
            switch (lpMsg->wParam)
            {
                DWORD dwAddress;

                case VK_F5:
                case VK_F6:
                {
                    SPatch p = { lpMsg->wParam == VK_F6 ? 0xA3 : 0x00, 0x01, 0x08CA8 };
#ifndef MY_DEBUG
                    PatchMemoryNoVP(&p, 1, 0, 0, GetModuleHandleW(0));
#else
                    PatchMemory(&p, 1, 0, 0, GetModuleHandleW(0));
#endif
                }
                break;

                case VK_F2:
                    dwAddress = 0x27282; // �Ի�
                    goto _START_;
                case VK_F3:
                    dwAddress = 0x28082; // ��������
                    goto _START_;
                case VK_F4:
                    dwAddress = 0x2824E; // ����Ի�
                {
    _START_:
                    COLORREF cr;
                    CHOOSECOLORW ccr;

                    dwAddress += (DWORD)GetModuleHandleW(0);
                    memset(&ccr, 0, sizeof(ccr));
                    ccr.lStructSize = sizeof(ccr);
                    ccr.hwndOwner = lpMsg->hwnd;
                    ccr.Flags = CC_FULLOPEN|CC_ANYCOLOR|CC_RGBINIT;
                    ccr.lpCustColors = &cr;
                    ccr.rgbResult = *(LPDWORD)dwAddress;
                    if (ChooseColorW(&ccr))
                    {
                        SPatch p = { ccr.rgbResult, 4, dwAddress };
#ifndef MY_DEBUG
                        PatchMemoryNoVP(&p, 1, 0, 0, 0);
#else
                        PatchMemory(&p, 1, 0, 0, 0);
#endif
                    }
                }
            }
            break;
#elif defined(EF_FIRST1)
            case VK_F2:
                if (GetAsyncKeyState(VK_SHIFT) < 0)
                    dwAddress = 0x36F65;
                else
                    dwAddress = 0x36F5C; // �Ի�
                goto _START_;
            case VK_F3:
                dwAddress = 0x37FF5; // ��������
                goto _START_;
            case VK_F4:
                dwAddress = 0x38203; // ����Ի�
#endif

        case WM_QUIT:
            if (bFree == False)
            {
                bFree = True;
#if defined(SUPPORT_UCA_PLAY)
                DeleteCriticalSection(&g_csPlayVoice);
                CloseHandle(g_hEventNotify);
#endif
                if (g_hFontJP[0] != NULL)
                    DeleteObject(g_hFontJP[0]);
                if (g_hFontJP[1] != NULL)
                    DeleteObject(g_hFontJP[1]);

                HeapFree(CMem::GetGlobalHeap(), 0, g_pbConvert);
            }
            break;
    }

    return bResult;
}

EXTC FARPROC WINAPI MyGetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
    FARPROC FarProc;
    static HMODULE hModuleKernel32;

    if (hModuleKernel32 == NULL)
    {
#if !defined(MY_DEBUG)
        Init();
#endif
        hModuleKernel32 = GetKernel32Handle();
    }

    if ((int)lpProcName > 0xFFFF)
    {
        switch (HashAPI(lpProcName))
        {
            case 0xB231F005:
#if !defined(EF_FIRST) && !defined(EF_LATTER)
                if (hModule == hModuleKernel32)
#endif
                    return (FARPROC)MyCreateFileA; break;
            case 0xD424F9FF: return (FARPROC)MyGetProcAddress;
            case 0xFFADBAB0: return (FARPROC)MyPeekMessageA;
            case 0x2EE713B9: return (FARPROC)MyMessageBoxA;
            case 0xBA33D305: return (FARPROC)MyCreateFontA;
            case 0xA1A757F2: return (FARPROC)MyGetGlyphOutlineA;
            case 0x13964DCC: return (FARPROC)MyRegOpenKeyExA;
            case 0xA47D461B: return (FARPROC)MyRegQueryValueExA;
            case 0x3F87F46C: return (FARPROC)MyRegCloseKey;
            case 0x334C7BFC: return (FARPROC)MySHGetPathFromIDListA;
            case 0x3B9136E1: return (FARPROC)MyGetTimeZoneInformation;
            case 0xD4768731: return (FARPROC)MyGetLocalTime;
#if defined(EF_FIRST)
            case 0xB92071F6: return (FARPROC)MyShowCursor;
#elif defined(EF_LATTER)
            case 0xB5AA70BD: return 0;  // (FARPROC)MyGetSystemDefaultLangID;
#endif
        }
    }

    FarProc = GetProcAddress(hModule, lpProcName);
    return FarProc ? FarProc : GetProcAddress(hModuleKernel32, lpProcName);
}

Void Init()
{
    DWORD i;
    HANDLE hFind;
    WIN32_FIND_DATAW fd;
    static WChar szDefFace[] = L"����";

    CMem::CreateGlobalHeap();

//    g_bSerialNumCorrect = True;
    g_bDynamicReadMask = False;
    g_pbConvert  = (PByte)HeapAlloc(CMem::GetGlobalHeap(), 0, g_dwConvSize);

#if defined(SUPPORT_UCA_PLAY)
    g_hEventNotify = CreateEventW(NULL, True, False, NULL);
//    InitializeCriticalSection(&g_csPlayVoice);
    InitializeCriticalSectionAndSpinCount(&g_csPlayVoice, 4000);
#endif

    if (LoByte(GetVersion()) >= 5)
        g_dwQuality = CLEARTYPE_NATURAL_QUALITY;
    else
        g_dwQuality = ANTIALIASED_QUALITY;

    i = GetModuleFileNameW(NULL, fd.cFileName, MAX_PATH);
    while (fd.cFileName[--i] != '\\');
    fd.cFileName[i] = 0;
    SetCurrentDirectoryW(fd.cFileName);
    hFind = FindFirstFileW(L"*.tt?", &fd);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            AddFontResourceExW(fd.cFileName, FR_PRIVATE, 0);
        } while (FindNextFileW(hFind, &fd));
        FindClose(hFind);
    }

    WideCharToMultiByte(CP_ACP, 0, szDefFace, countof(szDefFace) + 1, g_szDefFaceName, sizeof(g_szDefFaceName), NULL, NULL);

    vorbis_func.ov_open_callbacks = old_ov_open_callbacks;
    vorbis_func.ov_read           = old_ov_read;
    vorbis_func.ov_pcm_seek       = old_ov_pcm_seek;
    vorbis_func.ov_pcm_seek_lap   = old_ov_pcm_seek_lap;
    vorbis_func.ov_clear          = old_ov_clear;

#if defined(EF_FD)

    INTEL_STATIC SFuncPatch f[] =
    {
        { JUMP, 0x3FCC1, DecodePng,       0x00, OldDecodePng },
        { JUMP, 0x3D1B2, ReadFileFromPaz, 0x00, OldReadFileFromPaz },

        { CALL, 0x3CC70, DynamicReadMask,      0x01 },
        { CALL, 0x4ED19, TrimSpceInCharName,   0x01 },
        { CALL, 0x252EB, CompareCharName,      0x00 },

        // audio
        { CALL, 0x2171A, my_ov_open_callbacks, 0x00 },
        { CALL, 0x2181B, my_ov_read,           0x00 },
        { CALL, 0x218B0, my_ov_pcm_seek,       0x00 },
        { CALL, 0x218BB, my_ov_pcm_seek_lap,   0x00 },
        { CALL, 0x21753, my_ov_clear,          0x00 },
        { CALL, 0x21C98, GetVorbisInfo,        0x00 },
    };

    INTEL_STATIC SPatch p[] =
    {
        // crack
        { 0xEB,          0x01,   0x13B09 },
        { 0xEB,          0x01,   0x155AD },
        { 0xB8,          0x01,   0x13B11 },
        { 0xEB,          0x01,   0x17BF0 }, // ȥ�������߳�
        { 0x00,          0x01,   0x013BD }, // InstallKeyCodeУ��

        // misc
        { 0x33,          0x01,   0x1B0D3 }, // save folder
        { szSaveFolder,  0x04,   0x16051 }, // \\save_folder\\eden
        { 0xC08B,        0x02,   0x0EC87 }, // �浵ͨ��
        { 0xEB,          0x01,   0x48C8E }, // �浵ͨ��
        { 0x33,          0x01,   0x145AA }, // "ȫ�����ı�ֱ���"ʱWA_INACTIVE���ָ�����
        { 0xFE,          0x01,   0x38F66 }, // ȫ�����ı�ֱ��ʲ���������ǰ��

        // font
        { GB2312_CHARSET, 0x01,   0x38B73 }, // EnumFontFamiliesExAb char set
        { 0xEB,           0x01,   0x38BEB }, // ����� LOGFONT::lfStrikeOut
        { FW_NORMAL,      0x04,   0x46FD0 }, // fnWeight
        { szFont,         0x04,   0x304BC }, // Ĭ������
        { szFont,         0x04,   0x10847 }, // Ĭ������
        { szFont,         0x04,   0x1649B }, // Ĭ������
        { szFont,         0x04,   0x38C84 }, // Ĭ������
        { szFont,         0x04,   0x46FC1 }, // Ĭ������
        { 0xA1AA,         0x02,   0x470FF }, // ���ۺ� ��
        { 0xA1AA,         0x02,   0x1CC0D }, // ���ۺ� ��

        // bound
        { 0xEB,            0x01,   0x1CE58 }, // �ƻ��ű��߽���
        { 0xEB,            0x01,   0x0FBA6 }, // �ƻ��߽���
        { 0xEB,            0x01,   0x1ADF3 },
        { 0xEB,            0x01,   0x1CD7A },
        { 0xEB,            0x01,   0x1CF62 },
        { 0xEB,            0x01,   0x1D1D3 },
        { 0xEB,            0x01,   0x2A36F },
        { 0xEB,            0x01,   0x3CECE },
        { 0xEB,            0x01,   0x485CA },
        { 0xEB,            0x01,   0x596F0 },
        { 0xEB,            0x01,   0x599E5 },
        { 0xEB,            0x01,   0x3D1F2 }, // �ƻ��ļ����߽���

//        { (DWORD)ReadFileFromPaz, 0x04, 0x9D690 }, // ��ȡ�ļ�
    };

#elif defined(EDEN)

    INTEL_STATIC SFuncPatch f[] =
    {
        { JUMP, 0x40FCC, DecodePng,       0x00, OldDecodePng },
        { JUMP, 0x3E01C, ReadFileFromPaz, 0x00, OldReadFileFromPaz },

        { CALL, 0x3DAD2, DynamicReadMask,      0x01 },
        { CALL, 0x51903, TrimSpceInCharName,   0x01 },
        { CALL, 0x20E43, CompareCharName,      0x00 },

        // audio
        { JUMP, 0x8F380, my_ov_open_callbacks, 0x00, old_ov_open_callbacks },
        { JUMP, 0x90F80, my_ov_read,           0x01, old_ov_read },
        { JUMP, 0x908D0, my_ov_pcm_seek,       0x03, old_ov_pcm_seek },
        { JUMP, 0x91790, my_ov_pcm_seek_lap,   0x03, old_ov_pcm_seek_lap },
        { JUMP, 0x8F280, my_ov_clear,          0x00, old_ov_clear },
        { JUMP, 0x1D434, GetVorbisInfo,        0x04, OldGetVorbisInfo },
/*
        { CALL, 0x1C981, my_ov_open_callbacks, 0x00 },
        { CALL, 0x1CA76, my_ov_read,           0x00 },
        { CALL, 0x1CB01, my_ov_pcm_seek,       0x00 },
        { CALL, 0x1CB0C, my_ov_pcm_seek_lap,   0x00 },
        { CALL, 0x1C9BA, my_ov_clear,          0x00 },
        { CALL, 0x1CE9C, GetVorbisInfo,        0x00 },

        // voice
        { CALL, 0x28DBE, StopVoiceBeforeNext,   0x01 },    // �����¾�Ի�ǰֹͣ��������
        { CALL, 0x25B2D, StopVoiceBeforeReturn, 0x01 },    // �������˵�ǰֹͣ����
        { CALL, 0x27106, FixWaitForVoiceStop,   0x01 },    // ����ʹ�þ���������ʱ/v��Ч
        { CALL, 0x28963, AutoModeWaitForVoice,  0x02 },    // �Զ�����ģʽ�ȴ���������

        // bgm
        { CALL, 0x2983A, StopBGMBeforeChange,  0x01 },    // �л�ǰֹͣBGM
        { CALL, 0x1C30E, StopBGMBeforeReturn,  0x00 },    // �������˵�ǰֹͣBGM
        { CALL, 0x28D55, StopBGMBeforeConfig,  0x01 },    // ��������ǰֹͣBGM
*/
        // char
        { CALL, 0x385A5, FixGlyphAlpha,        0x01 },    // ����alphaֵ
    };

    INTEL_STATIC SPatch p[] =
    {
        // crack
        { 0xEB,          0x01,   0x13BC1 },
        { 0xB8,          0x01,   0x13D5C },
        { 0xEB,          0x01,   0x1811F },  // ȥ�������߳�
        { 0x00,          0x01,   0x06C0D }, // InstallKeyCodeУ��

        // misc
        { 0xC08B,        0x02,   0x0F065 }, // �浵ͨ��
        { 0xEB,          0x01,   0x5CD1D }, // �浵ͨ��
        { 0x33,          0x01,   0x14A13 }, // "ȫ�����ı�ֱ���"ʱWA_INACTIVE���ָ�����
        { 0xFE,          0x01,   0x39C50 }, // ȫ�����ı�ֱ��ʲ���������ǰ��
        { szMutex,       0x04,   0x1393E }, // ͬʱ���������������汾

        // font
        { FW_NORMAL,     0x04,   0x5CFC8 }, // fnWeight
        { GB2312_CHARSET,0x01,   0x39862 }, // EnumFontFamiliesExAb char set
        { 0xEB,          0x01,   0x398DA }, // ����� LOGFONT::lfStrikeOut
        { 0x33,          0x01,   0x1E7DD }, // save folder
        { szSaveFolder,  0x04,   0x1656C }, // \\save_folder\\eden
        { szFont,        0x04,   0x5CFB9 }, // System ʾ����������
        { szFont,        0x04,   0x169B6 }, // Ĭ������
        { 0xA1AA,        0x02,   0x5D0F7 }, // ���ۺ� ��
        { 0xA844,        0x02,   0x5D100 }, // ���ۺ� ��
        { 0xA1AA,        0x02,   0x387D6 }, // ���ۺ� ��
        { 0xA844,        0x02,   0x387DF }, // ���ۺ� ��
//        { GB2312_CHARSET,0x01,   0x5CFD6 }, // CreateFontA char set
//        { 0x06,          0x01,   0x5CFCF }, // GGO_GRAY8_BITMAP
//        { 0x3F,          0x01,   0x5D1CA }, // GGO_GRAY8_BITMAP

        // bound
        { 0xEB,          0x01,   0x38A1F }, // �ƻ��ű��߽���
        { 0xEB,          0x01,   0x5C63B }, // �ƻ��浵ע�ͱ߽���
        { 0xEB,          0x01,   0x0FF12 },
        { 0xEB,          0x01,   0x1E48E },
        { 0xEB,          0x01,   0x2648B },
        { 0xEB,          0x01,   0x38941 },
        { 0xEB,          0x01,   0x38B29 },
        { 0xEB,          0x01,   0x38D98 },
        { 0xEB,          0x01,   0x3DD30 },
        { 0xEB,          0x01,   0x3E05C },
        { 0xEB,          0x01,   0x5E8E8 },
        { 0xEB,          0x01,   0x5E8DD },

//        { (DWORD)ReadFileFromPaz, 0x04, 0xA1510 }, // ��ȡ�ļ�
    };

#elif defined(EF_FIRST)

    INTEL_STATIC SFuncPatch f[] =
    {
/*
        { CALL, 0x23F50, ReadFileFromPaz,      0x00 },
        { CALL, 0x2A7A9, ReadFileFromPaz,      0x00 },
        { CALL, 0x4DDBC, ReadFileFromPaz,      0x00 },
        { CALL, 0x5FA2D, ReadFileFromPaz,      0x00 },
        { CALL, 0x81427, ReadFileFromPaz,      0x00 },
        { CALL, 0x23DFB, DecodePng,        0x00 },    // ���⻭�����
        { CALL, 0x5FA57, DecodePng,        0x00 },    // ����CG����
*/
        { JUMP, 0x5FB20, DecodePng,            0x00, OldDecodePng },
        { JUMP, 0x5A620, ReadFileFromPaz,      0x02, OldReadFileFromPaz },

        { CALL, 0x501FC, RederChar,            0x00 },    // ���ּ�಻һ��
        { CALL, 0x59B4D, DynamicReadMask,      0x03 },
        { CALL, 0x76893, TrimSpceInCharName,   0x01 },
        { CALL, 0x2C2BB, CompareCharNameEfFirst, 0x00 },

        // voice
        { JUMP, 0x4E740, PlayGameSound,  0x00, OldPlayGameSound },
//        { CALL, 0x39323, StopVoiceBeforeNext,   0x01 },    // �����¾�Ի�ǰֹͣ��������
//        { CALL, 0x35519, StopVoiceBeforeReturn, 0x01 },    // �������˵�ǰֹͣ����
//        { CALL, 0x36DAD, FixWaitForVoiceStop,   0x01 },    // ����ʹ�þ���������ʱ/v��Ч
//        { CALL, 0x39118, AutoModeWaitForVoice,  0x01 },    // �Զ�����ģʽ�ȴ���������
    };

    INTEL_STATIC SPatch p[] =
    {
        { FW_NORMAL,     0x04,   0x84C66 }, // fnWeight
//        { GB2312_CHARSET,0x04,   0x84C7D }, // CreateFontA char set
        { GB2312_CHARSET,0x01,   0x54026 }, // EnumFontFamiliesExAb char set
        { 0x00E2,        0x04,   0x16A6F }, // ���� System ʾ������ Rect ���
        { 0x01EF,        0x04,   0x16A77 }, // ���� System ʾ������ Rect �߶�
        { 0x81,          0x01,   0x5050E }, // �߽���
        { 0xEB,          0x01,   0x540DE }, // ����� LOGFONT::lfStrikeOut
        { 0xB8,          0x01,   0x2123A }, // report.txt
        { szSaveFolder,  0x04,   0x1DBBB }, // save folder
        { szFont,        0x04,   0x1E494 }, // Ĭ������
        { szFont,        0x04,   0x1E4BE }, // Ĭ������
        { szFont,        0x04,   0x84C4A }, // Ĭ������
        { szFont,        0x04,   0x16CC2 }, // Ĭ������
        { szFont,        0x04,   0x5422E }, // Ĭ������
        { szFont,        0x04,   0x542D6 }, // Ĭ������
        { szFont,        0x04,   0x84D18 }, // Ĭ������
        { 0x81,          0x01,   0x1410C }, // �浵ͨ��
        { 0x02CAE9,      0x04,   0x1D20C }, // 1.00.1 �����������˵�
        { 0xA1AA,        0x02,   0x84FEC }, // ���ۺ���ʾ���� ��
        { 0xA844,        0x02,   0x84FF4 }, // ���ۺ���ʾ���� ��
        { 0xA1AA,        0x02,   0x5024D }, // ���ۺ���ʾ���� ��
        { 0xA844,        0x02,   0x50255 }, // ���ۺ���ʾ���� ��
        { 0xEB,          0x01,   0x501A5 }, // ����ַ����
        { 0xEB,          0x01,   0x5020C }, // ͬ��

        // vtable hook
//        { (DWORD)ReadFileFromPaz, 0x04, 0xE7700 }, // ��ȡ�ļ�

        // IAT hook
//        { (DWORD)MyCreateFileA, 0x04, 0xE1198 }, // ��ȡ�ļ�
    };

#elif defined(EF_LATTER)

    INTEL_STATIC SFuncPatch f[] =
    {
/*
        { CALL, 0x46324, DecodePng,        0x00 },    // ���⻭�����
        { CALL, 0x1FA63, DecodePng,        0x00 },    // ����CG����
*/
        { JUMP, 0x46358, DecodePng,       0x00, OldDecodePng },
        { JUMP, 0x43039, ReadFileFromPaz, 0x00, OldReadFileFromPaz },

        { CALL, 0x3BEBB, RederChar,            0x00 },    // ���ּ�಻һ��
        { CALL, 0x42B16, DynamicReadMask,      0x01 },
        { CALL, 0x575FA, TrimSpceInCharName,   0x01 },
        { CALL, 0x24B27, CompareCharName,      0x00 },

        // voice
        { JUMP, 0x3AF7A, GetVorbisInfoEfLatter, 0x04, OldGetVorbisInfo },
        { JUMP, 0x3AB1A, PlayGameSound,         0x00, OldPlayGameSound },
/*
        { CALL, 0x2D1CC, StopVoiceBeforeNext,   0x01 },    // �����¾�Ի�ǰֹͣ��������
        { CALL, 0x2A326, StopVoiceBeforeReturn, 0x01 },    // �������˵�ǰֹͣ����
        { CALL, 0x2B8B0, FixWaitForVoiceStop,   0x01 },    // ����ʹ�þ���������ʱ/v��Ч
        { CALL, 0x2D052, AutoModeWaitForVoice,  0x02 },    // �Զ�����ģʽ�ȴ���������
*/
    };

    INTEL_STATIC SPatch p[] =
    {
        // crack
        { 0xFA,   0x01, 0x190E3 },  // ���кŲ���23�ֽ�
        { 0x0226, 0x02, 0x1AED3 },  // ͬ��
        { 0xEB,   0x01, 0x1D21F },  // ȥ�������߳�
        { 0x00,   0x01, 0x064FA },  // InstallKeyCodeУ��

        // font
//        { GB2312_CHARSET, 0x04,   0x62DEF }, // CreateFontA char set
        { FW_NORMAL,      0x04,   0x62DD8 }, // fnWeight
        { GB2312_CHARSET, 0x01,   0x3EA47 }, // EnumFontFamiliesExAb char set
        { 0xEB,           0x01,   0x3EABF }, // ����� LOGFONT::lfStrikeOut
        { szFont,         0x04,   0x1617C }, // Ĭ������
        { szFont,         0x04,   0x1BFB7 }, // Ĭ������
        { szFont,         0x04,   0x3EB58 }, // Ĭ������
        { szFont,         0x04,   0x62DBE }, // Ĭ������
        { 0xEB,           0x01,   0x3C175 }, // �߽���
        { 0x01EF,         0x04,   0x15FB1 }, // ���� System ʾ������ Rect �߶�
        { 0xEB,           0x01,   0x3BE73 }, // ����ַ����
        { 0xEB,           0x01,   0x3BECA }, // ͬ��
        { 0xA1AA,         0x04,   0x63080 }, // ���ۺ���ʾ���� ��
        { 0xA1AA,         0x04,   0x3BF1A }, // ���ۺ���ʾ���� ��

        // misc
        { 0x00,           0x01,   0x1457F }, // �浵ͨ��
        { 0xEB,           0x01,   0x62141 }, // �浵ͨ��
        { 0x33,           0x01,   0x21692 }, // save folder
        { szSaveFolder,   0x04,   0x1BB5D }, // save folder
        { 0xE959,         0x02,   0x1AB62 }, // �����������˵�   pop ecx; jmp
        { 0x0000029F,     0x04,   0x1AB64 }, // �����������˵�   41AE07h

        // vtable hook
//        { (DWORD)ReadFileFromPaz, 0x04, 0xBBBE0 }, // ��ȡ�ļ�
    };

#endif

#ifndef MY_DEBUG
    PatchMemoryNoVP(p, countof(p), f, countof(f), GetModuleHandleW(0));
#else
    PatchMemory(p, countof(p), f, countof(f), GetModuleHandleW(0));
#endif
}