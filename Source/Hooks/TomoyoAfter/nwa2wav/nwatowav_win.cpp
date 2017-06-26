#pragma comment(linker,"/ENTRY:main")
#pragma comment(linker,"/MERGE:.text=.Kaede /SECTION:.Kaede,EWR")
#pragma comment(linker, "/MERGE:.rdata=.Kaede")
#pragma comment(linker, "/MERGE:.data=.Kaede")

/* nwatowav : Visual Arts ϵ�Υ��`��Υǥ��ʹ���� nwa ��ʽ��
**            �ե������ wav ��ʽ�ˉ�Q����
**
**     compile : gcc -O2 -o nwatowav nwatowav.cc
**     usage : nwatowav [nwa-file [outfile]]
**	       nwatowav [nwk-file [outfile]]
**     example : nwatowav HM06.nwa HM06.wav	# BGM�ե����롣HM06.wav ��չ�_�����
**		 nwatowav z2813.nwk z2813	# �����ե����롣 z2813-100.wav �ʤɤΥե���������չ�_�����
**		 nwatowav z0513.ovk z0513	# �����ե����롣 z0513-100.ogg �ʤɤΥե���������չ�_�����
**
**
** 2004.5.19 С�ɤ���<s1100089@u-aizu.ac.jp> ���� CLANNAD �Οo�R�snwa��ʽ�ˌ��ꤹ��
**           �ѥå��򤤤��������Τǡ��m�ä��ޤ��������꤬�Ȥ��������ޤ���
** 2006.9.10 ���Ǵ����ե��`���������ե�������ʽ (complevel = 5) �򥵥ݩ`��
**	     .nwk �Ȥ��������Ӥ�֤ĥե�������ܤ�ȡ��������ե�����Ȥ���
**	     ��ዡ��ָ��չ�_����褦�ˤ���
** 2007.7.28 ����ȥ�Х����`�������������ե�������ʽ (*.ovk; ogg �B�Y��)
**		�򥵥ݩ`�ȡ�.ovk �Ȥ��������Ӥ��ĥե�������ܤ�ȡ���
**		�����ե�����Ȥ��ƽ�ዡ��ָ��չ�_����褦�ˤ���
**	     ����ȥ�Х����`��������BGM�ե�����˶����ΥΥ������\�놖�}��
**	     ����Q������󥰥��R�s�΄I������Ҫ���ä���
*/

/*
 * Copyright 2001-2007  jagarl / Kazunori Ueno <jagarl@creator.club.ne.jp>
 * All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted.
 *
 * ���Υץ��������ߤ� jagarl �Ǥ���
 *
 * ���Υץ���ࡢ���ӥ���ѥ���ˤ�ä����ɤ����Х��ʥ��
 * �ץ����������롢���ʤ��ˤ�����餺���䲼���ܤǤ���
 * �����H����ӛ Copyright ��ʾ�򱣳֤���ʤɤ��������n����
 * ���󡣌��꤬�浹�ʤΤǥХ������������`����B�j�򤹤�
 * �ʤɤα�Ҫ�⤢��ޤ��󡣥��`����һ�������ä��뤳�Ȥ򺬤ᡢ
 * �����ɤˤ�ʹ������������
 *
 * THIS SOFTWARE IS PROVIDED BY KAZUNORI 'jagarl' UENO ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL KAZUNORI UENO BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 * 
 */

/********************************************
**
**	nwa �ե��`�ޥåȤˤĤ���
**
**		ȫ��Ȥ��Ƥ����¤Θ����֤�
**		NWA Header
**		data offset index
**		data block<0>
**		data block<1>
**		...
**		data block<N>
**
**	NWA Header: �ե��������^���� 44 bytes
**		magic number �ʤɤϤʤ��Τ�nwa �ե����뤫��
**		�ǩ`���������Ԥ����жϤ����Ҫ������
**		�ǩ`����ȫ�� little endian �ǡ�
**		short(signed 2byte)�ޤ��� int(signed 4byte) �Ǥ��롣
**
**		+00 short   channel ��(1/2)
**		+02 short   sample һ�Ĥ������ bit ��(16)
**		+04 int     �ܲ���(һ�뤢����Υǩ`����)
**		+08 int     �R�s��٥룺-1~5.2����С�Υǩ`����0�����Ώ�Ԫ��(-1�ϟo�R�sraw�ǩ`���Ȥߤʤ����)
**		+12 int     ?
**		+16 int     �֥�å���
**		+20 int     չ�_��Υǩ`���δ󤭤�(�Х��ȅgλ)
**		+24 int     �R�s�r�Υǩ`���δ󤭤�(nwa �ե�����δ󤭤����Х��ȅgλ)
**		+28 int     ����ץ�����չ�_��Υǩ`����(16bit data�ʤ� short �gλ==����ץ�gλ�Υǩ`���δ󤭤�)
**		+32 int     �ǩ`�����֥�å���չ�_�����r�Υ���ץ�gλ�Υǩ`����
**		+36 int     ��K�֥�å���չ�_�����r�Υ���ץ�gλ�Υǩ`����
**		+40 int     ?
**		
**	data offset index
**		ȫ�֥�å��� x 4 byte �Υǩ`��
**		���줾�� int �Υǩ`����ȫ�֥�å����A���Ƥ���
**
**		�ǩ`���֥�å������^��ָ���ե��������^�����λ��(���ե��å�)
**		����{����Ƥ���
**
**	data block
**		�L���Ͽɉ䡣չ�_���뤳�Ȥ�һ���δ󤭤����ĥǩ`����չ�_����롣
**		�ǩ`����DPCM��ʽ��Ԫ PCM �ǩ`���� a,b,c �ʤ�� (a),b-a, c-b ��
**		���ä���֥ǩ`����������3-5bit,ָ��3bit����ʽ�Ǳ��椵��Ƥ��롣
**		�Y���Ĥˡ�16bit �Υǩ`�����य�Έ��� 6-8bit �Ǹ�{����롣
**		�����Υӥå����ψR�s��٥�0��5bit���R�s��٥�2��3bit�Ȥʤ롣
**		���¡��R�s��٥�2�Έ��ϤˤĤ���Ԓ���M��롣
**		��Υ��Έ��ϣ�
**			+00 short  �֥�å��ڤ�����Υǩ`��
**			+02- bit stream
**		���ƥ쥪�Έ��ϣ�
**			+00 short  ��(?)�����ͥ������Υǩ`��
**			+02 short  ��(?)�����ͥ������Υǩ`��
**			+04- bit stream
**
**		��֥ǩ`���ξ��Ȥ��ߤ��ʤ��ΤǸ��֥�å������^��
**		���_�ʥǩ`���ˤ���a�������(��)
**
**	bit stream
**		little endian
**		+0 - +2 : ָ��
**		+3 - +5 : ����
**		����ʽ�������� a,b,c �Ȥ���8bit�ǩ`��������С�
**		a&0x07 : �ǩ`������ָ��
**		(a>>3)&0x07 : �ǩ`�����΁���(signed ; 
**		((b<<2)|(a>>6))&0x07 : �ǩ`������ָ��
**		(b>>1)&0x07 : �ǩ`�����΁���
**		�Ȥʤ롣
**		��������ָ���΂��ˤ�ꁢ����bit�����仯���뤳�Ȥ����롣
**		ָ�� = 1 - 6 �Έ��ϣ�
**			a=ָ����b=������p=ǰ�Υǩ`���Ȥ��ơ���ؤΥǩ`��d ��
**			b��2bitĿ�����äƤ�����ϣ�
**				d = p - (b&3)<<(4+a)
**			���äƤʤ����ϣ�
**				d = p + (b&3)<<(4+a)
**		ָ�� = 0 �Έ��ϣ������ϴ��ڤ��ʤ�(�ǩ`����3bit�Ȥʤ�)
**			d = p
**			���Ǵ����ե��`���������ե����� (complevel == 5) �Ǥϥ���󥰥��R�s�ä�ʹ���Ƥ��롣
**		ָ�� = 7
**			�Τ� bit �����äƤ�����ϣ�
**				d = 0 (�F��δʹ��)
**				(�ǩ`����4bit�Ȥʤ�)
**			�Τ� bit �����äƤʤ����ϣ�
**				complevel = 0,1,2:
**				   ���� b = 6bit
**				   b �� 5bit Ŀ�����äƤ�����ϣ�
**					d = p - (b&0x1f)<<(4+7)
**				   ���äƤʤ����ϣ�
**					d = p + (b&0x1f)<<(4+7)
**				   (�ǩ`����10bit�Ȥʤ�)
**				complevel = 3,4,5:
**				   ���� b = 8bit
**				   b �� 7bit Ŀ�����äƤ�����ϣ�
**					d = p - (b&0x7f)<<9
**				   ���äƤʤ����ϣ�
**					d = p + (b&0x1f)<<9
**				   (�ǩ`����10bit�Ȥʤ�)
**
**		�R�s��٥뤬���ʤ���ϡ����Ȥ��ЈR�s��٥�==0��
**			ָ��==1~6��d������λbit�����äƤ������
**				d = p - (b&0x0f)<<(2+a)
**			ָ��==7��d������λbit�����äƤ������
**				d = p - (b&0x7f)<<(2+7)
**				(b : 8bit�ʤΤǥǩ`����12bit�Ȥʤ�)
**		�Τ褦�ˡ����Ȥ������仯����褦�ˤʤäƤ��롣
**
**	�إå��i���z�ߤˤĤ��Ƥ�NWAData::ReadHeader()����
**	bit stream ����Υǩ`��չ�_�ˤĤ��Ƥ� NWADecode()����
**************************************************************
*/

// #define NDEBUG /* �ʤ��� assert����ä������٤������� */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <direct.h>
#include <sys/stat.h>
#include <string.h>
#include "getmainargs.h"
#include "my_crtadd.h"

#ifdef WORDS_BIGENDIAN
#error Sorry, This program does not support BIG-ENDIAN system yet.
/* �⤷ big endian �Υ����ƥ�ˌ��ꤵ�������
** ���¤� *_little_endian_* ����
** getbits() �v�����������Ҫ������
*/
#endif

inline int read_little_endian_int(const char* buf) {
	return *(int*)buf;
}

inline int read_little_endian_short(const char* buf) {
	return *(short*)buf;
}

inline int write_little_endian_int(char* buf, int number) {
	int c = *(int*)buf; *(int*)buf = number; return c;
}

inline int write_little_endian_short(char* buf, int number) {
	int c = *(short*)buf; *(short*)buf = number; return c;
}
inline int getbits(const char*& data, int& shift, int bits) {
	if (shift > 8) { data++; shift-=8;}
	int ret = read_little_endian_short(data)>>shift;
	shift += bits;
	return ret & ((1<<bits)-1); /* mask */
}

/* ָ�����줿��ʽ�Υإå���Ĥ��� */
const char* make_wavheader(int size, int channels, int bps, int freq) {
	static char wavheader[0x2c] = {
		'R','I','F','F',
		0,0,0,0, /* +0x04: riff size*/
		'W','A','V','E',
		'f','m','t',' ',
		16,0,0,0, /* +0x10 : fmt size=0x10 */
		1, 0,    /* +0x14 : tag : pcm = 1 */
		2, 0,    /* +0x16 : channels */
		0,0,0,0, /* +0x18 : samples per second */
		0,0,0,0, /* +0x1c : average bytes per second */
		0,0,     /* +0x20 : block alignment */
		0,0,     /* +0x22 : bits per sample */
		'd','a','t','a',
		0,0,0,0};/* +0x28 : data size */
	write_little_endian_int(wavheader+0x04, size+0x24);
	write_little_endian_int(wavheader+0x28, size);
	write_little_endian_short(wavheader+0x16, channels);
	write_little_endian_short(wavheader+0x22, bps);
	write_little_endian_int(wavheader+0x18, freq);
	int byps = (bps+7)>>3;
	write_little_endian_int(wavheader+0x1c, freq*byps*channels);
	write_little_endian_short(wavheader+0x20, byps*channels);
	return wavheader;
}

/* NWA �� bitstreamչ�_�˱�Ҫ�Ȥʤ���� */
class NWAInfo {
	int channels;
	int bps;
	int complevel;
	bool use_runlength;
public:
	NWAInfo(int c,int b,int cl) {
		channels=c;
		bps=b;
		complevel=cl;
		use_runlength = false;
		if (cl == 5) {
			use_runlength = true; // Tomoyo After (.nwk koe file)
			if (channels == 2) use_runlength = false; // BGM*.nwa in Little Busters!
		}
	}
	int Channels(void) const{return channels;}
	int Bps(void) const { return bps;}
	int CompLevel(void) const { return complevel;}
	int UseRunLength(void) const { return use_runlength; }
};

template<class NWAI> void NWADecode(const NWAI& info,const char* data, char* outdata, int datasize, int outdatasize) {
	int d[2];
	int i;
	int shift = 0;
	const char* dataend = data+datasize;
	/* ����Υǩ`�����i���z�� */
	if (info.Bps() == 8) {d[0] = *data++; datasize--;}
	else /* info.Bps() == 16 */ {d[0] = read_little_endian_short(data); data+=2; datasize-=2;}
	if (info.Channels() == 2) {
		if (info.Bps() == 8) {d[1] = *data++; datasize--;}
		else /* info.Bps() == 16 */ {d[1] = read_little_endian_short(data); data+=2; datasize-=2;}
	}
	int dsize = outdatasize / (info.Bps()/8);
	int flip_flag = 0; /* stereo �� */
	int runlength = 0;
	for (i=0; i<dsize; i++) {
		if (data >= dataend) break;
		if (runlength == 0) { // ���ԩ`��`���ФǤʤ��ʤ�ǩ`���i���z��
			int type = getbits(data, shift, 3);
			/* type �ˤ���᪣�0, 1-6, 7 */
			if (type == 7) {
				/* 7 : �󤭤ʲ�� */
				/* RunLength() �Є��r��CompLevel==5, �����ե�����) �Ǥϟo�� */
				if (getbits(data, shift, 1) == 1) {
					d[flip_flag] = 0; /* δʹ�� */
				} else {
					int BITS, SHIFT;
					if (info.CompLevel() >= 3) {
						BITS = 8;
						SHIFT = 9;
					} else {
						BITS = 8-info.CompLevel();
						SHIFT = 2+7+info.CompLevel();
					}
					const int MASK1 = (1<<(BITS-1));
					const int MASK2 = (1<<(BITS-1))-1;
					int b = getbits(data, shift, BITS);
					if (b&MASK1)
						d[flip_flag] -= (b&MASK2)<<SHIFT;
					else
						d[flip_flag] += (b&MASK2)<<SHIFT;
				}
			} else if (type != 0) {
				/* 1-6 : ͨ���β�� */
				int BITS, SHIFT;
				if (info.CompLevel() >= 3) {
					BITS = info.CompLevel()+3;
					SHIFT = 1+type;
				} else {
					BITS = 5-info.CompLevel();
					SHIFT = 2+type+info.CompLevel();
				}
				const int MASK1 = (1<<(BITS-1));
				const int MASK2 = (1<<(BITS-1))-1;
				int b = getbits(data, shift, BITS);
				if (b&MASK1)
					d[flip_flag] -= (b&MASK2)<<SHIFT;
				else
					d[flip_flag] += (b&MASK2)<<SHIFT;
			} else { /* type == 0 */
				/* ����󥰥��R�s�ʤ��Έ��ϤϤʤˤ⤷�ʤ� */
				if (info.UseRunLength() == 1) {
					/* ����󥰥��R�s����Έ��� */
					runlength = getbits(data,shift,1);
					if (runlength==1) {
						runlength = getbits(data,shift,2);
						if (runlength == 3) {
							runlength = getbits(data, shift, 8);
						}
					}
				}
			}
		} else {
			runlength--;
		}
		if (info.Bps() == 8) {
			*outdata++ = d[flip_flag];
		} else {
			write_little_endian_short(outdata, d[flip_flag]);
			outdata += 2;
		}
		if (info.Channels() == 2) flip_flag ^= 1; /* channel �Ф��椨 */
	}
	return;
};

class NWAData {
public:
	int channels;
	int bps; /* bits per sample */
	int freq; /* samples per second */
private:
	int complevel; /* compression level */
	int dummy; /* ? : 0x00 */
public:
	int blocks; /* block count */
	int datasize; /* all data size */
private:
	int compdatasize; /* compressed data size */
	int samplecount; /* all samples */
	int blocksize; /* samples per block */
	int restsize; /* samples of the last block */
	int dummy2; /* ? : 0x89 */
	int curblock;
	int* offsets;
	int offset_start;
	int filesize;
	char* tmpdata;
public:
	void ReadHeader(FILE* in, int file_size=-1);
	int CheckHeader(void); /* false: invalid true: valid */
	NWAData(void) {
		offsets = 0;
		tmpdata = 0;
	}
	~NWAData(void) {
		if (offsets) free(offsets);
		if (tmpdata) free(tmpdata);
	}
	int BlockLength(void) {
		if (complevel != -1) {
			if (offsets == 0) return false;
			if (tmpdata == 0) return false;
		}
		return blocksize * (bps/8);
	}
	/* data �� BlockLength ���Ϥ��L����֤Ĥ���
	** ���ꂎ�����ɤ����ǩ`�����L�����K�˕r�� 0��
	** ����`�r�� -1
	*/
	int Decode(FILE* in, char* data, int& skip_count);
	void Rewind(FILE* in);
};

void NWAData::ReadHeader(FILE* in, int _file_size) {
	char header[0x2c];
	struct _stat sb;
	int i;
	if (offsets) free(offsets);
	if (tmpdata) free(tmpdata);
	offsets = 0;
	tmpdata = 0;
	filesize = 0;
	offset_start = ftell(in);
	if (offset_start == -1) offset_start = 0;
	if (_file_size != -1) filesize = _file_size;
	curblock = -1;
	/* header �i���z�� */
	if (in == 0 || feof(in) || ferror(in)) {
		fprintf(stderr,"invalid stream\n");
		return;
	}
	fread(header, 0x2c, 1, in);
	if (feof(in) || ferror(in)) {
		fprintf(stderr,"invalid stream\n");
		return;
	}
	channels = read_little_endian_short(header+0x00);
	bps = read_little_endian_short(header+0x02);
	freq = read_little_endian_int(header+0x04);
	complevel = read_little_endian_int(header+0x08);
	dummy = read_little_endian_int(header+0x0c);
	blocks = read_little_endian_int(header+0x10);
	datasize = read_little_endian_int(header+0x14);
	compdatasize = read_little_endian_int(header+0x18);
	samplecount = read_little_endian_int(header+0x1c);
	blocksize = read_little_endian_int(header+0x20);
	restsize = read_little_endian_int(header+0x24);
	dummy2 = read_little_endian_int(header+0x28);
	if (complevel == -1) {	/* �o�R�sraw�ǩ`�� */
		/* �m���˛Q�������� */
		blocksize = 65536;
		restsize = (datasize % (blocksize * (bps/8))) / (bps/8);
		blocks = datasize / (blocksize * (bps/8)) + (restsize > 0 ? 1 : 0);
	}
	if (blocks <= 0 || blocks > 1000000) {
		/* ���r�g�򳬤������äƤΤϤʤ��Ǥ���*/
		fprintf(stderr,"too large blocks : %d\n",blocks);
		return;
	}
	/* regular file �ʤ� filesize �i���z�� */
	if (filesize == 0 && _fstat(fileno(in), &sb)==0 && (sb.st_mode&S_IFMT) == S_IFREG) {
		int pos = ftell(in);
		fseek(in, 0, 2);
		filesize = ftell(in);
		fseek(in, pos, 0);
		if (pos+blocks*4 >= filesize) {
			fprintf(stderr,"offset block is not exist\n");
			return;
		}
	}
	if (complevel == -1) return;
	/* offset index �i���z�� */
    offsets = (int *)malloc(blocks * sizeof(*offsets));
	fread(offsets, blocks, 4, in);
	for (i=0; i<blocks; i++) {
		offsets[i] = read_little_endian_int((char*)(offsets+i));
	}
	if (feof(in) || ferror(in)) {
		fprintf(stderr,"invalid stream\n");
		free(offsets);
		offsets = 0;
		return;
	}
	return;
}
void NWAData::Rewind(FILE* in) {
	curblock = -1;
	fseek(in, 0x2c, 0);
	if (offsets) fseek(in, blocks*4, 0);
}
int NWAData::CheckHeader(void) {
	if (complevel != -1 && offsets == 0) return false;
	/* �ǩ`�����Τ�ΤΥ����å� */
	if (channels != 1 && channels != 2) {
		fprintf(stderr,"This program only supports mono / stereo data : data have %d channels.\n",channels);
		return false;
	}
	if (bps != 8 && bps != 16) {
		fprintf(stderr,"This program only supports 8 / 16bit data : data is %d bits\n",bps);
		return false;
	}
	if (complevel == -1) {
		int byps = bps/8; /* bytes per sample */
		if (datasize != samplecount*byps) {
			fprintf(stderr,"invalid datasize : datasize %d != samplecount %d * samplesize %d\n",datasize,samplecount,byps);
			return false;
		}
		if (samplecount != (blocks-1)*blocksize+restsize ) {
			fprintf(stderr,"total sample count is invalid : samplecount %d != %d*%d+%d(block*blocksize+lastblocksize).\n",samplecount,blocks-1,blocksize,restsize);
			return false;
		}
		else
			return true;
	}
	//if (complevel < 0 || complevel > 2) {
	if (complevel < 0 || complevel > 5) {
		fprintf(stderr,"This program only supports -1,0,1,2 compression level : the level of data is %d\n",complevel);
		return false;
	}
	/* �����ԥ����å� */
	if (filesize != 0 && filesize != compdatasize) {
		fprintf(stderr,"file size is invalid : %d != %d\n",filesize,compdatasize);
		return false;
	}
	if (offsets[blocks-1] >= compdatasize) {
		fprintf(stderr,"the last offset overruns the file.\n");
		return false;
	}
	int byps = bps/8; /* bytes per sample */
	if (datasize != samplecount*byps) {
		fprintf(stderr,"invalid datasize : datasize %d != samplecount %d * samplesize %d\n",datasize,samplecount,byps);
		return false;
	}
	if (samplecount != (blocks-1)*blocksize+restsize ) {
		fprintf(stderr,"total sample count is invalid : samplecount %d != %d*%d+%d(block*blocksize+lastblocksize).\n",samplecount,blocks-1,blocksize,restsize);
		return false;
	}
    tmpdata = (char *)malloc(blocksize * byps * 2); /* �������Ϥδ󤭤��Ϥʤ����������� */
	return true;
}

class NWAInfo_sw2 {
public:
	int Channels(void) const{return 2;}
	int Bps(void) const { return 16;}
	int CompLevel(void) const { return 2;}
	int UseRunLength(void) const { return false; }
};
int NWAData::Decode(FILE* in, char* data, int& skip_count) {
	if (complevel == -1) {		/* �o�R�s�r�΄I�� */
		if (feof(in) || ferror(in)) return -1;
		if (curblock == -1) {
			/* ����Υ֥�å��ʤ顢wave header ���� */
			memcpy(data, make_wavheader(datasize, channels, bps, freq), 0x2c);
			curblock++;
			fseek(in, offset_start + 0x2c, SEEK_SET);
			return 0x2c;
		}
		if (skip_count > blocksize/channels) {
			skip_count -= blocksize/channels;
			fseek(in, blocksize*(bps/8), SEEK_CUR);
			curblock++;
			return -2;
		}
		if (curblock < blocks) {
			int readsize = blocksize;
			if (skip_count) {
				fseek(in, skip_count*channels*(bps/8), SEEK_CUR);
				readsize -= skip_count * channels;
				skip_count = 0;
			}
			int err = fread(data, 1, readsize * (bps/8), in);
			curblock++;
			return err;
		}
		return -1;
	}
	if (offsets == 0 || tmpdata == 0) return -1;
	if (blocks == curblock) return 0;
	if (feof(in) || ferror(in)) return -1;
	if (curblock == -1) {
		/* ����Υ֥�å��ʤ顢wave header ���� */
		memcpy(data, make_wavheader(datasize, channels, bps, freq), 0x2c);
		curblock++;
		return 0x2c;
	}
	/* ����i���z�࣯�ǥ��`�ɤ���ǩ`���δ󤭤���ä� */
	int curblocksize, curcompsize;
	if (curblock != blocks-1) {
		curblocksize = blocksize * (bps/8);
		curcompsize = offsets[curblock+1] - offsets[curblock];
		if (curblocksize >= blocksize*(bps/8)*2) return -1; // Fatal error
	} else {
		curblocksize = restsize * (bps/8);
		curcompsize = blocksize*(bps/8)*2;
	}
	if (skip_count > blocksize/channels) {
		skip_count -= blocksize/channels;
		fseek(in, curcompsize, SEEK_CUR);
		curblock++;
		return -2;
	}
	/* �ǩ`���i���z�� */
	fread(tmpdata, 1, curcompsize, in);
	/* չ�_ */
	if (channels == 2 && bps == 16 && complevel == 2) {
		NWAInfo_sw2 info;
		NWADecode(info, tmpdata, data, curcompsize, curblocksize);
	} else {
		NWAInfo info(channels, bps, complevel);
		NWADecode(info, tmpdata, data, curcompsize, curblocksize);
	}
	int retsize = curblocksize;
	if (skip_count) {
		int skip_c = skip_count * channels * (bps/8);
		retsize -= skip_c;
		memmove(data, data+skip_c, skip_c);
		skip_count = 0;
	}
	curblock++;
	return retsize;
}

void conv(FILE* in, FILE* out, int skip_count, int in_size = -1) {
	NWAData h;
	h.ReadHeader(in, in_size);
	h.CheckHeader();
	int bs = h.BlockLength();
	char* d = (char *)malloc(bs);
	int err;
	while( (err=h.Decode(in, d, skip_count)) != 0) {
		if (err == -1) break;
		if (err == -2) continue;
		fwrite(d, err, 1, out);
	}
    free(d);
	return;
}
__forceinline int main2(int argc, char** argv) {
	int skip_count = 0;

	if (argc > 2 && strcmp(argv[1], "--skip") == 0) {
		skip_count = atoi(argv[2]);
		argc -= 2;
		argv[1] = argv[3];
		argv[2] = argv[4];
	}
	if (argc != 2 && argc != 3) {
		fprintf(stderr,"usage : nwatowav [inputfile [outputfile]]\n");
		return -1;
	}
	if (strstr(argv[1], ".nwk") != 0 || strstr(argv[1], ".ovk") != 0) {
		bool is_ovk;
		int headblk_sz;
		char* out_ext;

        char* outpath = (char *)malloc(strlen(argv[1]) + 10);
		char buf[1024];
		memset(buf, 0, 1024);
		FILE* in = fopen(argv[1], "rb");
		if (in == 0) {
            free(outpath);
			fprintf(stderr,"Cannot open file : %s\n",argv[1]);
			return -1;
		}
		if (strstr(argv[1], ".ovk") != 0) {
			is_ovk = true;
			headblk_sz = 16; 
			out_ext = "ogg";
		} else {
			is_ovk = false;
			headblk_sz = 12;
			out_ext = "wav";
		}
		fread(buf, 1, 4, in);
		int index = read_little_endian_int(buf);
		if (index <= 0) { 
			if (is_ovk)
				fprintf(stderr,"Invalid Ogg-ovk file : %s : index = %d\n",argv[1],index);
			else
				fprintf(stderr,"Invalid Koe-nwk file : %s : index = %d\n",argv[1],index);
            free(outpath);
			return -1;
		}
        char *pExt;
		int* tbl_off = (int *)malloc(index * sizeof(int));
		int* tbl_siz = (int *)malloc(index * sizeof(int));
		int* tbl_cnt = (int *)malloc(index * sizeof(int));
		int* tbl_origsiz = (int *)malloc(index * sizeof(int));
		int i;
		for (i=0; i<index; i++) {
			fread(buf, 1, headblk_sz, in);
			tbl_siz[i] = read_little_endian_int(buf);
			tbl_off[i] = read_little_endian_int(buf+4);
			tbl_cnt[i] = read_little_endian_int(buf+8);
			tbl_origsiz[i] = read_little_endian_int(buf+12);
		}
        pExt = findext(argv[1]);
        if (pExt) *pExt = 0;
        pExt = findname(argv[1]);
        mkdir(argv[1]);
        chdir(argv[1]);
		fseek(in, 0, 2);
		int fsize = ftell(in);
		for (i=0; i<index; i++) {
			if (tbl_off[i] <= 0 || tbl_siz[i] <= 0 || tbl_off[i]+tbl_siz[i] > fsize) {
				fprintf(stderr,"Invalid table[%d] : cnt %d off %d size %d / %d\n",i,tbl_cnt[i],tbl_off[i],tbl_siz[i],fsize);
				continue;
			}
			if (argc == 2)
				sprintf(outpath, "%s%05u.%s", pExt, tbl_cnt[i],out_ext);
			else
				sprintf(outpath, "%s%05u.%s", pExt, tbl_cnt[i],out_ext);
			FILE* out = fopen(outpath, "wb");
			if (out == 0) {
				fprintf(stderr,"Cannot open output file %s\n",outpath);
				continue;
			}
			fprintf(stderr,"Writing file %s...\n",outpath);
			fseek(in, tbl_off[i], 0);
			if (is_ovk) { // copy file
				int sz = tbl_siz[i];
				char buf[32*1024];
				while(sz > 32*1024) {
					fread(buf, 32*1024, 1, in);
					fwrite(buf, 32*1024, 1, out);
					sz -= 1024*32;
				}
				if (sz > 0) {
					fread(buf, sz, 1, in);
					fwrite(buf, sz, 1, out);
				}
			} else { // .nwk
				conv(in, out, 0, tbl_siz[i]);
			}
			fclose(out);
		}
        free(outpath);
		return 0;
	}
	FILE* in = fopen(argv[1],"rb");
	if (in == 0) {
		fprintf(stderr,"Cannot open file : %s\n",argv[1]);
		return -1;
	}
	FILE* out;
	char *pExt, outpath[MAX_PATH];
    pExt = findext(argv[1]);
    if (pExt) *pExt = 0;
	sprintf(outpath, "%s.wav",argv[1]);
	if (argc == 3) outpath = argv[2];
	out = fopen(outpath, "wb");
	if (out == 0) {
		fprintf(stderr,"Cannot open file : %s\n",outpath);
        free(outpath);
		return -1;
	}
    conv(in, out, skip_count);
	return 0;
}

void __cdecl main(int argc, char **argv)
{
    getargs(&argc, &argv);
    main2(argc, argv);
    exit(0);
}