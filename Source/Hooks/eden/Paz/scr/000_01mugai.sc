; �ե�����: 000_01.txt

;����Ӱ�����å�
;�������`������o�����Є����ˤ��륹����ץȡ�
;����Σ�ʤ��ΤǱؤ����åȤ�ʹ�����ȣ�
;��----------------------------------------------
;.pragma disable_control
;.pragma enable_control
;��----------------------------------------------


;;����Ӱ�����å�
;;�������L�äη�᪥�����ץ�����
;;��----------------------------------------------
.if ef_000 == 1 ef_000_b1
.if ef_000 <= 0 ef_000_a1
;
.label ef_000_a1

;����Ӱ�����å�
;�������`�����o��
.pragma disable_control

.goto ef_000_b1
.end
;
.label ef_000_b1
;;��----------------------------------------------




.setGlobal EYE_SEQ_DEFAULT = 2


.wait 200
.effect Snow
.wait 100




;.transition 0 * 50
;.stage	* BLACK.png 0 0
.wait 80
;������
;�֤�ȫ����ҹ�����饹���`�Ȥ��ʡ�
;.transition 0 * 10
;.transition 0 * 15
;.stage	* BLACK.png 0 0
.wait 200
;.stage	* ef_tero_a_1.png 0 0
.panel 3
.message	100	yuk-000_01-0003	#�D�@�q	������˭��������������ʱ��\v\a
.transition 0 * 10
.stage	* BLACK.png 0 0
.message	110	yuk-000_01-0005	#�D�@�q	\a���������������Ҳ��Ȼ����ȫ��ȫ��ȥ������һ�̡�\a\v
;.wait 50
;.transition 0 * 10
.transition 0 * 15
.stage	* BLACK.png 0 0
.message	120	yuk-000_01-0007	#�D�@�q	\a˭����ȥѰ��֮�\v\a
;.transition 0 * 10
.transition 0 * 20
.stage	* BLACK.png 0 0
.message	130	yuk-000_01-0009	#�D�@�q	\a˭����ȥ����֮�\v\a
;.wait 50
;.transition 0 * 10
.transition 0 * 15
.stage	* BLACK.png 0 0
.message	140	yuk-000_01-0011	#�D�@�q	\a���˫�֣���Ҫ���֮�\v\a
;.wait 50

;��ζ�Ϥ��Ĥ�2�Ĥ˷֤���ΤϤޤ����Τ����� 5b��ͬ�� nbkz 2006/04/12
;.transition 0 * 10
;.stage	* ef_tero_a_5c.png 0 0
;.wait 450

;.transition 0 * 10
.transition 0 * 15
.stage	* BLACK.png 0 0
.message	150	yuk-000_01-0013	#�D�@�q	\a�޾���˼���У��������˵������֮�\v\a
;.wait 250
.transition 0 * 10
.stage	* BLACK.png 0 0
;.wait 200
;.transition 0 * 10
.transition 0 * 30
.stage	* BLACK.png 0 0
.message	160	yuk-000_01-0015	#�D�@�q	\a�ǡ�һ���ǩ���\v\a
.wait 300
.effect fadeout
;.wait 150

;����Ӱ�����å�
;.wait 100
.wait 20


;.effect SnowH
.transition 0 * 10
;.stage	* WHITE.png 0 0

.stage	* BLACK.png 0 0




;�Ȥꤢ�������񻯤����ΤǤϤ����Ƥ���ޤ��� nbkz 2006/04/12
.panel 3
;.stage	* ef_tero_a_1.png 0 0
;.message	100		#�D�@�q	�l�⤬һ�Ȥ��񘔤���ä����Ȥ������˼����
;.stage	* ef_tero_a_2.png 0 0
;.message	110		#�D�@�q	���Ȥ��Τ��Ť��Ƥ��ʤ��Ƥ⣬�ޤä������Ĥ������������դ����Ĥ��ؤ���äƤ��롣
;.stage	* ef_tero_a_3b.png 0 0
;.message	120		#�D�@�q	�l�⤬̽���Ƥ����Ρ�
;.stage	* ef_tero_a_3c.png 0 0
;.message	130		#�D�@�q	�l�⤬���Ƥ����Ρ�
;.stage	* ef_tero_a_4.png 0 0
;.message	140		#�D�@�q	�֤���Ф����Ĥ���ȡ���Ȥ��뤽��ϡ�
;.stage	* ef_tero_a_5.png 0 0
;.message	150		#�D�@�q	�ᤰ���뤤�ȣ��ˡ��νO��������������Ȥˤ��뤽��ϡ�
;.stage	* ef_tero_a_6.png 0 0
;.message	160		#�D�@�q	����Ϥ��äȩ���




;���̻��ڣ������������������r
;�������������Ϧ����˽������
;������������m���ӣ�˽������
.panel 0
.transition 0 * 20
.stage	* BLACK.png 0 0
;�����������Q�餹�g�δ_���Τ��ᣬ�虜���\�Ϥ���Ǥޤ����ե��`�ɥ��ԩ`�ɤ�40����������
.playSE kyoukai_door.ogg f 0 *
.transition 0 * 20
.stage	vista_window2.png ev00_001a01_mugai_a.png 0 0
.effect *
.panel 3
;.panel 1
.message	170			\a�����������������ƿ��ǵ����ص��š�
.wait 250
.playSE2 yuka.ogg f 0 *
.message	180			\a̤���˲�䣬һ˲��е�������ĺ��䡣
.wait 300
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_001a01_mugai_a.png 0 0
;.stage	* ev00_001a01_mugai_a.png 0 0
.vscroll	1200	10
.endScroll f
.playSE2 *
.panel 3
.message	190			\a������ɫ����Ϣ����������ļ�̳��
.wait 270
.message	200			\aӦ������Ϥ�ò�������Ϥ�ĳ�����
.wait 260
.message	210			\aȻ����Ŀǰȴ�ǲ����ܳ��ֵĹ⾰��
.wait 270
.message	220			\a�ҵ�����ʲôʱ�򡭡���
.wait 250
.message	230			\a�������������������ˡ�
.wait 320
;nbkz׷��
.stage * BLACK.png 0 0
.panel 0
.wait 50
.stage	* planner.png 0 0
.message	231			\a��
.wait 200
.stage	vista_window2.png ev00_001b01.png 0 600
.transition 0 * 5
.panel 3
.message	240	yuk-000_01-0017	#�D�@�q	\a��������\a\v
.wait 100
.panel 3
.message	250			\a��̳ǰ����Ů����ת��������
.wait 280
.panel 3
.message	260	yuk-000_01-0019	#�D�@�q	\a�����Ϻá�\a\v
.wait 100
.transition 0 * 20
.stage	vista_window2.png prologue_mugai_h3.png 0 0
;.stage	vista_window2.png prologue_mugai_j.png 0 0
.panel 3
.message	270			\a����Ů�����峺��Ц�ݣ�΢΢����һ��ͷ��
.wait 300
.transition 0 * 20
.stage	vista_window2.png prologue_mugai_h.png 0 0
;.stage	vista_window2.png prologue_mugai_e.png 0 0
;.transition 0 * 20
;.stage	vista_window2.png prologue_mugai_f.png 0 0
.message	280			\a��ͷ����Ҳ�������������Ĳ��ơ�
.wait 280
.panel 0
.transition 0 * 20
.stage	vista_window2.png prologue_mugai_e.png 0 0
;.stage	vista_window2.png prologue_mugai_f.png 0 0
.panel 3
.message	290	him-000_01-0003	#�@�[�@	\a������������\a\v
.wait 100
.panel 3
.message	300			\a�ؿ��б��ս������ʹ��
.wait 280
.message	310			\a��������Զ����������������������������
.wait 290
.message	320			\aÿһ��ÿһ�ﶼ�������Ͷ��ö�������
.wait 260
.message	330	him-000_01-0005	#�@�[�@	\a������Ӵ��\a\v
.wait 100
.panel 3
.message	340			\a�þ�ȫ�������ż���һ�仰��
.wait 260
.message	350			\a�����������ں����Ի������ʵ��
.wait 290
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_002a01_mugai_a_vista.png 0 0
.panel 3
.message	360	yuk-000_01-0021	#�D�@�q	\a����������Ŷ������Ӧ���ǩ�����\a\v
;.wait 200
.panel 0
;nbkz׷�� 2006/04/07
.stage * BLACK.png 0 0
.transition 0 * 20
.wait 50
.stage	* os_sp.png 0 0
.message	361			\a��
.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_002a03_mugai_c.png 0 0
.panel 3
.message	370	yuk-000_01-0023	#�D�@�q	\a��ʥ�����֡��Ŷ��ء�\a\v
.wait 100
.panel 3
.message	380			\a��վ�����賓�������ź���ʱ��һ����Ц�ݡ�
.wait 270
.transition 0 * 20
.stage	vista_window2.png ev00_002a03_mugai_b.png 0 0
;���������������ꐙ���ݤ�����Τǣ��Ф�����ǥե��`�ɤ����Ƥޤ���
.message	390			\a�����ξ����ѹ���֡�
.wait 270
.message	400	him-000_01-0007	#�@�[�@	\a������ʥ�����֡�\a\v
.wait 100
;.wait 200
.panel 3
.message	410			\a�������������̴��к���ʱ��
.wait 240
.message	420			\a�����и���Ҫ�Ļ������ò�˵�Ļ���
.wait 240
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_002a01.png 0 250
.panel 3
.message	430	yuk-000_01-0025	#�D�@�q	\a��������ʥ���ڡ���ȴ��һ�����𣿡�\v
.wait 100
;.wait 300
.message	440	him-000_01-0009	#�@�[�@	\a��������һ���˹�ʥ�����Ѿ��ܶ����ˡ�����\v
;.wait 300
.transition 0 * 20
.stage	vista_window2.png ev00_002a03.png 0 250
.message	450	yuk-000_01-0027	#�D�@�q	\a����ѽ�������Ǽ�į�����ء�\a\v
;.wait 200
.message	460	yuk-000_01-0029	#�D�@�q	\a������˵������Ҳ����һ�����ء�\a\v
.wait 100
.message	470	him-000_01-0011	#�@�[�@	\a����ô������\a\v
.wait 100
.message	480	him-000_01-0013	#�@�[�@	\a��������ԵĻ���������΢�����𣿡�\a\v
;.wait 50
;.wait 100
.wait 80
.message	490	yuk-000_01-0031	#�D�@�q	\a���ţ�ʮ�����⡹\a\v
.wait 100
;nbkz׷�� 2006/04/07
.stage * BLACK.png 0 0
.transition 0 * 20
.panel 0
.wait 50
.stage	* cd.png 0 0
.message	491			\a��
.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_002a02.png 0 250
.panel 3
.message	500	yuk-000_01-0033	#�D�@�q	\a��ʮ�����⡭����\a\v
.wait 100
.panel 3
.message	510			\a����Ů��Ц�ݣ�����֮������������
.wait 260
.message	520	yuk-000_01-0035	#�D�@�q	\a���þò������ء�����\a\v
.wait 100
.message	530	him-000_01-0015	#�@�[�@	\a������һֱ����\a\v
;.wait 100
.wait 85
.message	540	him-000_01-0017	#�@�[�@	\a��������˺ܾ��˰���\a\v
.wait 100
.panel 3
.message	550			\a��������Ҳ����ν��
.wait 200
.message	560	yuk-000_01-0037	#�D�@�q	\a���ţ�������û��\a\v
;.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_002a01.png 0 250
.message	570	yuk-000_01-0039	#�D�@�q	\a����΢������\a\v
.wait 100
;.transition 0 * 20
;.stage	vista_window2.png ev00_002a02.png 0 250
;�mugai�Щ`�Τߤ���Ҏ��
.message	580	yuk-000_01-0041	#�D�@�q	\a����΢�ȵ���Щ�����ء�\a\v
;.wait 200
.wait 60
.message	590	him-000_01-0019	#�@�[�@	\a������\a\v
;.wait 200
.panel 3
.message	600			\aֻҪ������վ���ҵ���ǰ����
.wait 220
.message	610	him-000_01-0021	#�@�[�@	\a�����Ǳ�Ǹ�أ����ӡ�\a\v
;.wait 200
.transition 0 * 20
.stage	vista_window2.png prologue_mugai_g.png 0 0
.panel 3
.message	620			\a��ʵ���������ȵ�̫���ˡ�
.wait 260
.message	630	him-000_01-0023	#�@�[�@	\a�����ӣ�����ǡ�����\a\v
;.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_002a01_mugai02.png 0 0
;.stage	vista_window2.png ev00_002a01_mugai_b.png 0 0
;�mugai�Щ`�Τߤ���Ҏ��
.message	640	yuk-000_01-0043	#�D�@�q	\a�����ǡ�����\a\v
.wait 100
;nbkz׷�� 2006/04/07
.stage * BLACK.png 0 0
.transition 0 * 20
.panel 0
.wait 50
.stage	* color.png 0 0
.message	641			\a��
.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_002a01_mugai01_close.png 0 0
;��g�H��Ŀ�]���Щ`�򣡣�
;.transition 0 * 20
;.stage	vista_window2.png ev00_002a01_close.png 0 250
;.panel 3

;����Ӱ�����å�
;�������줬�����ʡ��������ȥ����ȡ�
;��------------------------------------------------------------
;.message	650	him-000_01-0025	#�@�[�@	��������\v\a
;.wait 100
;.panel 3
;.message	660			��Ů�Ϥʤˤ������z��褦���˲ݤ򤹤롣\a
;.wait 220
;.panel 0
;��------------------------------------------------------------


.panel 3
.message	670	yuk-000_01-0045	#�D�@�q	����塭����\v\a
;.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_002a01_mugai01.png 0 0
;.stage	vista_window2.png ev00_002a01.png 0 250
.message	680	yuk-000_01-0047	#�D�@�q	����壬Ϧ������û��ɡ�\v\a
;.wait 200
.panel 3
.message	690			Ŀ�������ڵȴ�����ߵĻش�\a
.wait 230
.message	700			�ѵ�˵������\a
.wait 190
.message	710	him-000_01-0027	#�@�[�@	�������������ҵ��������𣿡�\v\a
;.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_002a03_mugai01.png 0 0
;.stage	vista_window2.png ev00_002a03.png 0 250
.message	720	yuk-000_01-0049	#�D�@�q	���ţ���ʵ�ء�\v\a
;.wait 200
.panel 3
.message	730			�������Ц��������\a
.wait 200
.message	740			������������𣿻��ǡ�������һʱ����ء�\a
.wait 270
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_002a02_mugai01.png 0 0
;.stage	vista_window2.png ev00_002a02.png 0 250
.panel 3
.message	750	yuk-000_01-0051	#�D�@�q	�����ڸղš����ڸղţ��������ˡ�\v\a
.wait 100
;.wait 150
;.wait 300
.message	760	yuk-000_01-0053	#�D�@�q	�������ӡ��ܸо�����ʱ�����෴�ء�\v\a
;.wait 300
.transition 0 * 20
.stage	vista_window2.png prologue_mugai_c.png 0 0
.panel 3
.message	770			����䣬�����糱���������ϡ�\a
.wait 200
.transition 0 * 20
.stage	vista_window2.png prologue_mugai_d.png 0 0
.message	780			���Ƕ��ټ����ֻ�֮ǰ����ĳһ��Ϧ���µĻ��䡣\a
.wait 250
;nbkz׷�� 2006/04/07
.stage * BLACK.png 0 0
.transition 0 * 20
.panel 0
.wait 50
.stage	* music.png 0 0
.message	781			\a��
.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_003_vista.png 0 0
.panel 3
.message	790	him-000_01-0029	#�@�[�@	��������û������\v\a
;.wait 200
.wait 70
.message	800	him-000_01-0031	#�@�[�@	�������ٻ��ˣ����Ǹ����ա�\v\a
;.wait 300
;.transition 0 * 20
;.stage	vista_window2.png prologue_mugai_i2.png 0 0
.panel 3
.message	810			�ԣ����Ǹ����졣\a
.wait 220
.transition 0 * 20
.stage	vista_window2.png prologue_mugai_j.png 0 0
.message	820			�Ǹ��������ӵ����졣\a
.wait 230
.message	830			�Ǹ�������һ����֪�����졣\a
.wait 250
.transition 0 * 20
.stage	vista_window2.png prologue_mugai_i2.png 0 0
.message	840			�Ǹ���Ҳ��������ģ��Һ��������졭����\a
.wait 280
.panel 0
.transition 0 * 10
.stage	* WHITE.png 0 0








.wait 30
;�����륹���`��
;��500_01���
;��������ѧ�@�����£��ģ������r
;�������������Ϧ�����Ʒ����ģ�
;������������m���ӣ��Ʒ�������
;.playBGM BGM016_sample.ogg
.transition 0 * 10
.stage	* bgc_sch002a01_02_pastm3.png 0 0
.panel 1


;����Ӱ�����å�
;�������`�����Є���
.pragma enable_control


.message	850			������ͼ��ݵ�ѧϰ���������ȡ�
.transition 0 * 20
.stage	* bgc_sch002a01_02_pastm2.png 0 0
.message	860			���ܾ���������������Ӱ����������
.transition 0 * 20
.stage	* bgc_sch002a01_02_pastm.png 0 0
.message	870			ƽʱӦ�û��в��Ż��ίԱ�Ṥ����ѧ���ڵģ�Ϊʲô������˰����ء�
.message	880			���Լ����������������˳Ծ���
;.message	890			�Ĥ��ղ�������z������¤�Ϧĺ��ˤʤäƤ⣬��ݤ������ʤ���
.message	890			����������������ȣ��ڰ�����Ȼ���ܲ������⡣
.message	900			���������Ŷ��ѣ����Ѿ�����䤱���
;���գ�Ϧĺ�죩
;.playSE higurashi.ogg f 0 *
.transition 0 * 20
;.stage	* sky_pastm_a.png 0 0
.stage	past_window.png bgs_sch009a01_02.png 0 0
;���Ĥ�У�h�˲�椨�Τ��ȣ�
.message	910			����ѥ�ӣ��߳���ѧ¥��
.message	920			��Ҳ��������������������ȵĿ�������ȫ��
.message	930			�ٴ����ҷ��������������������ʵ��
.message	940			�Ҳ����������졣
.message	950			���������Ķ��죬�����ҵ��������������ɫ�͹�â�ļ��ڵ����ɡ�
.message	960			�������ᣬ��
.message	970			�ҷ���������ˡ�
.message	980			����ֻ�ᱻ�ҷ�Ϊ�����������������ֶ��ѡ�
.message	990			��Ʋ����ǽ�ȫ�����淽ʽ�������Ҷ��Կ�Ц������
.message	1000			���淽ʽ����
;.playSE *
.transition 0 * 20
.stage	past_window.png ev00_004_mugai_h2.png 781 1037
;.stage	past_window.png ev00_004_mugai_h4.png 1121 1457
.message	1010			������ա�
.message	1020			����ϣ�������淽ʽ�ǩ���
.message	1030		�@�[�@	������ʲô��������
.transition 0 * 20
;.stage	past_window.png ev00_004_mugai_h4.png 1121 1457
;.scroll	781 1037	6
.stage	past_window.png ev00_004_mugai_h2.png 781 1037
.scroll	581 837	6
.endScroll f
.message	1040			����Ϧ��Ⱦ�����գ�һƬϸС�İ�ɫ�����趯��
.transition 0 * 20
.stage	* ev00_004.png 0 0
.message	1050			���ǡ���һ��ֽ�ɻ���
.message	1060		�@�[�@	������ı����ӳ����ġ�
;.transition 0 * 20
.transition 0 * 10
.stage	* ev00_005.png 0 0
.message	1070			������Ʈ���ڵص�ֽ�ɻ���
;����ԣ������У����w�ЙC��֤ä�Ϧ����Ԫ�Σãǡ�
.message	1080			�������ˣ�����ѧУ�ﻹ�����ĸ��������������Ķ�����
.transition 0 * 20
.stage	* ev00_006_mugai_d.png 0 600
.message	1090			�Ҵ���Щ��ľ��ȣ���ʼһ������ȷ�Ͻ�ѧ¥�Ĵ�����
.transition 0 * 20
.stage	* ev00_006_mugai_d.png 0 600
.vscroll	0	-10
.endScroll f
.message	1100			������Ϊ���˿����Ѿ����ڵ�ʱ�򡭡���
.message	1110		�@�[�@	����������
;�盧���������Ϥ��¤���Ҋ�Ϥ����h����
.transition 0 * 20
.stage	* ev00_006_mugai_a.png 0 0
.message	1120			һ����Ů����Ӱ���������ҵ����ߡ�
.message	1130			���Ҳ�֪Ϊ�Σ���Ů�������ݶ��ı�Ե������ҡ�����Լ���˫�㡣
.transition 0 * 20
.stage	* ev00_006.png 0 0
.message	1140			�����ֵط���ʲô�ء�
.message	1150			���������������
.message	1160			���������ʽ���ӿ����ʱ��ͻȻ��
.message	1170			��Ȼ��Զ����ȴ����ؿ����ˡ�
.message	1180			��Ů��ֹͣ�˽ŵĻζ����������·����ҩ���΢Ц������


;�����ϣ��ģ������r
;�������������Ϧ�����Ʒ����ģ�
;������������m���ӣ��Ʒ����ģ�
.transition 0 * 10
.stage	* bgs_sky001a01_02_mugai_a.png 0 0
.message	1190			�������ţ���ս��ķ·��ֿɼ���
.message	1200			���޵�糺�ɫ���쵽������������Ϧ�����ϱ�����½������ȼ���Ĵ����
.message	1210			����Ūʹ�۾����ɫ֮�Щ���
.transition 0 * 10
.stage	* ev00_007a01_mugai_a.png 0 0
.message	1220			��Ů��΢Ц�š�
.transition 0 * 20
.stage	* ev00_007a02.png 0 0
.message	1230		�@�[�@	������Ϊʲô�Ƕ�������
.message	1240			��Ȼ����õ�̨�ʲ�ͬ����֮�������ʹ�ȥ��
.message	1250			����˵���޷�˵��ʲô�ʺϵĻ��
.message	1260			��ǰ�Ĺ⾰��������������ʧȥ��ʵ�С�
.message	1270			������Ȼ�ǵ�һ�������ݶ�������Ȼ���ڵ�դ��ȴû��Ҳ�������гԾ���
.transition 0 * 40
.stage	* ev00_007a03.png 0 0
.message	1280	yuk-000_01-0055	@�D�@�q	����������
.message	1290			����ǿ�ҵĲ�Э��������Ⱦ���ľ�ɫ�У�������Ů����һ��ͷ��
.message	1300		�@�[�@	���㴩�Ĳ��Ƕ�����
.message	1310		�@�[�@	�����ǲ�֪��ʲô�������·��أ���
.transition 0 * 40
.stage	* ev00_007a01.png 0 0
;���¤�02����ˤ��룿04��ʹ���ɤ���⤷�ä��꿼���Ƥ������ȣ�
.message	1320	yuk-000_01-0057	@�D�@�q	������������·��������ķ�Ŷ��
.message	1330		�@�[�@	��������
.message	1340			�����·�����ô����������ѧ԰�Ķ�����
.message	1350			����������ʵʵ�������˾�����ֵ��������׶����š�
.transition 0 * 40
.stage	* ev00_007a02.png 0 0
.message	1360	yuk-000_01-0059	@�D�@�q	�����촩���·��Ž��·����������촩���������ķ��������𣿣���
.message	1370		�@�[�@	����ȫ���Եİɡ�����
.message	1380			�����ǲ����ó���˵���ˡ�
.transition 0 * 40
.stage	* ev00_007a01.png 0 0
.message	1390	yuk-000_01-0061	@�D�@�q	��������������Ȼż���ᱻ��˵�����ž;����ȵ����ܡ�����
.message	1400			������˵Ҳ��������Ȼ�İɡ�
.message	1410			���������ȵ�ʱ���ﴩ�������·�����Ȼ�����˾��ò��ʡ�
.transition 0 * 40
.stage	* ev00_007a02.png 0 0
.message	1420	yuk-000_01-0063	@�D�@�q	����̫�봩���䡹
.message	1430	yuk-000_01-0065	@�D�@�q	����ǰ����΢������Щ���ء�
.message	1440			��һ��˵�ţ������·����ḧĦ�Լ�������
.message	1450	yuk-000_01-0067	@�D�@�q	����ʱ�Ǿ�������ν���������ڵ���΢�����Ͱ�������
.message	1460		�@�[�@	���ҵ�Ҳû��׷�ʷ�����ʲô����˼��
.message	1470			��������Ů������˼������������Ļ���
.message	1480			����ǣ�С���ӵ�ʱ���ܹ��˶����µĴ��ڰɡ�
.message	1490			�������͵�Ů�����������˿ڲ��뱻����Ҳ�޿ɺ�ǡ�
.message	1500			���̶ֳȵ������һ��Ƕ��ģ��������濴�����Ļ�����
.message	1510			��Ů�����Ŷ��������ֲ���˼����ʺϸС�
.message	1520			��Ȼ�������Ļ��ҿɲ���˵���ڡ�
;����Ӱ�����å�
;��������仯���롣
.transition 0 * 40
.stage	* ev00_007a01.png 0 0
.message	1530	yuk-000_01-0069	@�D�@�q	��˵������������ר��Ϊ��˵���俴�������ȶ����İɣ���
.message	1540		�@�[�@	����ô���ܡ�
.message	1550			��ҡ��ҡͷ�������˱�����Ŀ�ġ�
.transition 0 * 20
.stage	* ev00_008a01.png 0 0
.message	1560		�@�[�@	����˵�㣬�ݶ��ǽ�ֹ����İ���
.message	1570			����Ӧ���Ǳ���ס�ĲŶԣ���ΰ����򿪵�Ҳ��һ���ԡ�
.transition 0 * 40
.stage	* ev00_008a02.png 0 0
.message	1580	yuk-000_01-0071	@�D�@�q	���㲻��Ҳ��������
.message	1590			��Ů¶������ִ�ֵ����顣
.message	1600		�@�[�@	��������������ġ��ɱ𳶿�����Ŷ��
.transition 0 * 40
.stage	* ev00_008a03.png 0 0
.message	1610	yuk-000_01-0073	@�D�@�q	�����˿������ǵ�һ���ء���ϧ����ϧ��
.message	1620			������ȫû����Ҫ˵��Ϊʲô��ϧ����˼��
.message	1630		�@�[�@	�������Ҳ��ǽ�ʦ��������ô�����ģ���
;.message	1640			����ѧ�@�����Ϥ���������ֹ�����Ȥ�����꣬��ѧ���Ƥ����g��������Ϥ⤦���Ϥδ��ڤ�������Ƥ��ޤ��Τ���ͨ������
.message	1640			����ѧ԰���ݶ���ֹ������멤����Ȼ��ô˵��������ѧ֮�����˵����£������ݶ��Ĵ��ں������ɡ�
.message	1650			�������˵����ط�ѧ����Ӧ�ò���Ϥ�Ŷԡ�
.transition 0 * 40
.stage	* ev00_008a01.png 0 0
.message	1660	yuk-000_01-0075	@�D�@�q	�����������������
.message	1670	yuk-000_01-0077	@�D�@�q	���������Ĳ�ԱŶ��ӵ���ر���Խ����ݶ�����ɡ�
.message	1680		�@�[�@	��Ҫ���ѵĻ���Ҳ��Щ�������ĳ�����
.message	1690		�@�[�@	��������ʱ����ô�ܿ���ʲô���ǡ���˵������ѧУ�����Ĳ��𣿡�
.message	1700			����ȥ�Ļ���Ҳû����������Զ��֮������ߡ�
.transition 0 * 40
.stage	* ev00_008a03.png 0 0
.message	1710	yuk-000_01-0079	@�D�@�q	����Ȼ�а���ֻ�ǣ�������ϲ��˶��ѡ�
.message	1720		�@�[�@	���ϲ�����
.transition 0 * 40
.stage	* ev00_008a04.png 0 0
.message	1730	yuk-000_01-0081	@�D�@�q	���ţ�3�꼶��ǰ������һ�������ˡ�û��2�꼶�Ĳ�Ա��ʣ�µ�ֻ��1�꼶���Ҷ��ѡ�
.message	1740		�@�[�@	��ֻ��1�꼶����
.message	1750			��Ȼ���ף������ŮӦ�����ҵĺ󱲡�
.message	1760			��ֱ�۵Ŀ������������Ʊ���С3��4�ꡣ
.transition 0 * 40
.stage	* ev00_008a03.png 0 0
.message	1770	yuk-000_01-0083	@�D�@�q	����Ȼ�һ�����᲻������������ʱ�벿�ء�����ϧ�������û��ôһ����˳����
.message	1780		�@�[�@	��ֻ��һ���˵Ļ�ȷʵû����ʲô����Ȼ�ź�����Ҳ��û�취���¡�
.message	1790			������˵�ź��޸���Ļ���
;.message	1800			����ϣ������Ǥ�����ʤ�Ԓ�ˤ⤴����ͨ����Ť����餤���Ƥ�褦�ˤʤä�����������ǷǤϤȤ⤫����
.message	1800			����������Ǽ������ĵĻ���Ҳ����ͨ��������Ӧ�������Ǻ��ǻ����Ҳ��ۡ�
.transition 0 * 40
.stage	* ev00_008a01.png 0 0
.message	1810	yuk-000_01-0085	@�D�@�q	���ǰ���û�취�������ء�
.transition 0 * 40
.stage	* ev00_008a04.png 0 0
.message	1820	yuk-000_01-0087	@�D�@�q	�������ء�����
.transition 0 * 20
.stage	* ev00_008a_mugai_a.png 0 0
.message	1830		�@�[�@	����ô����
.message	1840	yuk-000_01-0089	@�D�@�q	�������йص��˻��£�����ӭ���ܻ��Ľ���ء�����
.message	1850		�@�[�@	������ʲô��˼��
.message	1860	yuk-000_01-0091	@�D�@�q	���������˵Ĵ���֮��ɣ����һ����Χ���������
.message	1870	yuk-000_01-0093	@�D�@�q	����Ȼ�Ҳ�����ô���Ծ��ء�
.message	1880			��˵Щ���µ����顣

;����Ӱ�����å�
;.message	1890			�Ȥ��������������ͨ�ꤹ��������g�˸�פ��뤳�ȤǤϤʤ���˼����
.message	1890			���ǣ����ڳ��μ�����˲�����ô̹�װɡ�

.message	1900		�@�[�@	���������������ν�ˡ���ֻ���������¶��ѡ���Ҫ��������ôΣ�յĵط��ˡ�
.transition 0 * 20
.stage	* ev00_008b02.png 0 0
.message	1910	yuk-000_01-0095	@�D�@�q	����������������������ء�
.message	1920			������Ů�Ǻǵ�Ц������
;.message	1930			����Ц�����Ϥʤ����Ҥɤ��B�˴��ä���
.message	1930			�Ǹ�Ц�ݲ�֪Ϊ��������Щ���ʡ�
.message	1940		�@�[�@	��������͵͵���ݶ���������Լ����¡����ǣ�ˤ��ȥ�����Ļ���������ŵġ�
.transition 0 * 40
.stage	* ev00_008b03.png 0 0
.message	1950	yuk-000_01-0097	@�D�@�q	��Ϊʲô����������أ���
.transition 0 * 20
.stage	* ev00_008b01_mugai_c.png 0 0
;�������������虜��Ŀ�ѥ������ʤ�����
.message	1960			������ͷ��������Ĳ��������ӡ�
.message	1970		�@�[�@	������������������������Ȼ�������𣿡�
.transition 0 * 20
.stage	* ev00_008a01_mugai_c.png 0 0
.message	1980	yuk-000_01-0099	@�D�@�q	����������˵ļ�ֵ�۰ɡ�
.message	1990			��������΢��Щ������˵����
.message	2000			˵�������޿��ǩ�����Ů����������������ӡ��
.message	2010			ͬʱҲ�о���ʵ����Ҳ������ô���¡�
.transition 0 * 40
.stage	* ev00_008a04_mugai_c.png 0 0
.message	2020	yuk-000_01-0101	@�D�@�q	����Ȼ��ˣ���Ȼ���Ҳ�û�б����ļ�ֵ�۵���˼Ŷ��

;����Ӱ�����å�
;.message	2030			Ѫ�Τ褦�˳तϦꖤ��դ餵�줿��Ů������Ť���΢Ц�ߤˉ��롣
.message	2030			��ɫ��Ϧ����ҫ�µ���Ů�����ӣ����������Ц�ݡ�

;.transition 0 * 20
.transition 0 * 10
.stage	* ev00_008b01_mugai_b.png 0 0
.message	2040	yuk-000_01-0103	@�D�@�q	�����Ϧǰ����
.message	2050			Ȼ����������������������ҵ����֩���
.message	2060		�@�[�@	����������˭����
.message	2070			��ͬһ��ѧУ��ѧ����֪���ҵ����ֱ���û��ʲô��˼�顣
.message	2080			���ǡ�
.message	2090			�Ҽǵ����������
.message	2100			���˵����ʽ�����Ц�ݣ�ȷʵ�������Ҿ�Զ�����ĳ����
.transition 0 * 20
.stage	* ev00_008a04_mugai_b.png 0 0
.message	2110	yuk-000_01-0105	@�D�@�q	����Ȼ�������Ұ�����΢��Щ�ܴ���ء���
.message	2120		�@�[�@	���ش��ҵ����⡹
;�Ӥ������ɤ��ΤǤȤꤢ�������� nbkz 2006/04/12
;.transition 0 * 20
;.stage	* ev00_008b04_mugai_b.png 0 0
.message	2130	yuk-000_01-0107	@�D�@�q	����Ҫ������ô���µı��������ر�����Ů������ǰŶ��
.message	2140			��ҡҡͷ������΢����߳��Ŀ���˵����
;����Ӱ�����å�
;.message	2150			����ʤˤ���Ĥ��ΤϤʤ�������
.message	2150			Ϊʲô����˲�����
.message	2160			���������ƺ���ǣ���ţ�����Ҫʧȥ�����ĸо���
.transition 0 * 20
.stage	* ev00_008a03_mugai_b.png 0 0
.message	2170			������Ů�ٴ�΢Ц������
;����Ӱ�����å�
;������������ǰ���_�������ߥ󥰤ϣ�Ϧ��˼���������񤫤��ȡ�
;�����ʤΤǣ��饹�Ȥޤ��]���Ƥ����������̨�~�������ʤ������¤ʤΤ⣬
;����������ζ�Ϥ��Ȥ�����˼����
;.message	2180	yuk-000_01-0109	@�D�@�q	���������ӤǤ��衹
.message	2180	yuk-000_01-0109	@�D�@�q	�������������Ӱ���
;����ǰ��ҥ餫���륿���ߥ󥰣��褯����Τ��ȣ�
.message	2190		�@�[�@	���š��ӣ���
.transition 0 * 40
.stage	* ev00_008a04_mugai_b.png 0 0
.message	2200	yuk-000_01-0111	@�D�@�q	���ţ������ҵ����󡭡��벻Ҫ˵���ǵ������Ļ�����
.message	2210			�š��ӡ�����
;.transition 0 * 40
;.stage	* ev00_008a01_mugai_b.png 0 0
.transition 0 * 40
.stage	* ev00_008a05_mugai_b.png 0 0
;�������α��飬�褯�褯����Τ��ȡ���Ҫ�ݥ���Ȥ����ã�
.message	2220	yuk-000_01-0113	@�D�@�q	����ֻ��һ�۾���������˭������ȴ���׵����������ء����ҵ����Ѿ����˵��޷������ˡ�
.transition 0 * 10
.stage	past_window.png ev00_008a05_mugai_b_close.png 0 0
;.transition 0 * 40
;.stage	* ev00_008a05_mugai_b.png 0 0
;��a05��ʹ���ɤ�����v���Ƥ����⣩
.message	2230	yuk-000_01-0115	@�D�@�q	���������
.panel 0
.transition 0 * 10
.stage	* WHITE.png 0 0
;.transition 0 * 40
;.stage	* ev00_008a05_mugai_b_close.png 0 0

;(׷��--��������ֳ����ޤ���������wait��voice�ˤ��碌���{�����뤳�� nbkz 2006/04/12
;��������Ӥ�̨�~�ϣ��虜�������ȥ�ޤ�����
.wait 200
.transition 0 * 10
.stage	* ev00_moshi.png 0 0
.message	2240		�D�@�q	�����������ǵ��ˣ�������֮ǰ��ʲô��Ҫ˵��\v\a
.wait 300





;;����Ӱ�����å�
;;�������L�äη�᪥�����ץ�����
;;��----------------------------------------------
.if ef_000 == 1 ef_000_b2
.if ef_000 <= 0 ef_000_a2
;
.label ef_000_a2

;����Ӱ�����å�
;�������`�����o��
.pragma disable_control

.goto ef_000_b2
.end
;
.label ef_000_b2
;;��----------------------------------------------






.transition 0 * 10
.stage	* WHITE.png 0 0
.wait 200



;�����롤��
;.transition 0 * 10
.playBGM efBGM016.ogg
.transition 0 * 5
.stage	vista_window2.png ev00_012a01.png 500 0
.hscroll	0	-10
.endScroll f
.panel 3
.message	2250			������ͷ������գ�΢΢��Ц�š�\a
.wait 250
.message	2260			����Ц�ո���ȥ���˿��δ�䡣\a
.wait 260
.message	2270	yuk-000_01-0119	#�D�@�q	���Ǹ�����Ҳ�ã��ݶ����ٻ�Ҳ�ã�����������һ�С������Ѿ�ԶԶ��ȥ��\v\a
.wait 80
:.wait 50
;.wait 500
.message	2280	him-000_01-0033	#�@�[�@	���Ǻ�ңԶ��������ңԶ�����Ѿ��Ǽ���ǰ���������ء�\v\a
.wait 100
;.wait 600
.message	2290	yuk-000_01-0121	#�D�@�q	����ô��������үү�ķ����ء�\v\a
.wait 50
;.wait 120
.message	2300	him-000_01-0035	#�@�[�@	���㲻Ҳһ����\v\a
.wait 200
.panel 3
.message	2310			�໥��Ц������\a
.wait 220
.message	2320			�����ȥȷʵ�ı��˵���ʵ��\a
.wait 250
.message	2330			����Ҳ����Ϊֵ�û���Ĺ�ȥ����һ������ӵ���ʵ��\a
.wait 270
.message	2340	yuk-000_01-0123	#�D�@�q	���㡭�����Ա����ء�\v\a
.wait 50
.message	2350	him-000_01-0037	#�@�[�@	����Ȼ��䰡�����Ѿ���������ʱ���ˡ�\v\a
.wait 100
;.wait 300
.message	2360	yuk-000_01-0125	#�D�@�q	���ǰ�������\v\a
.wait 100
.message	2370	yuk-000_01-0127	#�D�@�q	������һ��ȹ�����Щʱ�䡭���Ѿ������ɼ���\v\a
;.wait 300
.wait 90
.message	2380	him-000_01-0039	#�@�[�@	�����䣬���䣬��������ȥ������������Ȼ�����项\v\a
.wait 100
.message	2390	yuk-000_01-0129	#�D�@�q	����Ȼ������Ȼ�������ǣ�ȴ���˱����ѽ���\v\a
.wait 100
.message	2400	him-000_01-0041	#�@�[�@	�����˵�������Ȼ����ࡣ���ǩ�����\v\a
.wait 200
.panel 3
.message	2410			ʱ�ӵ�ָ�벻���ת��\a
.wait 250
.message	2420			��į�ͱ�������ô���۩�������һ��ὥ����ɢ��\a
.wait 290
.message	2430			��ʱ������������Ѷ��á�\a
.wait 250
.message	2440			��ţ���Ҳһ����\a
.wait 220
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_012_mugai_c2.png 0 316
.panel 3
.message	2450	him-000_01-0043	#�@�[�@	�����ǲ�Ҫ�ٰڳ����˵ı����˰ɡ�\v\a
.wait 100
.message	2460	yuk-000_01-0131	#�D�@�q	���ǰ�������\v\a
;.wait 100
.wait 90
.message	2470	yuk-000_01-0133	#�D�@�q	���������ǵڶ��ε��ٻᰡ��\v\a
.wait 200
;.wait 300
.message	2480	yuk-000_01-0135	#�D�@�q	�����ڣ�����Ҫ�������Ц�ݡ�\v\a
.wait 200
.message	2490	yuk-000_01-0137	#�D�@�q	����Ҳ��Ҫ����Ц�ա�\v\a
;.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_012_mugai_c2.png 0 316
.vscroll	0	-7
.endScroll f
.transition 0 * 20
.stage	vista_window2.png ev00_012a02_mugai_a.png 0 0
.message	2500	yuk-000_01-0139	#�D�@�q	��ֻ���������ǰ����������չ��Ц���ء�\v\a
;.wait 300
.transition 0 * 20
.stage	vista_window2.png ev00_014a01.png 0 0
;���ӥ����ˌ��ꤵ���뤿�ᒷ�롣�����ע�⤷�ƣ�
.message	2510	him-000_01-0045	#�@�[�@	����������\v\a
.wait 200
;nbkz׷�� 2006/04/07
.stage * BLACK.png 0 0
.panel 0
.wait 50
.stage	* movie.png 0 0
.message	2511			\a��
.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_014a01_mugai_a.png 0 0
;��������Ϧ��Ŀ�Ĥ��Цǣ���
.panel 3
.message	2520	him-000_01-0047	#�@�[�@	������Ц��һ��ʼ����Ѿ�ӵ�С�ֻ�����������ǵ��˶��ѡ�\v\a
.wait 50
.message	2530	yuk-000_01-0141	#�D�@�q	����������\v\a
;.wait 200
.panel 3
.message	2540			������Ц��������\a
.wait 250
.message	2550			�ɹ����ٻ�����죬����ת˲���ţ�Ȼ�������������\a
.wait 280
.message	2560			�Ǹ���Ĺ��ֵĶ��ա�\a
.wait 270
.message	2570			��Ȼ�ǹ�ȥ���˺���δƽ����\a
.wait 250
.message	2580			�����Ӻ��Ҷ������ԵĿ����š�\a
.wait 260
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_014a04_mugai_a.png 0 0
.panel 3
.message	2590	him-000_01-0049	#�@�[�@	����������찡���Ǹ�ʱ��\v\a
;.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_014a04.png 0 0
;���ӥ����������ˌ���Τ��ᣬ���룩
.message	2600	yuk-000_01-0143	#�D�@�q	����Ȼ��һ�������ء�\v\a
.wait 50
.message	2610	yuk-000_01-0145	#�D�@�q	����Ȼһ�����У���ֻҪ��һ��Ϳ��Ա���Ц�ա�\v\a
;.wait 300
.transition 0 * 20
.stage	vista_window2.png ev00_014a02_mugai_a.png 0 0
.message	2620	him-000_01-0051	#�@�[�@	������������\v\a
.wait 200
.panel 3
.message	2630			ֻҪ��������Ц���ұ���ʵ������\a
.wait 270
.message	2640			������Ҫ�κ���������ĳ̶ȡ�\a
.wait 250
.message	2650			��ʲô����Ҫ��Ц�ա�\a
.wait 280
.message	2660			ֱ�����ĺ��ǣ�΢Ц�ŵ�������������ߣ��ҷ���������˼��š�\a
.wait 300
.panel 0
.transition 0 * 10
.stage	* WHITE.png 0 0






;�����룬607_01��ꡣ
;��Ϧ���ң����������r
;�������������Ϧ����˽������
;������������m���ӣ�˽������
.transition 0 * 10
.stage	* ev00_009_pastm.png 0 0

;����Ӱ�����å�
;�������`�����Є���
.pragma enable_control

.panel 1
.message	2670	yuk-000_01-0147	�D�@�q	������Ҫ��Ϣ�˰ɣ���
.message	2680			���������̵��������Ա�˵����
.transition 0 * 20
.stage	* ev00_009_pastm2.png 0 0
;.transition 0 * 20
;.stage	* ev00_016_pastm2.png 0 0
.message	2690		�@�[�@	���ף��㻹������
.message	2700			�Ҵӱʼ�������Ŀ��ش𵽡�
.message	2710			�����ӱ�������Ȼ�ǵڶ����ˡ�
.message	2720	yuk-000_01-0149	�D�@�q	���������м������ء�������Ȼ����������������¡�
.message	2730		�@�[�@	���������������������ʱ���ӳ����Ļ�������
.transition 0 * 20
.stage	* bgw_home008a01_03_pastm.png 0 0
.message	2740	yuk-000_01-0151	�D�@�q	���Ǳ߲��ǲŸոտ�ʼ��������ڿ�ʼ�����ڿ�ʼ��
.message	2750		�@�[�@	���͵��������ɡ�
;.transition 0 * 20
;.stage	past_window.png ev00_010a03.png 0 0
.transition 0 * 20
.stage	* ev00_010a03_pastm2.png 0 0
.message	2760			�ҿ�Ц�����ӵ���Ȼ�Եã������˱ʼǡ�
.message	2770			����Ҳ���ˣ�������ͣ���˰ɡ�
.transition 0 * 20
.stage	* ev00_016_pastm2.png 0 0
.message	2780	yuk-000_01-0153	�D�@�q	��Ҫ��Ҫ������ȣ���
;�����`�ҩ`�������ϤˤΤäƤ��뤬����
.message	2790		�@�[�@	��������Ҳ�á�
;����Ӱ�����å�
;.message	2800		�@�[�@	���������䣬�⤦�ޤ뤫�������𤭤Ƥ�Ȥ��ޤ����ޤ����ˤʤ�����
.message	2800		�@�[�@	��������������˯�ɡ�
.message	2805		�@�[�@	����������ŵĻ�����Ҳ����ȥ������Ϣ��
;.transition 0 * 20
;.stage	* ev00_016a04_mugai_b.png 0 0
;.transition 0 * 20
;.stage	* ev00_016a04.png 0 0
:.transition 0 * 20
.transition 0 * 10
.stage	* ev00_016a01.png 0 0
;������ע�⣩
.message	2810	yuk-000_01-0155	�D�@�q	��������¶�����𣿡�
.message	2820		�@�[�@	�����Ǻ������𡣲�Ҫǿ���Լ�����������项
.transition 0 * 40
.stage	* ev00_016a02.png 0 0
;.transition 0 * 40
;.stage	* ev00_016a03.png 0 0
.message	2830	yuk-000_01-0157	�D�@�q	����������ֻ�ǿ�Ϧ������ı��������˶��ѡ�
.message	2840		�@�[�@	���㰡����Ϊʲô������˵���������˻����ŵĻ��أ���
;.transition 0 * 40
;.stage	* ev00_016a01.png 0 0
.transition 0 * 40
.stage	* ev00_016a04.png 0 0
;�����α������ˣ���
.message	2850	yuk-000_01-0159	�D�@�q	���š�������
.transition 0 * 40
.stage	* ev00_016a03.png 0 0
.message	2860	yuk-000_01-0161	�D�@�q	������Ϊ������Ҫ���������Ű�<���ַ���>��
.message	2870		�@�[�@	������������
.message	2880			���ǵģ������Ǻ��Ը��ء�
;.transition 0 * 20
.transition 0 * 10
.stage	* ev00_010a03.png 0 0
;.transition 0 * 40
;.stage	* ev00_016a02.png 0 0
;��02����Ϥ��ࣿ��
.message	2890	yuk-000_01-0163	�D�@�q	����ô����ȥ�̱����ˡ�


;��Ϧ���ң����������r��ҹ�����ƣ�
;������Ȥ��쾮��ö�}�ǳ�������
.transition 0 * 20
.stage	* ev00_010a04.png 0 0
.message	2900			ȷ�������Ѿ�����Լ��ı����ʱ����Ҳ����������
.message	2910			��������Щ΢��ȴʮ�����ģ�һ˲ȫ�����������и��������
.message	2920			���Լ�����Ļ�Ҫƣ�͡�
.message	2930		�@�[�@	������������
.message	2940			����ֻҪ�����۾��Ϳ��Խ������硭��
.message	2950	yuk-000_01-0165	�D�@�q	��Ϧ����
.message	2960		�@�[�@	�����������ţ���
.message	2970	yuk-000_01-0167	�D�@�q	���Ǹ�������
.message	2980		�@�[�@	����ô�ˡ�
.message	2990	yuk-000_01-0169	�D�@�q	����ʵ������������㡭����
.message	3000		�@�[�@	����������ô����
.message	3010	yuk-000_01-0171	�D�@�q	�������š�����
.message	3020	yuk-000_01-0173	�D�@�q	�����ܵ��Ǳ�ȥ�𣿡�
.message	3030		�@�[�@	����������������
.message	3040			һ˲����Ϊ�����Ƿ����ë����
.message	3050			���ǣ�ȴ��������
.message	3060		�@�[�@	���������ҵ�������ν��
.message	3070			����΢��Щ����Ļش�
.message	3080		�@�[�@	����Ȼ�Ҳ��Ǻܶ��������ʱ���Ǹûر�һ�����������𣿡�
.message	3090		�@�[�@	�������Һ����ˡ�����
.message	3100	yuk-000_01-0175	�D�@�q	��Ϧ������û���ʲô�ɣ���
.message	3110			�ڰ����Ǳߴ���΢΢�Ľ�����
.message	3120	yuk-000_01-0177	�D�@�q	���ң�������˵��Ҫ���Ϧ���ı������Ŷ����
.message	3130		�@�[�@	������������˵������������Ļ���
.message	3140	yuk-000_01-0179	�D�@�q	�����������Լ�����ġ������������
.message	3150		�@�[�@	��û��������
.message	3160			�е����ϵ�Щ������ȣ��ұ��������ӡ�
.message	3170	yuk-000_01-0181	�D�@�q	��Ϧ��������ʵ��H�ء�
.message	3180		�@�[�@	�����˹�����ʵ˯����
.message	3190	yuk-000_01-0183	�D�@�q	�����������ҵ������أ���
.message	3200		�@�[�@	������㡹
.message	3210			�ұ�������˵����
.message	3220			�ɶ񣬶�����˵���Ǵ�ʧ��
;����Ӱ�����å�
;.message	3230	yuk-000_01-0185	�D�@�q	�����㣬ʧ�񤷤ޤ���
.message	3230	yuk-000_01-0185	�D�@�q	����ô�������ˡ�Ŷ��
.message	3240			������������������챻����������
.message	3250			Ȼ�����ӱ����˽�����
.transition 0 * 10
.stage	* ev00_011a01.png 0 0
.message	3260	yuk-000_01-0187	�D�@�q	���ߺߺߺߺߡ�����
;.message	3260	yuk-000_01-0187	�D�@�q	���դդա�����
.message	3270		�@�[�@	������ʲô���Ǹ���ֵ�Ц����
.message	3280			���������ҵı����˹�����
.message	3290			����������ظ��Ĵ��С�����
.message	3300		�@�[�@	������������
.transition 0 * 40
.stage	* ev00_011a02.png 0 0
.message	3310	yuk-000_01-0189	�D�@�q	���Բ���
.message	3320		�@�[�@	��ΪʲôҪ��Ǹ��
.message	3330	yuk-000_01-0191	�D�@�q	�������¡�������΢�����°ɡ����ڻ��ǿ���һ�µıȽϺá�
.message	3340		�@�[�@	��������֪����
.message	3350			���Ը���������Ҳƽ����������
.message	3360			Ϊ����������������ҲҪ���Ƹ�������
.message	3370		�@�[�@	�����ӡ�
.message	3380			��ת�����壬����������棬��ס����С�����塣
.transition 0 * 40
.stage	* ev00_011b01.png 0 0
.message	3390	yuk-000_01-0193	�D�@�q	����������
.message	3400		�@�[�@	������ȡů�ܿ��԰ɣ���
.transition 0 * 40
.stage	* ev00_011b02.png 0 0
.message	3410	yuk-000_01-0195	�D�@�q	���ţ���
.message	3420			���Ӹ��˵�������
.transition 0 * 40
.stage	* ev00_011b03.png 0 0
.message	3430		�@�[�@	�����ƣ����᲻����𣿡�
.message	3440	yuk-000_01-0197	�D�@�q	�����ţ�û�µġ�
.message	3450	yuk-000_01-0199	�D�@�q	����Ȼ����ǿ���Լ�������һ�鱻��Ҳ�����ء�
.message	3460			��������߿��˿���
.message	3470	yuk-000_01-0201	�D�@�q	���㿴�������˸�һ�鱻�첻Ҳͦ����
.message	3480		�@�[�@	�������Ļ��᲻����İɡ�λ��Ҳ��С��
.message	3490			˵���������ʱ��
.message	3500			��ʱ����˵��һ����������쩤��ֻ��һ��Ļ������������ᰲ��������
.message	3510			��ͬһ��������������Ʋ�ס�ġ�
.message	3520			��������������״̬�Ļ����Һ����Ӷ���ͷʹ�ġ�
.message	3530		�@�[�@	��ż����������
.message	3540	yuk-000_01-0203	�D�@�q	�����أ���һֱ������
.message	3550	yuk-000_01-0205	�D�@�q	����Ϧ��һ�𡭡�һֱ��һ��ͺá�
.message	3560	yuk-000_01-0207	�D�@�q	�������Ļ�����������Ҳ������һ���ء�
.message	3570		�@�[�@	������˵����ô���˵Ļ���������
.message	3580	yuk-000_01-0209	�D�@�q	��������Ҳ�ܺ��߰���
.message	3590		�@�[�@	���Ǿͱ�˵����
.message	3600	yuk-000_01-0211	�D�@�q	�����ǡ�
.transition 0 * 40
.stage	* ev00_011c01.png 0 0
.message	3610	yuk-000_01-0212		����������Ҵ����˹�����
.transition 0 * 40
.stage	* ev00_011b03.png 0 0
.message	3620	yuk-000_01-0213	�D�@�q	�����ǣ�����������˰���
.message	3630		�@�[�@	���������Ǹ�С������
.transition 0 * 40
.stage	* ev00_011c02.png 0 0
.message	3640			����������˹�ȥ�������ı�ס���ӡ�
.transition 0 * 10
.stage	* ev00_010a04.png 0 0
;.transition 0 * 10
;.stage	* ev00_010a04_mugai_a.png 0 0
.message	3650			�ţ��Ӵ��Ժ�ÿ�춼һ�����߰ɡ�
.transition 0 * 10
.stage	past_window.png ev00_010a04.png 0 0
;.transition 0 * 10
;.stage	past_window.png ev00_010a04_mugai_a.png 0 0
.message	3660			���������廥�࿿����˫�ֽ��ղ��֡�
.panel 0
.transition 0 * 10
.stage	* WHITE.png 0 0




;;����Ӱ�����å�
;;�������L�äη�᪥�����ץ�����
;;��----------------------------------------------
.if ef_000 == 1 ef_000_b3
.if ef_000 <= 0 ef_000_a3
;
.label ef_000_a3

;����Ӱ�����å�
;�������`�����o��
.pragma disable_control

.goto ef_000_b3
.end
;
.label ef_000_b3
;;��----------------------------------------------





;���������֤��񻯤��ޤ��� nbkz 2006/04/12
.transition 0 * 10
.stage	* ev00_asaga.png 0 0
.message	3670			���������٣����Բ��벻�֡�\v\a
.wait 400



;�����롤��
;.transition 0 * 10
.transition 0 * 5
.stage	vista_window2.png ev00_013a01_mugai_a.png 0 0
.panel 3
.message	3680	him-000_01-0053	#�@�[�@	������Ƿǳ�����ء�����\v\a
.wait 50
;.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_013a01_mugai_a.png 0 0
.hscroll	660	10
.endScroll f
.message	3690	yuk-000_01-0215	#�D�@�q	���ţ��ǳ�������\v\a
.wait 200
.panel 3
.message	3700			��Ȼż���ᳳ���ܣ���Ҳ�����Ƕ��������е�С������\a
.wait 260
.transition 0 * 20
.stage	vista_window2.png ev00_013a01.png 0 0
.message	3710			����ʲô���ѶԷ���������Ҫ����\a
.wait 240
.message	3720			Լ������һ������ȥ��\a
.wait 280
.message	3730			Լ����˵ġ�����\a
.wait 220
.message	3740	him-000_01-0055	#�@�[�@	����������ȴ����\v\a
;.wait 200
;nbkz׷�� 2006/04/07
.stage * BLACK.png 0 0
.transition 0 * 20
.panel 0
.wait 50
.stage	* sound.png 0 0
.message	3741			\a��
.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_013a05.png 0 0
.panel 3
.message	3750	yuk-000_01-0217	#�D�@�q	������������\v\a
;.wait 200
.message	3760	him-000_01-0057	#�@�[�@	������ȴ�ɿ������ŵ�˫�֣����Ų�ͬ�ĵ�·�������\v\a
;.wait 300
.message	3770	yuk-000_01-0219	#�D�@�q	���š�\v\a
.wait 100
.panel 3
.message	3780			���Բ���˵�Ƕ��ݵ�ʱ�䡣\a
.wait 240
.message	3790			�����������ǶԷ�������ֵĵز���\a
.wait 290
.message	3800			�����ҵļ����ѿ�ʼ�绯�������Ҫ�����ﶼ�ѱ���Ҷ�ȥ�˰ɡ�\a
.wait 340
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_013a05_close.png 0 0
.panel 3
.message	3810	yuk-000_01-0221	#�D�@�q	��Ϊʲô������\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_013a03.png 0 0
.message	3820	yuk-000_01-0223	#�D�@�q	��Ϊʲô����Ҫ���������أ���\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_014a01.png 0 0
.message	3830	him-000_01-0059	#�@�[�@	�����ǲ���Լ�õ���\v\a
.wait 100
.message	3840	him-000_01-0061	#�@�[�@	������������Լ����\v\a
.wait 100
.panel 3
.message	3850			����ǰ��ʥ�����糿��\a
.wait 240
.message	3860			��ȷʵ����������Լ������Ҳ���˵�ͷ��\a
.wait 280
.message	3870			�����������������ӵȴ����ҵĽ̻ᡣ\a
.wait 280
.message	3880			���յ����������Լ������¡�\a
.wait 280
.message	3890			û������Լ���������ؿڵ�ʹ���������������ǡ�����\a
.wait 300
.message	3900	him-000_01-0063	#�@�[�@	������˵����������Ⱦõġ�\v\a
.wait 100
.stage	vista_window2.png ev00_013a04.png 0 0
.message	3910	yuk-000_01-0225	#�D�@�q	�������������������顭����\v\a
;.wait 400
;.wait 300
.panel 3
.message	3920			������һ����һ�ε�ҡͷ��\a
.wait 230
.message	3930			�����ס�\a
.wait 210
.message	3940			���Ѿ�����ԭ�µ���ʵ��\a
.wait 250
.message	3950			���ǣ�����ؿڵ�ʹ��ȴ������˾��������ˡ�\a
.wait 270
.panel 0
.stage	vista_window2.png ev00_014a01.png 0 0
.panel 3
.message	3960	him-000_01-0065	#�@�[�@	����������������е�ʱ��Լ�����������\v\a
.wait 100
.message	3970	him-000_01-0067	#�@�[�@	�����ҡ�\v\a
.wait 140
;.wait 100
.message	3980	him-000_01-0069	#�@�[�@	����ţ�һֱ�ں������ҵ������㡭����û��ɣ���\v\a
;.wait 300
.wait 20
.panel 3
.message	3990			����ֱ�����ڻ�������ط��ȴ��š�\a
.wait 240
.message	4000			����������������żȻ��\a
.wait 270
.panel 0
.stage	vista_window2.png ev00_013a02.png 0 0
.panel 3
.message	4010	yuk-000_01-0227	#�D�@�q	���š�����\v\a
.wait 100
.message	4020	yuk-000_01-0229	#�D�@�q	��˵����������û��\v\a
;.wait 200
;.stage	* ev00_014a01.png 0 0
;���ƾ�ָ���ˤ��������
.message	4030	him-000_01-0071	#�@�[�@	�������Ұɡ�������߾���������ʲô��\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_014_mugai_b.png 0 0
.message	4040	yuk-000_01-0231	#�D�@�q	��������ʲô���𡭡���\v\a
.wait 100
.panel 3
.message	4050			����̻�����飬���ӿ�ʼ��Ѱ��Ҫ˵�Ļ���\a
.wait 240
.message	4060			�ҵ�Ȼ���ס�\a
.wait 220
.message	4070			����һ������Ϳ���˵��Ĺ��¡�\a
.wait 270
.message	4080	yuk-000_01-0233	#�D�@�q	�����µĿ�ʼ������\v\a
.wait 200
;nbkz׷�� 2006/04/07
.stage * BLACK.png 0 0
.transition 0 * 20
.panel 0
.wait 50
.stage	* direc.png 0 0
.message	4081			\a��
.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_015a02.png 0 0
.panel 3
.message	4090	yuk-000_01-0235	#�D�@�q	����Ȼ����ʥ�����ء�\v\a
.wait 130
;.wait 150
;.wait 100
.message	4100	yuk-000_01-0237	#�D�@�q	������һ��ǰ��ʥ���ڵ�ҹ��\v\a
.wait 150
;.wait 100
.message	4110	yuk-000_01-0239	#�D�@�q	���Ǹ��˩������ˣ����������Ǹ��������м��������ء�\v\a
.wait 90
;.wait 100
.message	4120	him-000_01-0073	#�@�[�@	�������𣿡�\v\a
.wait 100
.panel 3
.message	4130			��������ûƷ���ˣ�������л�����һ����\a
.wait 270
.message	4140	yuk-000_01-0241	#�D�@�q	���ƿ����飬�Ǹ������˽�����\v\a
.wait 150
.message	4150	yuk-000_01-0243	#�D�@�q	���߽������ǣ�һ���к��ӡ�\v\a
.wait 150
.message	4160	yuk-000_01-0245	#�D�@�q	��ĳЩ�ط��������Ʃ����ԣ��������˻������Ϣ��\v\a
;.wait 300
.transition 0 * 20
.stage	vista_window2.png ev00_015a01.png 0 0
;���������¤�01���⤦����ä�Ŀ�򼚤᤿Ц������ʡ�����
.message	4170	yuk-000_01-0247	#�D�@�q	�������ҲŻ���ô��ɡ�\v\a
.wait 100
.message	4180	him-000_01-0075	#�@�[�@	��ʲô����\v\a
.wait 100
;nbkz׷�� 2006/04/07
.stage * BLACK.png 0 0
.transition 0 * 20
.panel 0
.wait 50
.stage	* produce.png 0 0
.message	4181			\a��
.wait 200
;.transition 0 * 20
.transition 0 * 10
.stage	vista_window2.png ev00_015a03.png 0 0
.panel 3
.message	4190	yuk-000_01-0249	#�D�@�q	����΢�������߽�����к��Ĺ�����ȥ�ɡ�\v\a
.wait 100
.message	4200	him-000_01-0077	#�@�[�@	�����������������Ǹ��˵Ĺ��¡�\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_015a01.png 0 0
.message	4210	yuk-000_01-0251	#�D�@�q	�������Ƴ��Ĺ��£������𣿡�\v\a

.wait 110
;.wait 100


;����Ӱ�����å�
;.panel 3
;.message	4220			΢Ц���ƣ����Ӥφ��������Ƥ��롣\a
;.wait 260
;.panel 0


.message	4230	him-000_01-0079	#�@�[�@	����Ȼ�����������кܾ��ء�\v\a
;.wait 300
.transition 0 * 20
.stage	vista_window2.png ev00_015a02.png 0 0
.message	4240	yuk-000_01-0253	#�D�@�q	����ô���������渵����ɡ�\v\a
.wait 100
;.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_015_mugai_a.png 0 0
.panel 0
;��ѥͥ�0�ϥե��`�ɤȻ�����g�˒��फ���ե��`�ɤ�ǰ���ä���������λ�äǤ����Τ����褯�褯���줷�ƣ�
;�������όg�H�ϥ�å��`��������ɥ��������ƣ������Τߤǣ�-- auto�ˤ���wait׷�� nbkz 2006/04/12



;����Ӱ�����å�
;�����g�Y��
;��-------------------------------------------------
;.label koko
;.playBGM efBGM016.ogg
;.transition 0 * 20
;.stage	vista_window2.png ev00_015_mugai_a.png 0 0
;.panel 0
;��-------------------------------------------------


.panel 3
.message	4250	yuk-000_01-0255	#�D�@�q	��������������̻��һ������ʼ�ģ����յĹ��¡�����\v\a
.wait 150
.panel 0

;�����ȥ�Ϥ����ˤ�äƤ��ޤ��� nbkz 2006/04/07
;.panel 0
.transition 0 * 10
;.transition 0 * 5
.stage	vista_window2.png WHITE.png 0 0
.wait 100
.effect SnowH
.transition 0 * 10
.stage	vista_window2.png bgw_normal011a01_03.png 0 600
.transition 0 * 20
.stage	vista_window2.png bgw_normal011a01_03.png 0 600
.vscroll	0	-10
.endScroll f
;.transition 0 * 20
;.wait 120
.wait 160
;.transition 0 * 10
.transition 0 * 7
.stage	vista_window2.png bgw_normal011a01_03_tero_c.png 0 0
.message	4251			\a��
;.wait 200
;.transition 0 * 10
.wait 220
.transition 0 * 7
.stage	vista_window2.png bgw_normal011a01_03_tero_d.png 0 0
.message	4251			\a��
.wait 250
;.transition 0 * 10
.transition 0 * 7
.stage	vista_window2.png bgw_normal011a01_03_tero_out.png 0 0
.message	4251			\a��


;.wait 500
.wait 170



;.playBGM *
.transition 0 * 10
.stage	* WHITE.png 0 0

;����Ӱ�����å�
.playBGM * 10
.wait 40

.effect *
;.stage * BLACK.png 0 0




;����Ӱ�����å�
;���������¡��i�����ե饰��
;��----------------------------------------------
.setGlobal ef_000 = 1
;��----------------------------------------------


;����Ӱ�����å�
;�������`�����Є���
.pragma enable_control


.chain 100_01.sc
;��100_01�ء�
;.end
