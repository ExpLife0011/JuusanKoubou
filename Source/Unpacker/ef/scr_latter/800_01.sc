.setGlobal EYE_SEQ_DEFAULT = 2


.if ef_800_01 == 1 ef_800_01_b1
.if ef_800_01 <= 0 ef_800_01_a1


.label ef_800_01_a1

.pragma disable_control

.goto ef_800_01_b1
.end

.label ef_800_01_b1




.transition 0 * 10
.stage	* BLACK.png 0 0

.transition 0 * 10
.stage	* title_final2.png 0 0
.message	5999			\a��
.wait 800

.transition 0 * 10
.stage	* BLACK.png 0 0
.wait 200




.transition 0 * 10
.stage	vista_window2.png BLACK.png 0 0
.panel 3
.message	110			\a���Ҵ򿪽̻���ſ�ʼ�������˶���ʱ�����ء�
.wait 350
.message	120			\a�о������˺ü����ʱ�⣬�����ָо�ֻ��һ˲֮������顣
.wait 370


.panel 3
.transition 0 * 5
.stage	vista_window2.png ago_base_80001a.png 0 0
.message	130	yuk-800_01-0003	#�D�@�q	������þ��ء�����\v\a
.transition 0 * 10
.stage	vista_window2.png ago_base_80001b.png 0 0
.message	140	him-800_01-0003	#�@�[�@	����ֱ��������ֻʣ������������һ����\v\a
.wait 50
.transition 0 * 10
.stage	vista_window2.png ev00_002a03.png 0 250
.message	150	yuk-800_01-0005	#�D�@�q	��ֻʣ�º�Ϧ���������𡭡�����Ҳ�����ء�\v\a

.transition 0 * 20
.stage	vista_window2.png ev00_002a02.png 0 250
.message	170	yuk-800_01-0007	#�D�@�q	��ÿһ�춼�ܿ��ֵ����ӡ�����\v\a
.transition 0 * 10
.stage	vista_window2.png ev00_013a04.png 0 250
.message	180	yuk-800_01-0009	#�D�@�q	�����Ϊ�ǻ����۵�Ϧ��������û�˿�����ʱ���ú������۸��˼ҡ�\v\a
.message	190	him-800_01-0005	�@�[�@	���㰡��˵�˺�ʧ��Ļ��˰���\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_017.png 0 600
.message	200	yuk-800_01-0011	#�D�@�q	��������\v\a
.wait 50

.transition 0 * 15
.stage	vista_window2.png ev00_013a03.png 0 0
.message	230	yuk-800_01-0013	#�D�@�q	�����ǣ���ġ�\v\a
.wait 70


.message	250	yuk-800_01-0015	#�D�@�q	�����졪��ֻ�н����������κ������������ǡ�\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_014a03.png 0 0
.message	260	him-800_01-0007	#�@�[�@	��������Ҳ�ǡ�\v\a
.wait 50
.message	270	him-800_01-0009	#�@�[�@	����Ϊ�������������Լ���ˡ�\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_015a01.png 0 0
.message	280	yuk-800_01-0017	#�D�@�q	���Ǹ����Ӹ��������ء�\v\a
.wait 30
.transition 0 * 20
.stage	vista_window2.png ev00_015a02.png 0 0
.message	290	yuk-800_01-0019	#�D�@�q	���ҵ����顣����������ȴ������项\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_014a02_mugai_a.png 0 0
.message	300	him-800_01-0011	#�@�[�@	���������ǵġ�\v\a

.transition 0 * 15
.stage	vista_window2.png BLACK.png 0 0
.panel 3
.message	330			\a��������˺�������˵�Ļ����Ҵ�Ų������Űɡ�
.wait 370
.message	340			\a���ǣ�����Ϊ�Ǹ����ӵĻ���
.wait 330
.message	350			\a������Ϊ�����Ӷ����������µ���Ů��˵�Ļ��������������š�
.wait 390
.message	360			\a�����ҲŻص���������С�
.wait 350


.panel 3
.transition 0 * 10
.stage	vista_window2.png ev00_013a02.png 0 0
.message	370	yuk-800_01-0021	#�D�@�q	��δ����Ҳ�Ѿ������˰ɡ�\v\a
.panel 3

.transition 0 * 15
.stage	vista_window2.png ev00_014a02.png 0 0

.message	390	him-800_01-0013	#�@�[�@	���Ǹ��������ڣ��;������ĵĹ������ʥ���ڰɡ�\v\a
.transition 0 * 10
.stage	vista_window2.png ev00_012a01.png 0 0
.message	400	yuk-800_01-0023	#�D�@�q	�������ʥ���ڡ�����\v\a
.message	410	him-800_01-0015	#�@�[�@	������������ǰ˵���İɣ�����������ʥ���ڡ�\v\a
.wait 120
.message	420	yuk-800_01-0025	#�D�@�q	������һ˵�������������������������ء�\v\a
.wait 100
.message	430	him-800_01-0017	#�@�[�@	��ȥȥ���ɣ���Ȼ�ϲ��Ͻ����ʥ�����ˣ������Ǳ߿�������Ŷ��\v\a
.wait 100
.message	440	yuk-800_01-0027	#�D�@�q	�����������ˡ�\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_012a02.png 0 0
.message	450	yuk-800_01-0029	#�D�@�q	�������ˣ�δ���������������ʥ���ڵĻ����������Ϳ����ˡ�\v\a
.wait 50
.message	460	him-800_01-0019	#�@�[�@	�����𡭡���\v\a


.transition 0 * 15
.stage	vista_window2.png BLACK.png 0 0
.panel 3
.message	470			\a��ɽ��ϣ�;������ȹ���ʥ���ڣ����ǵ�һ��Ҳ���������һ���˰ɡ�
.wait 370
.message	480			\a�Ǹ��ر�������ǡ��������ʥ���ڡ�
.wait 330
.message	490			\a�Һ����Ӳ���˼��ػ��������ŵģ������ʥ���ڡ�
.wait 390
.message	500			\a��Ҳ����Ե�ְɡ�
.wait 300


.panel 3
.transition 0 * 10
.stage	vista_window2.png ev00_015a03.png 0 0
.message	510	yuk-800_01-0031	#�D�@�q	����ʹ���������Ǻ������ء��������ڣ�δ�������л���������ٻ᡹\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_014a03_mugai_a.png 0 0
.message	520	him-800_01-0021	#�@�[�@	����ֻ��δ�������к����������ģ��йص����ǡ�\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_014a03.png 0 0
.message	530	him-800_01-0023	#�@�[�@	������Ϊ��ҵĻ��䣬���ӳ��ˣ���Ŧ������������ǵ��ٻ᡹\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_014a02.png 0 0
.message	540	him-800_01-0025	#�@�[�@	���Ҿ���������Ϊ��Ŷ��\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_014_mugai_b.png 0 0
.message	550	yuk-800_01-0033	#�D�@�q	��������\v\a
.wait 20
.message	560	yuk-800_01-0035	#�D�@�q	�����ǲ���Ϧ�������������뷨�ء�\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_014a02_mugai_a.png 0 0
.message	570	him-800_01-0027	#�@�[�@	����Ϊ������ʥ���ڰ���ż������Ҳ���԰ɡ�\v\a


.transition 0 * 10
.stage	vista_window2.png BLACK.png 0 0
.panel 3
.message	580			\a��ʥ�����������漣��
.wait 330
.message	590			\a����ȫ����ʲôϷ��������������Ҳ�á�
.wait 390
.message	600			\a������
.wait 280
.message	610			\a����״�����˲��ò��š�
.wait 330


.panel 3
.transition 0 * 15
.stage	vista_window2.png ev00_014a03.png 0 0
.message	620	him-800_01-0029	#�@�[�@	�����ӡ�\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_013a03.png 0 0
.message	630	yuk-800_01-0037	#�D�@�q	���ǡ�\v\a


.transition 0 * 15
.stage	vista_window2.png BLACK.png 0 0
.panel 3
.message	640			\a���ǲ��ò���һ�¡�
.wait 320
.message	650			\aֻ������������ڵ�״���Ļ���
.wait 320
.message	660			\aֻ�������Ļ����һ���Ϊ���Լ��������������Ρ�
.wait 390
.message	670			\a���ԡ�������ȷ���°ɡ�
.wait 320


.panel 3
.transition 0 * 20
.stage	vista_window2.png ago_base_80001c.png 0 0
.message	680	him-800_01-0031	#�@�[�@	��Ϊʲô���㻹�Ǻ���ǰһ����\v\a
.transition 0 * 15
.stage	vista_window2.png ago_base_80001d.png 0 0
.message	690	yuk-800_01-0039	#�D�@�q	������������\v\a

.panel 3
.transition 0 * 15
.stage	vista_window2.png ago_base_80001e.png 0 0
.message	730	him-800_01-0033	#�@�[�@	��Ϊʲô��ᡭ���������\v\a
.wait 140
.message	740	him-800_01-0035	#�@�[�@	����Ϊ���㡭����\v\a
.wait 50
.transition 0 * 20
.stage	vista_window2.png ed05_004_mugai.png 0 0
.message	750	yuk-800_01-0041	#�D�@�q	���ţ����ء�\v\a

.transition 0 * 10
.stage	vista_window2.png WHITE.png 0 0
.panel 3
.message	760			\a����СС�ĵ���ͷ��
.wait 320
.message	770			\a��Ȼ����Щ���˵ı��飬���ǵ�ȷ���˵�ͷ��
.wait 390

.panel 3
.playBGM * * 5
.transition 0 * 20
.stage	vista_window2.png ago_base_80001f.png 0 0
.message	780	yuk-800_01-0043	#�D�@�q	���깬����������ڡ���Ӧ���ں�����ǰ����ʧ�ˡ�\v\a



.playBGM efLAT04_08.ogg
.transition 0 * 10
.stage	vista_window2.png WHITE.png 0 0


.panel 3
.message	790			\a������һ��Ů���ӡ�
.wait 300
.message	800			\a�����źܶ౯�˵Ļ��䡣
.wait 350
.message	810			\aһֱ���ڿ����š�
.wait 330
.message	820			\a�����ţ������ţ���ʹ�����Ҳû��ʧȥ�������ᡣ
.wait 380
.message	830			\a����ģ��ɰ��ĨD�D�洦�ɼ�����ͨ��Ů���ӡ�
.wait 390
.playSE2 *
.message	840		#�@�[�@	�����ǡ�����\v\a
.wait 330
.message	850			\a����Ӧ��Ц�Ŷȹ�����ҹҹ�ġ�
.wait 340

.transition 0 * 10
.stage	* ev05_216_mugai.png 0 0
.message	860		#�@�[�@	��Ϊʲô���㡭����\v\a
.wait 330


.wait 360
.transition 0 * 20
.stage	* ev05_218a01_mugai.png 0 0
.message	1060		#�@�[�@	�����ӡ�����\v\a
.wait 320


.transition 0 * 15
.stage	* ev05_218a02_mugai.png 0 0
.message	1140		#�@�[�@	���š����ӡ�\v\a
.wait 330
.transition 0 * 15
.stage	* ev05_218a03_mugai.png 0 0
.message	1150		#�@�[�@	����ȥ�����ﰡ��������\v\a
.wait 300
.transition 0 * 15
.stage	* ev05_218a04_mugai.png 0 0
.message	1160		#�@�[�@	��˵��Ҫ���ҡ�������˵��Ҫ���ҵ�ô��������\v\a
.wait 330
.transition 0 * 15
.stage	* ev05_218b01_mugai.png 0 0
.message	1170		#�@�[�@	��Լ���ˡ���Լ�����ɡ�������\v\a
.wait 330


.transition 0 * 15
.stage	* ev05_218b01_mugai_bk.png 0 0
.message	1190		#�@�[�@	���ӽ��Ժ󣳸��ˡ��������ͥ������\v\a
.wait 300
.transition 0 * 15
.stage	* ev05_218b01_mugai_ek.png 0 0
.message	1200		#�@�[�@	����ͥ��������\v\a
.wait 300
.transition 0 * 10
.stage	* ev05_218b01_mugai.png 0 0
.message	1210			\a���������ں�����Ѿ��޴���ȥ��
.wait 360
.message	1220			\a��ʹ�����Ȼ��˻���ߵش󺰨D�D������Ҳ�������ˡ�
.wait 390
.message	1230			\a���ӡ���
.wait 300
.message	1240			\a��Ҫ���������ұ��һ���ˡ�
.wait 330
.message	1250			\a���Ҷ��¡�����ȥ�Ķ��˰�����
.wait 370
.transition 0 * 10
.stage	* ev05_218b01_mugai_jk.png 0 0
.message	1260			\a�ţ����ӡ�
.wait 330
.message	1270			\a��һ�Ρ�
.wait 350
.message	1280			\a�����������������
.wait 350
.transition 0 * 10
.stage	* ev05_218b01_mugai_fk.png 0 0
.message	1290			\a��һ�ΨD�DЦ�����ɡ�

.playBGM * * 5
.wait 150
.panel 3
.wait 350



.transition 0 * 10
.stage	vista_window2.png BLACK.png 0 0
.panel 3
.message	1300			\a�Ҽǵã��Ǹ�ʥ���ڵ�����Ҳ���ر�ĺ��䡣
.wait 350


.message	1310			\a������̻�ġ�
.wait 310
.message	1320			\a����ĵذ��ϡ�
.wait 310
.message	1330			\a��������ʱ����Ƿ���ů����
.wait 380
.message	1340			\a�������޷���ȴ��
.wait 330


.playBGM efBGM016.ogg

.panel 3
.transition 0 * 10
.stage	vista_window2.png ev00_014a05_mugai_a.png 0 0
.message	1350	him-800_01-0037	#�@�[�@	���Ǹ�ʱ��\v\a
.transition 0 * 10
.stage	vista_window2.png ev00_013a03.png 0 0
.message	1360	him-800_01-0039	#�@�[�@	���Ǹ�ʱ���㡭����\v\a

.transition 0 * 15
.stage	vista_window2.png BLACK.png 0 0
.panel 3
.message	1370			\a����ҧס���촽��
.wait 310
.message	1380			\a��Ȼ��ô�������Ͽɡ�
.wait 330
.message	1390			\a��Ϊ�Ҵ��������������塣
.wait 360
.message	1400			\a���ԣ�������Ҳ����Ц�����ˡ��������ž�ʹ�������������¡�
.wait 430

.panel 3
.transition 0 * 15
.stage	vista_window2.png ev00_013a05.png 0 0
.message	1410	yuk-800_01-0045	#�D�@�q	�������벻Ҫȥ��δ����\v\a
.wait 30
.transition 0 * 15
.stage	vista_window2.png ev00_014a03.png 0 0
.message	1420	him-800_01-0041	#�@�[�@	����֪�����Ǹ�����û���κ������\v\a
.wait 50
.message	1430	him-800_01-0043	#�@�[�@	������������Ҳû���κδ���Ŷ��\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_013a05_close.png 0 0
.message	1440	yuk-800_01-0047	#�D�@�q	��������˵�Ļ�����Ҳ�������������ء�\v\a


.transition 0 * 10
.stage	vista_window2.png BLACK.png 0 0
.panel 3
.message	1450			\a������������ǰ�Ϳ챻�����˵�������
.wait 420
.message	1460			\a��˭��ȥ���������ء�
.wait 360
.message	1470			\a��ȻҪ��ȫ��ͨ�Ǽ��£�Ҳ�����൱���ʱ�䡣
.wait 390


.panel 3
.transition 0 * 10
.stage	vista_window2.png ago_base_80001g.png 0 0
.message	1480	him-800_01-0045	#�@�[�@	�����ԣ��㡭����\v\a
.wait 50


.transition 0 * 10
.stage	vista_window2.png ev00_003_vista.png 0 0

.message	1500	yuk-800_01-0051	#�D�@�q	����ţ��Ҳ������깬���Ӱɡ�\v\a

.panel 3
.transition 0 * 15
.stage	vista_window2.png ago_base_80001h.png 0 0
.message	1530	him-800_01-0047	#�@�[�@	��������������������������ӡ�\v\a
.wait 30

.panel 3
.transition 0 * 15
.stage	vista_window2.png ev00_013a04.png 0 0
.message	1550	yuk-800_01-0053	#�D�@�q	��Ϧ��������\v\a

.panel 3
.transition 0 * 15
.stage	vista_window2.png ev00_013a02.png 0 0
.message	1570	yuk-800_01-0055	#�D�@�q	������ʲôʱ��ص�������еģ���ȫ�����ǵ��ˡ�\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_013a03.png 0 0
.message	1580	yuk-800_01-0057	#�D�@�q	���ع�������ʱ�����Ѿ��������ˣ�����Ҳ�ǳ����ҡ�����\v\a
.wait 110
.message	1590	yuk-800_01-0059	#�D�@�q	��ֻ�����𣱸����֣����깬���ӡ�����������������ҵ����֡�\v\a
.transition 0 * 15
.stage	vista_window2.png ago_base_80001i.png 0 0
.message	1600	yuk-800_01-0061	#�D�@�q	�����ǣ�������֪���ˡ��Ҽ����깬���ӣ�Ҳ�����깬���ӡ�\v\a


.transition 0 * 15
.stage	vista_window2.png ev00_014a05_mugai_a.png 0 0
.message	1610	him-800_01-0049	#�@�[�@	��ԭ���������𡭡���\v\a

.panel 3
.transition 0 * 10
.stage	vista_window2.png ev00_015_mugai_a.png 0 0
.message	1640	yuk-800_01-0063	#�D�@�q	��������Ļ�����Ҳ�ע�⵽�ġ�\v\a
.wait 120
.message	1650	yuk-800_01-0065	#�D�@�q	���Ұ���\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_013a05_close.png 0 0
.message	1660	yuk-800_01-0067	#�D�@�q	����ţ����Ǵ��깬���Ӻ��������������ŵ�С�����е����ġ�����\v\a
.wait 50
.transition 0 * 20
.stage	vista_window2.png ev00_013a05.png 0 0
.message	1670	him-800_01-0051	#�@�[�@	�����ǵġ������ӡ�����\v\a

.transition 0 * 10
.stage	vista_window2.png BLACK.png 0 0
.panel 3
.message	1680			\a������һ����ʧ������������
.wait 380
.message	1690			\a�Һ����ӣ�Ӧ����ɣ����˵ļ�ͥ�ġ�����
.wait 390


.panel 3
.transition 0 * 10
.stage	vista_window2.png ev00_013a03.png 0 0
.message	1700	yuk-800_01-0069	#�D�@�q	���ص�������֮�ǵ��ң����ű���Ҫ�������项\v\a
.wait 80
.message	1710	him-800_01-0053	#�@�[�@	������Ҫ�������顭������\v\a
.wait 130
.message	1720	yuk-800_01-0071	#�D�@�q	��������ô��������ҡ�\v\a


.transition 0 * 15
.stage	vista_window2.png ago_base_80001j.png 0 0
.panel 3
.message	1740	yuk-800_01-0073	#�D�@�q	����ʹ����һ�ˣ�Ҳ��ȥ����ضԴ��ܶ��ˡ�\v\a

.transition 0 * 15
.stage	vista_window2.png ev00_013a03.png 0 0
.message	1750	yuk-800_01-0075	#�D�@�q	��Ϊ�˱��˷��׳��Լ������ҵĹ�����\v\a
.wait 80
.message	1760	yuk-800_01-0077	#�D�@�q	������ô���ɣ���˭��������š�\v\a
.wait 80
.message	1770	him-800_01-0055	#�@�[�@	��������˭����\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_013a04.png 0 0
.message	1780	yuk-800_01-0079	#�D�@�q	��˭֪���ء�������\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_013a02.png 0 0
.message	1790	yuk-800_01-0081	#�D�@�q	�����Ҫ˵�Ļ���˵��������ɡ�\v\a
.wait 100
.message	1800	him-800_01-0057	#�@�[�@	����ô������\v\a

.transition 0 * 15
.stage	vista_window2.png ago_base_80001k.png 0 0
.panel 3
.message	1810			\a��ʧȥ������һ�졣
.wait 300
.transition 0 * 15
.stage	vista_window2.png ago_base_80001k2.png 0 0
.message	1820			\a��һ�죬������ա����һ����������Ʋ�ķ�϶�����µ�������â��
.wait 390

.panel 3
.transition 0 * 10
.stage	vista_window2.png ev00_014a02_mugai_a.png 0 0
.message	1830	him-800_01-0059	#�@�[�@	�����ԣ��������ʹ�ɣ���\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_014_mugai_b.png 0 0
.message	1840	yuk-800_01-0083	#�D�@�q	����ʹ������\v\a
.transition 0 * 10
.stage	vista_window2.png ev00_015a03.png 0 0
.message	1850	yuk-800_01-0085	#�D�@�q	���š�˵������������\v\a
.wait 100


.transition 0 * 15
.stage	vista_window2.png BLACK.png 0 0
.panel 3
.message	1860			\a��������΢Ц�š���
.wait 350
.message	1870			\a��ϵأ���������ͬ��ʹ���峺��Ц�ݡ�
.wait 400


.panel 3
.transition 0 * 15
.stage	vista_window2.png ev00_015a01.png 0 0
.message	1880	yuk-800_01-0087	#�D�@�q	����Ӧ�ò����������ϡ�\v\a
.wait 20
.message	1890	yuk-800_01-0089	#�D�@�q	������ǰ����ô˵�ء�\v\a
.wait 30
.message	1900	him-800_01-0061	#�@�[�@	���š�\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_015a02.png 0 0
.message	1910	yuk-800_01-0091	#�D�@�q	�����ڻ���ô��Ϊ�𣿡�\v\a


.transition 0 * 15
.stage	vista_window2.png WHITE.png 0 0
.panel 3
.message	1920			\a��������ĥ���������⡣
.wait 350
.message	1930			\a���ӻ�������������ǲ����ܵ����顣
.wait 390
.message	1940			\a����˵��˵�����ñ���Ϊ���漣����
.wait 400
.message	1950			\aȻ����Ҫ�ش���ǡ���
.wait 400


.panel 3
.transition 0 * 10
.stage	vista_window2.png ev00_015a01.png 0 0
.message	1960	him-800_01-0063	#�@�[�@	������ע�����Լ������Լ���ߵ����ǣ������Ż�������Ŷ��\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_015a03.png 0 0
.message	1970	yuk-800_01-0093	#�D�@�q	������������\v\a
.wait 50
.message	1980	yuk-800_01-0095	#�D�@�q	����ģ�������ķ��\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_014a02_mugai_a.png 0 250
.message	1990	him-800_01-0065	#�@�[�@	����Ϊ�ҳ����Լ���������ȥ���⣬����������\v\a


.transition 0 * 15
.stage	vista_window2.png WHITE.png 0 0
.panel 3
.message	2000			\a����������漣���ͻ�ı��Լ����뷨��
.wait 380
.message	2010			\a�Ҿ��ã�����Ҳû��ϵ��
.wait 330


.panel 3
.transition 0 * 15
.stage	vista_window2.png ev00_014a01.png 0 0
.message	2020	him-800_01-0067	#�@�[�@	���š�\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_013a01.png 0 0
.message	2030	yuk-800_01-0097	#�D�@�q	�������š�\v\a
.transition 0 * 10
.stage	vista_window2.png ev00_012a01.png 0 0
.message	2040	him-800_01-0069	#�@�[�@	��������˵����������ӡ�������ô���㡹\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_012a02.png 0 0
.message	2050	yuk-800_01-0099	#�D�@�q	������лл�㡹\v\a


.transition 0 * 10
.stage	vista_window2.png WHITE.png 0 0
.panel 3
.message	2060			\a���ӵ��۾���������⡣
.wait 300
.message	2070			\a͸���ģ���Ө��͸�ģ�����Ƿǳ�Ư�������ᡪ��
.wait 400


.panel 3
.transition 0 * 15
.stage	vista_window2.png ev00_014a02_mugai_a.png 0 0
.message	2080	him-800_01-0071	#�@�[�@	�����ӡ���ǰ������һ�仰û�ܶ���˵��\v\a


.transition 0 * 10
.stage	vista_window2.png WHITE.png 0 0
.panel 3
.message	2100			\a��Ϊ���ߣ�һ�ζ�û��˵�����Ļ���
.wait 380
.message	2110			\a����˵�����ɡ�
.wait 390
.message	2120			\a��ע�ҵ����顣
.playBGM *
.wait 400


.playBGM efLAT05_25.ogg


.panel 3
.transition 0 * 10
.stage	vista_window2.png ev00_018a01.png 0 0
.message	2130	him-800_01-0073	#�@�[�@	�����ӣ��Ұ��㡪����\v\a
.wait 150
.transition 0 * 10
.stage	vista_window2.png ev00_015_mugai_a.png 0 0
.message	2140	yuk-800_01-0101	#�D�@�q	��Ϧ����������\v\a


.panel 3
.transition 0 * 10
.stage	vista_window2.png ev00_018a01.png 0 0
.message	2160	him-800_01-0075	#�@�[�@	���Ұ��㣬���ӡ�����\v\a

.panel 3
.transition 0 * 15
.stage	vista_window2.png ev00_014a02.png 0 0
.message	2190	him-800_01-0077	#�@�[�@	��һֱ��û˵���������Բ���\v\a
.wait 50
.message	2200	yuk-800_01-0103	#�D�@�q	��Ϧ��������\v\a

.panel 3
.transition 0 * 15
.stage	vista_window2.png ev00_014_mugai_b.png 0 0
.message	2220	yuk-800_01-0105	#�D�@�q	������Ŷ���Ǹ���\v\a
.wait 100
.message	2230	him-800_01-0079	#�@�[�@	�����ԡ�������\v\a
.transition 0 * 15
.stage	vista_window2.png ev00_015a04.png 0 0
.message	2240	yuk-800_01-0107	#�D�@�q	���ǰ����ң��Ŷ԰ɣ���\v\a
.wait 30
.transition 0 * 15
.stage	vista_window2.png ev00_015a05.png 0 0
.message	2250	him-800_01-0081	#�@�[�@	�����ӡ�����\v\a
.wait 130

.message	2270	yuk-800_01-0109	#�D�@�q	��Ϧ�������ء�\v\a
.wait 150
.message	2280	yuk-800_01-0111	#�D�@�q	���Һ��Ҹ�������\v\a


.transition 0 * 15
.stage	vista_window2.png ev00_013a06.png 0 0

.message	2300	yuk-800_01-0113	#�D�@�q	��лл�㡭����\v\a
.wait 150
.message	2310	yuk-800_01-0115	#�D�@�q	���ܺ����������̫���ˡ�����\v\a
.wait 170
.message	2320	yuk-800_01-0117	#�D�@�q	������Լ������������ط��ٴμ��棬��ĺÿ��ġ�����\v\a
.wait 140
.message	2330	yuk-800_01-0119	#�D�@�q	�������Ѿ������ˡ����Ѿ�����������õ��˺ܶ�Ķ����ˡ�\v\a
.transition 0 * 10
.stage	vista_window2.png ev00_014a05_mugai_a.png 0 0
.message	2340	him-800_01-0083	#�@�[�@	��Ҫ�����𡭡���\v\a


.panel 0
.transition 0 * 10
.stage	vista_window2.png ev00_012a02.png 0 0
.panel 3
.message	2410	yuk-800_01-0121	#�D�@�q	���Բ���\v\a
.wait 110
.message	2420	him-800_01-0085	#�@�[�@	�����Ǹ������\v\a




.transition 0 * 13
.stage	vista_window2.png ev00_012a12.png 0 0
.panel 3
.message	2430			\aû���κ���Ҫ��Ǹ�����顣
.wait 50
.transition 0 * 7
.stage	vista_window2.png ev00_012a22.png 0 0
.message	2440			\a������ֻ�ǻ���һ˲��Ҳ�á�
.wait 100
.transition 0 * 7
.stage	vista_window2.png ev00_012a32.png 0 0
.message	2450			\aӦ���������ʱ������ٵģ��봫�ݸ�����˼������
.wait 130
.transition 0 * 7
.stage	vista_window2.png ev00_012a42.png 0 0
.message	2460			\a����Щ�������������ҲӦ�������ˡ�
.wait 100
.transition 0 * 7
.stage	vista_window2.png ev00_012a52.png 0 0
.message	2470			\a����֮�⣬�����������κ�����������
.wait 300




.panel 0
.playBGM * * 8
.transition 0 * 4
.stage	* BLACK.png 0 0
.wait 100
.playBGM *
.transition 0 * 10
.stage	* BLACK.png 0 0



.if ef_800_01 == 1 800_01_b1
.if ef_800_01 <= 0 800_01_a1

.label 800_01_a1
.movie2 ed.avi 800 600 ed.ogg 44100 2 f

.pragma disable_control

.goto 800_01_c1
.end

.label 800_01_b1
.movie2 ed.avi 800 600 ed.ogg 44100 2 t
.goto 800_01_c1
.end


.label 800_01_c1



.setGlobal ef_800_01 = 1

.pragma enable_control

.wait 600


.end

