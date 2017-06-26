/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library Release 2.7
 */
/*
 *                      ATOK Library Sample
 *
 *                         Version 0.10
 *                           Shift-JIS
 *
 *      Copyright (C) 2002 Sony Computer Entertainment Inc.
 *                        All Rights Reserved.
 *
 *
 *       Version        Date            Design      Log
 *  --------------------------------------------------------------------
 *      0.10
 */

#ifndef _TIM2_H_INCLUDED
#define _TIM2_H_INCLUDED


#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
extern "C" {
#endif
// �������yһ�Τ�����Ͷ��x
typedef unsigned char  TIM2_UCHAR8;
typedef unsigned int   TIM2_UINT32;
typedef unsigned short TIM2_UINT16;

#ifdef R5900
typedef unsigned long  TIM2_UINT64;     // PS2
#else  // R5900
#ifdef WIN32
typedef unsigned __int64 TIM2_UINT64;   // Win32
#else  // WIN32
typedef unsigned long long TIM2_UINT64; // GNU-C
#endif // WIN32
#endif // R5900


// �ԥ�����إå���ClutType,ImageType��ʹ�ä���붨���ζ��x
enum TIM2_gattr_type {
	TIM2_NONE = 0,  // CLUT�ǩ`���ʤ��ΤȤ���ClutType��ʹ��
	TIM2_RGB16,     // 16bit����`(ClutType,ImageType�I����ʹ��)
	TIM2_RGB24,     // 24bit����`(ImageType�ǤΤ�ʹ��)
	TIM2_RGB32,     // 32bit����`(ClutType,ImageType�I����ʹ��)
	TIM2_IDTEX4,    // 16ɫ�ƥ�������(ImageType�ǤΤ�ʹ��)
	TIM2_IDTEX8     // 16(?256)ɫ�ƥ�������(ImageType�ǤΤ�ʹ��)
};

// TIM2�ե�����إå�
typedef struct {
	TIM2_UCHAR8 FileId[4];      // �ե�����ID('T','I','M','2'�ޤ���'C','L','T','2')
	TIM2_UCHAR8 FormatVersion;  // �ե�����ե��`�ޥåȥЩ`�����
	TIM2_UCHAR8 FormatId;       // �ե��`�ޥå�ID
	TIM2_UINT16 Pictures;       // �ԥ�����ǩ`������
	TIM2_UCHAR8 pad[8];         // 16�Х��ȥ��饤�����
} TIM2_FILEHEADER;


// TIM2�ԥ�����إå�
typedef struct {
	TIM2_UINT32 TotalSize;      // �ԥ�����ǩ`��ȫ��ΥХ��ȥ�����
	TIM2_UINT32 ClutSize;       // CLUT�ǩ`�����ΥХ��ȥ�����
	TIM2_UINT32 ImageSize;      // ����`���ǩ`�����ΥХ��ȥ�����
	TIM2_UINT16 HeaderSize;     // ����إå�������
	TIM2_UINT16 ClutColors;     // ����åȥ�����������åȲ���ɫ����
	TIM2_UCHAR8 PictFormat;     // ����ID
	TIM2_UCHAR8 MipMapTextures; // MIPMAPö��
	TIM2_UCHAR8 ClutType;       // ����åȲ��N�e
	TIM2_UCHAR8 ImageType;      // ����`�����N�e
	TIM2_UINT16 ImageWidth;     // ����᥵����(�ӥå����ǤϤ���ޤ���)
	TIM2_UINT16 ImageHeight;    // ����k������(�ӥå����ǤϤ���ޤ���)

	TIM2_UINT64 GsTex0;         // TEX0
	TIM2_UINT64 GsTex1;         // TEX1
	TIM2_UINT32 GsTexaFbaPabe;  // TEXA, FBA, PABE�λ�ϥӥå�
	TIM2_UINT32 GsTexClut;      // TEXCLUT(��λ32bit���Τޤ�)
} TIM2_PICTUREHEADER;


// TIM2�ߥåץޥåץإå�
typedef struct {
	TIM2_UINT64 GsMiptbp1;      // MIPTBP1(64�ӥåȤ��Τޤ�)
	TIM2_UINT64 GsMiptbp2;      // MIPTBP2(64�ӥåȤ��Τޤ�)
	TIM2_UINT32 MMImageSize[0]; // MIPMAP[?]öĿ�λ���Х��ȥ�����
} TIM2_MIPMAPHEADER;


// TIM2�����إå�
typedef struct {
	TIM2_UCHAR8 ExHeaderId[4];  // ���������ȥإå�ID('e','X','t','\x00')
	TIM2_UINT32 UserSpaceSize;  // ��`���`���ک`��������
	TIM2_UINT32 UserDataSize;   // ��`���`�ǩ`���Υ�����
	TIM2_UINT32 Reserved;       // �ꥶ�`��
} TIM2_EXHEADER;


// TIM2�ե������`���Υץ�ȥ���������
int   Tim2CheckFileHeaer(void *p);  // TIM2�ե����뤫�ɤ��������å�
TIM2_PICTUREHEADER *Tim2GetPictureHeader(void *p, int imgno); // ָ��ö��Ŀ�Υԥ�����إå���ȡ��
int   Tim2IsClut2(TIM2_PICTUREHEADER *ph);                    // TIM2,CLUT2���Єe

int   Tim2GetMipMapPictureSize(TIM2_PICTUREHEADER *ph,
                   int mipmap, int *pWidth, int *pHeight);  // MIPMAP��٥뤴�ȤΥԥ����㥵������ȡ��

TIM2_MIPMAPHEADER *Tim2GetMipMapHeader(TIM2_PICTUREHEADER *ph, int *pSize);
                                                            // MIPMAP�إå����_ʼ���ɥ쥹,��������ȡ��

void *Tim2GetUserSpace(TIM2_PICTUREHEADER *ph, int *pSize); // ��`���`���ک`�����_ʼ���ɥ쥹,��������ȡ��
void *Tim2GetUserData(TIM2_PICTUREHEADER *ph, int *pSize);  // ��`���`�ǩ`�����_ʼ���ɥ쥹,��������ȡ��
char *Tim2GetComment(TIM2_PICTUREHEADER *ph);               // �����������Ф��_ʼ���ɥ쥹��ȡ��
void *Tim2GetImage(TIM2_PICTUREHEADER *ph, int mipmap);     // ָ����٥�Υ���`���ǩ`�����_ʼ���ɥ쥹��ȡ��
void *Tim2GetClut(TIM2_PICTUREHEADER *ph);                  // CLUT�ǩ`�����_ʼ���ɥ쥹��ȡ��

unsigned int Tim2GetClutColor(TIM2_PICTUREHEADER *ph,
                    int clut, int no);                        // ָ��CLUT���å�,����ǥ�����CLUT����`�ǩ`����ȡ��
unsigned int Tim2SetClutColor(TIM2_PICTUREHEADER *ph,
                    int clut, int no, unsigned int newcolor); // ָ��CLUT���å�,����ǥ�����CLUT����`�ǩ`�����O��

unsigned int Tim2GetTexel(TIM2_PICTUREHEADER *ph,
                    int mipmap, int x, int y);        // ָ��MIPMAP��٥��ָ���ƥ��������ˤ���ƥ�����ǩ`����ȡ��
unsigned int Tim2SetTexel(TIM2_PICTUREHEADER *ph,
                    int mipmap, int x, int y, unsigned int newtexel); // ָ����٥��ָ�����ˤإƥ�����ǩ`�����O��

unsigned int Tim2GetTextureColor(TIM2_PICTUREHEADER *ph,
                    int mipmap, int clut, int x, int y); // ָ��MIPMAP��٥뤫�顢ָ��CLUT��ʹ�äƥƥ����륫��`��ȡ��


#ifdef R5900

unsigned int Tim2LoadPicture(TIM2_PICTUREHEADER *ph,
                    unsigned int tbp, unsigned int cbp);   // ����`���ǩ`��,CLUT�ǩ`����GS��`��������ܞ��
unsigned int Tim2LoadImage(TIM2_PICTUREHEADER *ph, unsigned int tbp); // ����`���ǩ`����GS��`��������ܞ��
unsigned int Tim2LoadClut(TIM2_PICTUREHEADER *ph, unsigned int cbp);  // CLUT�ǩ`����GS��`��������ܞ��

int Tim2TakeSnapshot(sceGsDispEnv *d0, sceGsDispEnv *d1,
                    char *pszFname);    // ���ʥåץ���åȻ����TIM2�ե�����ǥۥ���HDD�˕�������

#endif // R5900

#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
}
#endif

#endif /* _TIM2_H_INCLUDED */
