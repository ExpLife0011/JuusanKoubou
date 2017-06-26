#ifndef _NAMETABLE_H_
#define _NAMETABLE_H_

#if defined(EF_FD)

enum ECharID
{
    ID_EFFD_INVALID = -1, 
    ID_EFFD_AMEMIYA, ID_EFFD_AKARI,  ID_EFFD_CHIHIRO, ID_EFFD_HIMURA,
    ID_EFFD_HIRO,    ID_EFFD_KEI,    ID_EFFD_KUZE,    ID_EFFD_KYOUSUKE, 
    ID_EFFD_ARISU,   ID_EFFD_MIZUKI, ID_EFFD_MIRAI,   ID_EFFD_MIYAKO,
    ID_EFFD_NAGI,    ID_EFFD_HAYAMA, ID_EFFD_RENJI,   ID_EFFD_SEI, 
    ID_EFFD_SUMIRE,  ID_EFFD_YUUKO
};

SCharNameMap CharName[] =
{
    { "�J�{",   "��m",   "�깬"   },
    { "����",   "����",   "����"   },
    { "��q",   "ǧ��",   "ǧѰ"   },
    { "�[",     "Ϧ",     "Ϧ"     },
    { "�h",     "��",     "��"     },
    { "�i",     "��",     "��"     },
    { "�v��",   "�Þ�",   "����"   },
    { "����",   "����",   "����"   },
    { "�A���X", "���ꥹ", "����˿" },
    { "�~�Y�L", "�ߥ���", "��ϣ"   },
    { "����",   "δ��",   "δ��"   },
    { "�݂₱", "�ߤ䤳", "����"   },
    { "��",     "�M",     "�M"     },
    { "���P",   "ˮ��",   "ˮ��"   },
    { "�@��",   "ɏ��",   "����"   },
    { "��",     "�}",     "ʥ"     },
    { "���݂�", "���ߤ�", "��"     },
    { "�D�q",   "����",   "����"   },
};

SCharNameHashMap NameHash[] =
{
    { 0x281124FA, 0xA811E9EE, 0xA817492F },
    { 0xF812ABA0, 0xDC18616C, 0xDC18616C },
    { 0x9C124872, 0x9C11E326, 0x9C1A4332 },
    { 0x0012E05B, 0x0019E0A6, 0x0019E0A6 },
    { 0x0011A068, 0x00178087, 0x00180080 },
    { 0x00118069, 0x0017C0B0, 0x0017C0B0 },
    { 0xD8124522, 0x0C139F82, 0x0C1CDFFD },
    { 0x7811656C, 0xA417FFEB, 0xA417FFEB },
    { 0x2C0020DC, 0xA234F370, 0xD2F901DC },
    { 0x63F020CB, 0xE5E4F365, 0xC01984A0 },
    { 0x8812AB8A, 0xD01867B6, 0xD01867B6 },
    { 0x85C000B6, 0x9DE4D3F8, 0xB01ABC51 },
    { 0x001260E2, 0x0010804D, 0x0010804D },
    { 0x1412E852, 0xB8112528, 0xB817E525 },
    { 0x00118CA0, 0x3C1AA44C, 0xAC1AA04C },
    { 0x001200B9, 0x0018407D, 0x001940A5 },
    { 0x7F6000ED, 0x7784D3A7, 0x001BA0C0 },
    { 0x10118BF0, 0x781AA151, 0x141A8950 },
};

#elif defined(EDEN)

enum ECharID
{
    ID_EDEN_INVALID = -1, 
    ID_EDEN_RYO,   ID_EDEN_SION, ID_EDEN_RAVI, ID_EDEN_ERIKA, ID_EDEN_NATSUME, 
    ID_EDEN_INABA, ID_EDEN_MAYA, 
};

SCharNameMap CharName[] =
{
    { "��",     "��",     "��",     },
    { "�V�I��", "������", "ʫ��",   },
    { "�����B", "�����", "��ά",   },
    { "�G���J", "���ꥫ", "����", },
    { "�i�c��", "�ʥĥ�", "��Ŀ",   },
    { "��t",   "�R�~",   "��Ҷ",   },
    { "�^��",   "��ҹ",   "��ҹ",   },
};

SCharNameHashMap NameHash[] = 
{
    { 0x0012E0BA, 0x001820C1, 0x001820C1 },
    { 0x21702014, 0xA364F33B, 0xAC1A25F6 },
    { 0x588020C6, 0xDE84F36A, 0xB419A0AE },
    { 0x2C6020CE, 0xA294F362, 0xC2D781CB },
    { 0x8A802006, 0x1CB4F328, 0x1018E73C },
    { 0xB812A477, 0x48195BFF, 0xF81A1A34 },
    { 0x781288E8, 0x981A2A3A, 0x981A2A3A },
};

#elif defined(EF_FIRST)

enum ECharID
{
    ID_EFFD_INVALID = -1, 
    ID_EFF_CHIHIRO,  ID_EFF_HIMURA, ID_EFF_HIRO,   ID_EFF_IZUMI, ID_EFL_KEI,
    ID_EFF_KYOUSUKE, ID_EFF_MIZUKI, ID_EFF_MIYAKO, ID_EFF_MOM,   ID_EFF_NAGI,
    ID_EFF_OOMURA,   ID_EFF_YUUKO,
};

SCharNameMap CharName[] =
{
    { "��q",   "ǧ��",   "ǧѰ"   },
    { "�[",     "Ϧ",     "Ϧ"     },
    { "�h",     "��",     "��"     },
    { "��",     "Ȫ",     "Ȫ"     },
    { "�i",     "��",     "��"     },
    { "����",   "����",   "����"   },
    { "�~�Y�L", "�ߥ���", "��ϣ"   },
    { "�݂₱", "�ߤ䤳", "����"   },
    { "��",     "ĸ",     "ĸ"     },
    { "��",     "�M",     "�M"     },
    { "�呺",   "���",   "���"   },
    { "�D�q",   "����",   "����"   },
};

SCharNameHashMap NameHash[] =
{
    { 0x9C124872, 0x9C11E326, 0x9C1A4332 },
    { 0x0012E05B, 0x0019E0A6, 0x0019E0A6 },
    { 0x0011A068, 0x00178087, 0x00180080 },
    { 0x001200F2, 0x001900AA, 0x001900AA },
    { 0x00118069, 0x0017C0B0, 0x0017C0B0 },
    { 0x7811656C, 0xA417FFEB, 0xA417FFEB },
    { 0x63F020CB, 0xE5E4F365, 0xC01984A0 },
    { 0x85C000B6, 0x9DE4D3F8, 0xB01ABC51 },
    { 0x0012A0EA, 0x001880B8, 0x001880B8 },
    { 0x001260E2, 0x0010804D, 0x0010804D },
    { 0x94126839, 0xCC16DAE6, 0xCC16DAE6 },
    { 0x10118BF0, 0x781AA151, 0x141A8950 },
};

#elif defined(EF_LATTER)

enum ECharID
{
    ID_EFFD_INVALID = -1, 
    ID_EFL_AKANE, ID_EFL_AMEMIYA, ID_EFL_CHIHIRO, ID_EFL_HIMURA,  ID_EFL_KEI,
    ID_EFL_KUZE,  ID_EFL_MIZUKI,  ID_EFL_MIRAI,   ID_EFL_NAGI,    ID_EFL_HAYAMA,
    ID_EFL_RENJI, ID_EFL_SUMIRE,  ID_EFL_YUUKO,   ID_EFL_ONNANOKO,
};

SCharNameMap CharName[] =
{
    { "��",     "��",     "��",    },
    { "�J�{",   "��m",   "�깬"   },
    { "��q",   "ǧ��",   "ǧѰ"   },
    { "�[",     "Ϧ",     "Ϧ"     },
    { "�i",     "��",     "��"     },
    { "�v��",   "�Þ�",   "����"   },
    { "�~�Y�L", "�ߥ���", "��ϣ"   },
    { "����",   "δ��",   "δ��"   },
    { "��",     "�M",     "�M"     },
    { "���P",   "ˮ��",   "ˮ��"   },
    { "�@��",   "ɏ��",   "����"   },
    { "���݂�", "���ߤ�", "��"     },
    { "�D�q",   "����",   "����"   },
    { "���̎q", "Ů����", "Ů����" },
};

SCharNameHashMap NameHash[] =
{
    { 0x001100A9, 0x001B80E7, 0x001B80E7 },
    { 0x281124FA, 0xA811E9EE, 0xA817492F },
    { 0x9C124872, 0x9C11E326, 0x9C1A4332 },
    { 0x0012E05B, 0x0019E0A6, 0x0019E0A6 },
    { 0x00118069, 0x0017C0B0, 0x0017C0B0 },
    { 0xD8124522, 0x0C139F82, 0x0C1CDFFD },
    { 0x63F020CB, 0xE5E4F365, 0xC01984A0 },
    { 0x8812AB8A, 0xD01867B6, 0xD01867B6 },
    { 0x001260E2, 0x0010804D, 0x0010804D },
    { 0x1412E852, 0xB8112528, 0xB817E525 },
    { 0x00118CA0, 0x3C1AA44C, 0xAC1AA04C },
    { 0x7F6000ED, 0x7784D3A7, 0x001BA0C0 },
    { 0x10118BF0, 0x781AA151, 0x141A8950 },
    { 0x3961806C, 0x32FAB35A, 0x82FABC5B },
};

#endif

#endif /* _NAMETABLE_H_ */