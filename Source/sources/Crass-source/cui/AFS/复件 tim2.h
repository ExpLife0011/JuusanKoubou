#ifndef TIM2_H
#define TIM2_H

#pragma pack (1)
typedef struct
{
	char FileId[4];      // ID of the File (must be 'T', 'I', 'M' and '2')
	BYTE FormatVersion;  // Version number of the format (4)
	BYTE FormatId;       // ID of the format (0)
	WORD Pictures;       // Number of picture data
	char Reserved[8];    // Padding (must be 0x00)
} TIM2_FILEHEADER;

typedef struct
{
	DWORD   TotalSize;      // Total size of the picture data in bytes(������TIM2_FILEHEADER)
	DWORD   ClutSize;       // CLUT data size in bytes(��ɫ�壩
	DWORD   ImageSize;      // Image data size in bytes��RGBA���ݳ��ȣ�������ClutSize��
	WORD    HeaderSize;     // Header size in bytes��TIM2_PICTUREHEADER���ȣ�
	WORD    ClutColors;     // Total color number in CLUT data����ɫ����ɫ����
	BYTE    PictFormat;     // ID of the picture format (must be 0)
	BYTE    MipMapTextures; // Number of MIPMAP texture��1����
	BYTE    ClutType;       // Type of the CLUT data��3��0?��
	BYTE    ImageType;      // Type of the Image data
	WORD    ImageWidth;     // Width of the picture
	WORD    ImageHeight;    // Height of the picture
	BYTE    GsTex0[8];      // Data for GS TEX0 register������
	BYTE    GsTex1[8];      // Data for GS TEX1 register������
	DWORD   GsRegs;         // Data for GS TEXA, FBA, PABE register������
	DWORD   GsTexClut;      // Data for GS TEXCLUT register������
} TIM2_PICTUREHEADER;
#pragma pack ()

#endif
