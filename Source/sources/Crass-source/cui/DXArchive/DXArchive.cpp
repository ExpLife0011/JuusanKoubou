#include <windows.h>
#include <tchar.h>
#include <crass_types.h>
#include <acui.h>
#include <cui.h>
#include <package.h>
#include <resource.h>
#include <cui_error.h>
#include <utility.h>
#include <stdio.h>
#include <vector>

using namespace std;
using std::vector;

/*
�ҽ���key�ķ�����
��������aa ��push AA��仰����KeyCreate��

Q:\asuhare
 */

/* �ӿ����ݽṹ: ��ʾcui�����һ����Ϣ */
struct acui_information DXArchive_cui_information = {
	_T("ɽ�� ��"),			/* copyright */
	_T("�ģإ饤�֥��"),	/* system */
	_T(".dxa .dat .hud"),	/* package */
	_T("1.0.1"),			/* revision */
	_T("�պ�����"),			/* author */
	_T("2009-7-31 20:18"),	/* date */
	NULL,					/* notion */
	ACUI_ATTRIBUTE_LEVEL_UNSTABLE
};

/*
	�ǩ`���ޥå�
		
	DARC_HEAD
	�ե�����g�ǩ`��
	�ե��������Ʃ`�֥�
	DARC_FILEHEAD �Ʃ`�֥�
	DARC_DIRECTORY �Ʃ`�֥�
*/

/*
	�ե��������Υǩ`����ʽ
	2byte:�����Ф��L��(�Х��ȥ������£�)
	2byte:�����ФΥѥ�ƥ��ǩ`��(ȫ�Ƥ����֤΂����㤷�����)
	Ӣ�֤ϴ����֤ˉ�Q���줿�ե��������Υǩ`��(���α����Υ�����)
	Ӣ�֤������֤ˉ�Q����Ƥ��ʤ��ե��������Υǩ`��
*/

#define FILE_ATTRIBUTE_DIRECTORY		0x00000010

// struct ---------------------------------------

#pragma pack(push)
#pragma pack(1)
// ���`�����֥ǩ`��������Υإå�
typedef struct tagDARC_HEAD {
	s8  Head[2];							// �إå�
	u16 Version;							// �Щ`�����
	u32 HeadSize;							// �إå����� DARC_HEAD ��i����ȫ������
	u32 DataStartAddress;					// ����Υե�����Υǩ`������{����Ƥ���ǩ`�����ɥ쥹(�ե���������^���ɥ쥹�򥢥ɥ쥹���Ȥ���)
	u32 FileNameTableStartAddress;			// �ե��������Ʃ`�֥�����^���ɥ쥹(�ե���������^���ɥ쥹�򥢥ɥ쥹���Ȥ���)
	u32 FileTableStartAddress;				// �ե�����Ʃ`�֥�����^���ɥ쥹(���Љ��� FileNameTableStartAddress �Υ��ɥ쥹�򣰤Ȥ���)
	u32 DirectoryTableStartAddress;			// �ǥ��쥯�ȥ�Ʃ`�֥�����^���ɥ쥹(���Љ��� FileNameTableStartAddress �Υ��ɥ쥹�򣰤Ȥ���)
											// ���ɥ쥹���������ä���Ƥ��� DARC_DIRECTORY �����夬��`�ȥǥ��쥯�ȥ�
} DARC_HEAD ;

// �ե�����Εr�g���
typedef struct tagDARC_FILETIME {
	u64 Create;			// ���ɕr�g
	u64 LastAccess;		// ��K���������r�g
	u64 LastWrite;		// ��K���r�g
} DARC_FILETIME;

// �ե������{���(Ver 0x0001)
typedef struct tagDARC_FILEHEAD_VER1 {
	u32 NameAddress ;			// �ե�����������{����Ƥ��륢�ɥ쥹( ARCHIVE_HEAD������ �Υ��Љ��� FileNameTableStartAddress �Υ��ɥ쥹�򥢥ɥ쥹���Ȥ���) 

	u32 Attributes ;			// �ե���������
	DARC_FILETIME Time ;		// �r�g���
	u32 DataAddress ;			// �ե����뤬��{����Ƥ��륢�ɥ쥹
								//			�ե�����Έ��ϣ�DARC_HEAD������ �Υ��Љ��� DataStartAddress ��ʾ�����ɥ쥹�򥢥ɥ쥹���Ȥ���
								//			�ǥ��쥯�ȥ�Έ��ϣ�DARC_HEAD������ �Υ��Љ��� DirectoryTableStartAddress �Τ�ʾ�����ɥ쥹�򥢥ɥ쥹���Ȥ���
	u32 DataSize ;				// �ե�����Υǩ`��������
} DARC_FILEHEAD_VER1;

// �ե������{���
typedef struct tagDARC_FILEHEAD {
	u32 NameAddress;			// �ե�����������{����Ƥ��륢�ɥ쥹( ARCHIVE_HEAD������ �Υ��Љ��� FileNameTableStartAddress �Υ��ɥ쥹�򥢥ɥ쥹���Ȥ���) 

	u32 Attributes;				// �ե���������
	DARC_FILETIME Time;			// �r�g���
	u32 DataAddress;			// �ե����뤬��{����Ƥ��륢�ɥ쥹
								//			�ե�����Έ��ϣ�DARC_HEAD������ �Υ��Љ��� DataStartAddress ��ʾ�����ɥ쥹�򥢥ɥ쥹���Ȥ���
								//			�ǥ��쥯�ȥ�Έ��ϣ�DARC_HEAD������ �Υ��Љ��� DirectoryTableStartAddress �Τ�ʾ�����ɥ쥹�򥢥ɥ쥹���Ȥ���
	u32 DataSize;				// �ե�����Υǩ`��������
	u32 PressDataSize;			// �R�s��Υǩ`���Υ�����( 0xffffffff:�R�s����Ƥ��ʤ� ) ( Ver0x0002 ��׷�Ӥ��줿 )
} DARC_FILEHEAD;

// �ǥ��쥯�ȥ��{���
typedef struct tagDARC_DIRECTORY {
	u32 DirectoryAddress;			// �Է֤� DARC_FILEHEAD ����{����Ƥ��륢�ɥ쥹( DARC_HEAD ������ �Υ��Љ��� FileTableStartAddress ��ʾ�����ɥ쥹�򥢥ɥ쥹���Ȥ���)
	u32 ParentDirectoryAddress;		// �H�ǥ��쥯�ȥ�� DARC_DIRECTORY ����{����Ƥ��륢�ɥ쥹( DARC_HEAD������ �Υ��Љ��� DirectoryTableStartAddress ��ʾ�����ɥ쥹�򥢥ɥ쥹���Ȥ���)
	u32 FileHeadNum;				// �ǥ��쥯�ȥ��ڤΥե��������
	u32 FileHeadAddress;			// �ǥ��쥯�ȥ��ڤΥե�����Υإå��Ф���{����Ƥ��륢�ɥ쥹( DARC_HEAD������ �Υ��Љ��� FileTableStartAddress ��ʾ�����ɥ쥹�򥢥ɥ쥹���Ȥ���) 
} DARC_DIRECTORY;
#pragma pack(pop)

typedef struct {
	s8 name[MAX_PATH];
	u32 offset;
	u32 comprlen;
	u32 uncomprlen;
} my_dxa_entry_t;

#define DXA_HEAD			"DX"		// �إå�
#define DXA_VER				0x0003		// �Щ`�����
#define DXA_KEYSTR_LENGTH	12			// �I�����Ф��L��

static const char *key_list[] = {
	"hug_001",
	"FbavPKCS7",
	"hug_001_DEMO",
	"jirotsuke",
	NULL
};

// �ե��������ǩ`������Ԫ�Υե��������������Ф�ȡ�ä���
static const char *GetOriginalFileName(u8 *FileNameTable)
{
	return (char *)FileNameTable + *((u16 *)&FileNameTable[0]) * 4 + 4;
}

#define MIN_COMPRESS		(4)						// ��͈R�s�Х�����
#define MAX_SEARCHLISTNUM	(64)					// ���һ���L��̽����Υꥹ�Ȥ��{�������
#define MAX_SUBLISTNUM		(65536)					// �R�s�r�g�̿s�Τ���Υ��֥ꥹ�Ȥ������
#define MAX_COPYSIZE 		(0x1fff + MIN_COMPRESS)	// ���ե��ɥ쥹���饳�ԩ`���Ф���󥵥���( �R�s���`�ɤ���F�Ǥ��륳�ԩ`����������� + ��͈R�s�Х����� )
#define MAX_ADDRESSLISTNUM	(1024 * 1024 * 1)		// ���饤�ɴǕ�����󥵥���
#define MAX_POSITION		(1 << 24)				// ���տ��ܤ�����������ɥ쥹( 16MB )

// �ǥ��`��( ���ꂎ:�����Υ�����  -1 �ϥ���`  Dest �� NULL �����뤳�Ȥ���� )
static int Decode(void *Src, void *Dest)
{
	u32 srcsize, destsize, code, indexsize, keycode, conbo, index ;
	u8 *srcp, *destp, *dp, *sp ;

	destp = (u8 *)Dest ;
	srcp  = (u8 *)Src ;
	
	// �����Υǩ`����������ä�
	destsize = *((u32 *)&srcp[0]) ;

	// �R�s�ǩ`���Υ�������ä�
	srcsize = *((u32 *)&srcp[4]) - 9 ;

	// ���`���`��
	keycode = srcp[8] ;
	
	// �����Ȥ��ʤ����Ϥϥ�������������
	if( Dest == NULL )
		return destsize ;
	
	// չ�_�_ʼ
	sp  = srcp + 9 ;
	dp  = destp ;
	while( srcsize )
	{
		// ���`���`�ɤ�ͬ���ǄI�����
		if( sp[0] != keycode )
		{
			// �ǈR�s���`�ɤΈ��ϤϤ��Τޤ޳���
			*dp = *sp ;
			dp      ++ ;
			sp      ++ ;
			srcsize -- ;
			continue ;
		}
	
		// ���`���`�ɤ��B�A���Ƥ������Ϥϥ��`���`����������
		if( sp[1] == keycode )
		{
			*dp = (u8)keycode ;
			dp      ++ ;
			sp      += 2 ;
			srcsize -= 2 ;
			
			continue ;
		}

		// ��һ�Х��Ȥ�ä�
		code = sp[1] ;

		// �⤷���`���`�ɤ���󤭤ʂ����ä����Ϥϥ��`���`��
		// �ȤΥХåƥ��󥰷�ֹ�Ξ�ˣ������Ƥ���Τǣ�������
		if( code > keycode ) code -- ;

		sp      += 2 ;
		srcsize -= 2 ;

		// �B�A�L��ȡ�ä���
		conbo = code >> 3 ;
		if( code & ( 0x1 << 2 ) )
		{
			conbo |= *sp << 5 ;
			sp      ++ ;
			srcsize -- ;
		}
		conbo += MIN_COMPRESS ;	// ����r�˜p�㤷����С�R�s�Х��������㤹

		// �����������ɥ쥹��ȡ�ä���
		indexsize = code & 0x3 ;
		switch( indexsize )
		{
		case 0 :
			index = *sp ;
			sp      ++ ;
			srcsize -- ;
			break ;
			
		case 1 :
			index = *((u16 *)sp) ;
			sp      += 2 ;
			srcsize -= 2 ;
			break ;
			
		case 2 :
			index = *((u16 *)sp) | ( sp[2] << 16 ) ;
			sp      += 3 ;
			srcsize -= 3 ;
			break ;
		}
		index ++ ;		// ����r�ˣ������Ƥ���Τǣ�������

		// չ�_
		if( index < conbo )
		{
			u32 num ;

			num  = index ;
			while( conbo > num )
			{
				memcpy( dp, dp - num, num ) ;
				dp    += num ;
				conbo -= num ;
				num   += num ;
			}
			if( conbo != 0 )
			{
				memcpy( dp, dp - num, conbo ) ;
				dp += conbo ;
			}
		}
		else
		{
			memcpy( dp, dp - index, conbo ) ;
			dp += conbo ;
		}
	}

	// �����Υ������򷵤�
	return (int)destsize ;
}

static void KeyCreate(const char *Source, unsigned char *Key)
{
	int Len ;

	if (Source == NULL) {
		memset(Key, 0xaaaaaaaa, DXA_KEYSTR_LENGTH);
	} else {
		Len = strlen(Source) ;
		if (Len > DXA_KEYSTR_LENGTH) {
			memcpy(Key, Source, DXA_KEYSTR_LENGTH);
		} else {
			int i ;

			for (i = 0; i + Len <= DXA_KEYSTR_LENGTH; i += Len)
				memcpy(Key + i, Source, Len);
			if (i < DXA_KEYSTR_LENGTH)
				memcpy(Key + i, Source, DXA_KEYSTR_LENGTH - i) ;
		}
	}

	Key[0] = ~Key[0];
	Key[1] = (Key[1] >> 4) | (Key[1] << 4);
	Key[2] = Key[2] ^ 0x8a;
	Key[3] = ~((Key[3] >> 4) | (Key[3] << 4));
	Key[4] = ~Key[4];
	Key[5] = Key[5] ^ 0xac;
	Key[6] = ~Key[6];
	Key[7] = ~((Key[7] >> 3) | (Key[7] << 5));
	Key[8] = (Key[8] >> 5) | (Key[8] << 3);
	Key[9] = Key[9] ^ 0x7f;
	Key[10] = ((Key[10] >> 4) | (Key[10] << 4)) ^ 0xd6;
	Key[11] = Key[11] ^ 0xcc;
}

static void KeyConv(void *Data, int Size, int Position, unsigned char *Key)
{
	int i, j;

	Position %= DXA_KEYSTR_LENGTH;
	j = Position;
	for (i = 0; i < Size; i++) {
		((u8 *)Data)[i] ^= Key[j];
		j++;
		if (j == DXA_KEYSTR_LENGTH) j = 0;
	}
}

// ָ���Υǥ��쥯�ȥ�ǩ`���ˤ���ե������չ�_����
static void DirectoryDecode(u8 *NameP, u8 *DirP, u8 *FileP, 
						   DARC_HEAD *Head, DARC_DIRECTORY *Dir, struct package *pkg, 
						   unsigned char *Key, char *ParentDirPath, 
						   vector<my_dxa_entry_t> &dxa_index)
{
	char DirPath[MAX_PATH];
	
	// �ǥ��쥯�ȥ���󤬤�����Ϥϡ��ޤ�չ�_�äΥǥ��쥯�ȥ�����ɤ���
	if (Dir->DirectoryAddress != 0xffffffff && Dir->ParentDirectoryAddress != 0xffffffff) {
		DARC_FILEHEAD *DirFile;
		
		// DARC_FILEHEAD �Υ��ɥ쥹��ȡ��
		DirFile = (DARC_FILEHEAD * )(FileP + Dir->DirectoryAddress) ;
		
		// �ǥ��쥯�ȥ������
		sprintf(DirPath, "%s%s\\", ParentDirPath, 
			GetOriginalFileName(NameP + DirFile->NameAddress));
		//CreateDirectory(GetOriginalFileName(NameP + DirFile->NameAddress), NULL);
		
		// ���Υǥ��쥯�ȥ�˥����ȥǥ��쥯�ȥ���Ƥ�
		//SetCurrentDirectory( GetOriginalFileName( NameP + DirFile->NameAddress ) ) ;
		//printf("switch dir %s\n", DirPath);
	} else
		strcpy(DirPath, ParentDirPath);

	// չ�_�I���_ʼ
	{
		u32 FileHeadSize;
		DARC_FILEHEAD *File;

		// ��{����Ƥ���ե�������������R�귵��
		FileHeadSize = Head->Version >= 0x0002 ? sizeof(DARC_FILEHEAD) : sizeof(DARC_FILEHEAD_VER1);
		File = (DARC_FILEHEAD *)(FileP + Dir->FileHeadAddress);
		for (u32 i = 0; i < Dir->FileHeadNum; ++i, File = (DARC_FILEHEAD *)((u8 *)File + FileHeadSize)) {
			// �ǥ��쥯�ȥ꤫�ɤ����ǄI�����
			if (File->Attributes & FILE_ATTRIBUTE_DIRECTORY) {
				// �ǥ��쥯�ȥ�Έ��Ϥ��َ��򤫤���
				DirectoryDecode(NameP, DirP, FileP, Head, 
					(DARC_DIRECTORY * )(DirP + File->DataAddress), pkg, 
					Key, DirPath, dxa_index);
			} else {
				my_dxa_entry_t entry;

				sprintf(entry.name, "%s%s", DirPath, 
					GetOriginalFileName(NameP + File->NameAddress));
				entry.offset = Head->DataStartAddress + File->DataAddress;

				// �ǩ`�����R�s����Ƥ��뤫�ɤ����ǄI�����
				if(Head->Version >= 0x0002 && File->PressDataSize != -1) {
					entry.uncomprlen = File->DataSize;
					entry.comprlen = File->PressDataSize;
				} else {
					entry.uncomprlen = 0;
					entry.comprlen = File->DataSize;
				}
				dxa_index.push_back(entry);
			}
		}
	}
}

/********************* dxa *********************/

/* ���ƥ��ص����� */
static int DXArchive_dxa_match(struct package *pkg)
{
	DARC_HEAD Head;	

	if (pkg->pio->open(pkg, IO_READONLY))
		return -CUI_EOPEN;

	if (pkg->pio->read(pkg, &Head, sizeof(Head))) {
		pkg->pio->close(pkg);
		return -CUI_EREAD;
	}

	u8 *Key = NULL;
	if (strncmp(Head.Head, DXA_HEAD, 2)) {
		Key = (u8 *)malloc(DXA_KEYSTR_LENGTH);
		if (!Key) {
			pkg->pio->close(pkg);
			return -CUI_EMEM;
		}

		KeyCreate(NULL, Key);
		KeyConv(&Head, sizeof(Head), 0, Key);
		if (!strncmp(Head.Head, DXA_HEAD, 2)) {
			//printf("Using default key\n");
			goto ver_check;
		}

		if (pkg->pio->readvec(pkg, &Head, sizeof(Head), 0, IO_SEEK_SET)) {
			free(Key);
			pkg->pio->close(pkg);
			return -CUI_EREADVEC;
		}

		memset(Key, 0xffffffff, DXA_KEYSTR_LENGTH);
		KeyConv(&Head, sizeof(Head), 0, Key);
		if (!strncmp(Head.Head, DXA_HEAD, 2)) {
			//printf("Using default key\n");
			goto ver_check;
		}

		const char *KeyString = get_options("key");
		if (KeyString) {
			if (pkg->pio->readvec(pkg, &Head, sizeof(Head), 0, IO_SEEK_SET)) {
				free(Key);
				pkg->pio->close(pkg);
				return -CUI_EREADVEC;
			}

			KeyCreate(KeyString, Key);
			KeyConv(&Head, sizeof(Head), 0, Key);

			if (!strncmp(Head.Head, DXA_HEAD, 2)) {
				//printf("Using specified key %s\n", KeyString);
				goto ver_check;
			}
		}

		int ret = -CUI_EMATCH;
		for (int k = 0; key_list[k]; k++) {
			if (pkg->pio->readvec(pkg, &Head, sizeof(Head), 0, IO_SEEK_SET)) {
				ret = -CUI_EREADVEC;
				break;
			}

			KeyCreate(key_list[k], Key);
			KeyConv(&Head, sizeof(Head), 0, Key);

			if (!strncmp(Head.Head, DXA_HEAD, 2)) {
				//printf("Using embedded key %s\n", key_list[k]);
				ret = 0;
				break;
			}
		}
		if (ret) {
			free(Key);
			pkg->pio->close(pkg);
			return ret;	
		}
	}

ver_check:
	if (Head.Version > DXA_VER) {
		free(Key);
		pkg->pio->close(pkg);
		return -CUI_EMATCH;
	}

	package_set_private(pkg, Key);

	return 0;	
}

/* �������Ŀ¼��ȡ���� */
static int DXArchive_dxa_extract_directory(struct package *pkg,
										   struct package_directory *pkg_dir)
{
	DARC_HEAD Head;

	if (pkg->pio->readvec(pkg, &Head, sizeof(Head), 0, IO_SEEK_SET)) 
		return -CUI_EREADVEC;

	u8 *Key = (u8 *)package_get_private(pkg);
	KeyConv(&Head, sizeof(Head), 0, Key);

	u8 *HeadBuffer = (u8 *)malloc(Head.HeadSize);
	if (!HeadBuffer)
		return -CUI_EMEM;
		
	// �إå��ѥå��������i���z��
	if (pkg->pio->seek(pkg, Head.FileNameTableStartAddress, IO_SEEK_SET)) {
		free(HeadBuffer);
		return -CUI_ESEEK;
	}

	if (pkg->pio->read(pkg, HeadBuffer, Head.HeadSize)) {
		free(HeadBuffer);
		return -CUI_EREAD;
	}
	KeyConv(HeadBuffer, Head.HeadSize, Head.FileNameTableStartAddress, Key);

	// �����ɥ쥹�򥻥åȤ���
	u8 *NameP = HeadBuffer;
	u8 *FileP = NameP + Head.FileTableStartAddress;
	u8 *DirP = NameP + Head.DirectoryTableStartAddress;

	vector<my_dxa_entry_t> my_dxa_index;

	// ���`�����֤�չ�_���_ʼ����
	DirectoryDecode(NameP, DirP, FileP, &Head, (DARC_DIRECTORY *)DirP, pkg, Key, "", my_dxa_index);
	
	my_dxa_entry_t *index = new my_dxa_entry_t[my_dxa_index.size()];
	if (!index)
		return -CUI_EMEM;

	for (DWORD i = 0; i < my_dxa_index.size(); ++i)
		index[i] = my_dxa_index[i];

	pkg_dir->index_entries = my_dxa_index.size();
	pkg_dir->directory = index;
	pkg_dir->directory_length = sizeof(my_dxa_entry_t) * my_dxa_index.size();
	pkg_dir->index_entry_length = sizeof(my_dxa_entry_t);

	return 0;
}

/* ���������������� */
static int DXArchive_dxa_parse_resource_info(struct package *pkg,
											 struct package_resource *pkg_res)
{
	my_dxa_entry_t *my_dxa_entry;

	my_dxa_entry = (my_dxa_entry_t *)pkg_res->actual_index_entry;
	strcpy(pkg_res->name, my_dxa_entry->name);
	pkg_res->name_length = -1;			/* -1��ʾ������NULL��β */
	pkg_res->raw_data_length = my_dxa_entry->comprlen;
	pkg_res->actual_data_length = my_dxa_entry->uncomprlen;
	pkg_res->offset = my_dxa_entry->offset;

	return 0;
}

/* �����Դ��ȡ���� */
static int DXArchive_dxa_extract_resource(struct package *pkg,
									   struct package_resource *pkg_res)
{
	DWORD comprlen = pkg_res->raw_data_length;
	BYTE *compr = new BYTE[comprlen];
	if (!compr)
		return -CUI_EMEM;

	if (pkg->pio->readvec(pkg, compr, comprlen, pkg_res->offset, IO_SEEK_SET)) {
		delete [] compr;
		return -CUI_EREADVEC;
	}

	u8 *Key = (u8 *)package_get_private(pkg);
	KeyConv(compr, comprlen, pkg_res->offset, Key);

	if (pkg_res->actual_data_length) {
		BYTE *uncompr = new BYTE[pkg_res->actual_data_length];
		if (!uncompr) {
			delete [] compr;
			return -CUI_EMEM;
		}

		// ���
		Decode(compr, uncompr);

		pkg_res->actual_data = uncompr;
	}

	pkg_res->raw_data = compr;

	return 0;
}

/* ��Դ���溯�� */
static int DXArchive_dxa_save_resource(struct resource *res, 
									struct package_resource *pkg_res)
{
	if (res->rio->create(res))
		return -CUI_ECREATE;

	if (pkg_res->actual_data && pkg_res->actual_data_length) {
		if (res->rio->write(res, pkg_res->actual_data, pkg_res->actual_data_length)) {
			res->rio->close(res);
			return -CUI_EWRITE;
		}
	} else if (pkg_res->raw_data && pkg_res->raw_data_length) {
		if (res->rio->write(res, pkg_res->raw_data, pkg_res->raw_data_length)) {
			res->rio->close(res);
			return -CUI_EWRITE;
		}
	}

	res->rio->close(res);
	
	return 0;
}

/* �����Դ�ͷź��� */
static void DXArchive_dxa_release_resource(struct package *pkg, 
										   struct package_resource *pkg_res)
{
	if (pkg_res->actual_data) {
		delete [] pkg_res->actual_data;
		pkg_res->actual_data = NULL;
	}

	if (pkg_res->raw_data) {
		delete [] pkg_res->raw_data;
		pkg_res->raw_data = NULL;
	}
}

/* ���ж�غ��� */
static void DXArchive_dxa_release(struct package *pkg, 
								  struct package_directory *pkg_dir)
{
	void *priv = (void *)package_get_private(pkg);
	if (priv) {
		free(priv);
		package_set_private(pkg, NULL);
	}

	if (pkg_dir->directory) {
		delete [] pkg_dir->directory;
		pkg_dir->directory = NULL;
	}

	pkg->pio->close(pkg);
}

/* �������ص��������� */
static cui_ext_operation DXArchive_dxa_operation = {
	DXArchive_dxa_match,				/* match */
	DXArchive_dxa_extract_directory,	/* extract_directory */
	DXArchive_dxa_parse_resource_info,	/* parse_resource_info */
	DXArchive_dxa_extract_resource,		/* extract_resource */
	DXArchive_dxa_save_resource,		/* save_resource */
	DXArchive_dxa_release_resource,		/* release_resource */
	DXArchive_dxa_release				/* release */
};

/* �ӿں���: ��cui_coreע��֧�ֵķ������ */
int CALLBACK DXArchive_register_cui(struct cui_register_callback *callback)
{
	/* ע��cui���֧�ֵ���չ������Դ������չ��������ص������ͷ������ */
	if (callback->add_extension(callback->cui, _T(".dxa"), NULL, 
		NULL, &DXArchive_dxa_operation, CUI_EXT_FLAG_PKG | CUI_EXT_FLAG_DIR))
			return -1;

	if (callback->add_extension(callback->cui, _T(".hud"), NULL, 
		NULL, &DXArchive_dxa_operation, CUI_EXT_FLAG_PKG | CUI_EXT_FLAG_DIR))
			return -1;

	if (callback->add_extension(callback->cui, _T(".dat"), NULL, 
		NULL, &DXArchive_dxa_operation, CUI_EXT_FLAG_PKG | CUI_EXT_FLAG_DIR))
			return -1;

	return 0;
}
