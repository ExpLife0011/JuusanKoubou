enum
{
    LB_CONTROL_ID_FIRST = DXUT_CONTROL_ID_USER,

    MAIN_TAB,

    QUICK_MSG_ENABLE,
    QUICK_MSG_TIP,

    MONSTER_COUNT_DOWN_ENABLE,
    MONSTER_COUNTDOWN_MINIMAP_SIGNAL,
    MONSTER_COUNTDOWN_SCREEN_SIGNAL,
    MONSTER_COUNTDOWN_TEAM_SIGNAL,
    MONSTER_COUNTDOWN_TIP,

    WARD_ENALBE,
    WARD_SAVE_COUNT,
    WARD_TIP,

    ZOOM_ENABLE,
    ZOOM_TIP,

    TURRET_ENABLE,
    TURRET_TIP,

    QMSG_1,
    QMSG_2,
    QMSG_3,
    QMSG_4,
    QMSG_5,
    QMSG_6,
    QMSG_7,
    QMSG_8,
    QMSG_9,

    LB_CONTROL_ID_LAST,
};

#define TAB_NAME_QUICK_MESSAGE                      L"һ����Ϣ"
#define TAB_NAME_MONSTER_COUNT_DOWN                 L"��Ұ��ʱ"
#define TAB_NAME_WARD_POSITION                      L"��λ����"
#define TAB_NAME_UNLIMITED_ZOOM                     L"��Զ�ӽ�"
#define TAB_NAME_TURRET_COUNT_DOWN                  L"ˮ����ʱ"

#define CTRL_TEXT_QUICK_MSG_ENABLE                  L"����һ����Ϣ"
#define CTRL_TEXT_QUICK_MSG_TIP                     L"������\"~\"��, ����һ����Ϣ���.\n"\
                                                    L"���������Ӧ����Ϣ���ɷ���.\n"\
                                                    L"����\"~\"�Ӷ�Ӧ�����ּ�������Ϣ."

#define CTRL_TEXT_MONSTER_COUNTDOWN_ENABLE          L"���ô�Ұ��ʱ"
#define CTRL_TEXT_MONSTER_COUNTDOWN_MINIMAP_SIGNAL  L"С��ͼ��˸(���Լ��ɼ�)"
#define CTRL_TEXT_MONSTER_COUNTDOWN_SCREEN_SIGNAL   L"��Ļ�м���ʾ"
#define CTRL_TEXT_MONSTER_COUNTDOWN_TEAM_SIGNAL     L"С���Զ�֪ͨ"
#define CTRL_TEXT_MONSTER_COUNTDOWN_TIP             L"���Զ���¼����buff����С��ˢ��ʱ��.\n"\
                                                    L"��Ұ��ˢ��ʱ����Ļ�м������������.\n"\
                                                    L"����F8������ʱ��С����֪ͨ����."

#define CRTL_TEXT_WARD_ENABLE                       L"������λ����"
#define CRTL_TEXT_WARD_SAVE_COUNT                   L"��������ͳ��"
#define CTRL_TEXT_WARD_TIP                          L"���������ͼ����ʾ�۵�λ�ú�ʱ��.\n"\
                                                    L"������F7��M���������ͼ.\n"\
                                                    L"����ͼ�Աߵ�����ͳ�ƶ��Ѳ��۵�����."

#define CRTL_TEXT_ZOOM_ENABLE                       L"���ó�Զ�ӽ�"
#define CTRL_TEXT_ZOOM_TIP                          L"��ͨ�������ָı侵ͷ����.\n"\
                                                    L"��ͨ��F6������/����."

#define CRTL_TEXT_TURRET_ENABLE                     L"���ó�Զ�ӽ�"
#define CTRL_TEXT_TURRET_TIP                        L"�������ͼ����ʾˮ��������ʣ��ʱ��.\n"\
                                                    L"������F7��M���������ͼ."

