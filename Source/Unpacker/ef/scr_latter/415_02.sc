.setGlobal EYE_SEQ_DEFAULT = 2


.if ef_418_01 == 1 ef_418_b1
.if ef_418_01 <= 0 ef_418_a1

.label ef_418_a1

.pragma disable_control

.goto ef_418_b1
.end

.label ef_418_b1


.playBGM efLAT05_21.ogg
.transition 0 * 10
.stage	* title_4back.png 0 0
.message	999			\a��
.wait 980

.transition 0 * 10
.stage	* WHITE.png 0 0

.pragma enable_control




.transition 0 * 10
.stage	vista_window.png WHITE.png 0 0
.panel 3
.message	100	mid-415_02-0003		һ�еĿ�ʼ�����������ء�����
.message	110	mid-415_02-0005		��ʼ����ϡ���ļ��䣬������������
.message	120	mid-415_02-0007		��ţ���������������һ�仰��
.transition 0 * 10
.stage	vista_window.png ev04_135a01.png 0 0
.message	130	yuk-415_02-0003	�D�@�q	����ô���أ���
.transition 0 * 20
.stage	vista_window.png WHITE.png 0 0
.message	140	mid-415_02-0009		���ұ��¶�Ժ����֮�󣬴���û�к�������˵������
.message	150	mid-415_02-0011		���¡�
.message	160	mid-415_02-0013		��Ҷ������¡�
.message	170	mid-415_02-0015		���£����£����£����£����£����£����£����£����¡�����
.transition 0 * 20
.stage	vista_window.png ago_base_40015a.png 0 0
.message	180	yuk-415_02-0005	�D�@�q	��ΪʲôҪ���أ���
.transition 0 * 20
.stage	vista_window.png WHITE.png 0 0
.message	190	mid-415_02-0017		���ǣ�ֻ������˵�������һ����
.message	200	mid-415_02-0019		��������ﱾ����ԣ�������˵��������ķ��ԡ�
.message	210	mid-415_02-0021		�������Ư��������ȴӡ�����Ҽ�į�����
.message	220	mid-415_02-0023		���ԡ�
.message	230	mik-415_02-0003	#���@��	����û�ޡ�
.message	240	mid-415_02-0025		������ʶ����⵽�����������ǰ�Ҳ��ܿޡ�
.message	250	mid-415_02-0027		������ý����ġ�
.transition 0 * 10
.stage	vista_window.png ev04_178.png 0 0
.message	260	mid-415_02-0029		�ҽ���ס̧����ͷ��


.panel 0
.transition 0 * 10
.stage	vista_window.png ev05_163b01.png 0 0
.transition 0 * 10
.stage	vista_window.png ev05_163b01_mugai.png 0 0
.panel 3
.message	270	mid-415_02-0031		����ǣ��Һ��깬����С���������



.transition 0 * 10
.stage	vista_window.png WHITE.png 0 0
.message	280	mid-415_02-0033		�ţ��ٸ����������������������ɡ�



.panel 0
.transition 0 * 10
.stage	vista_window.png ev05_181a04.png 0 0
.transition 0 * 10
.stage	vista_window.png ev05_181a04_mugai.png 0 0
.panel 3
.message	290	yuk-415_02-0007	�D�@�q	������ֵĵط��������ء������������ô����
.message	300	mik-415_02-0005	#���@��	���̻�ǰ�桹
.transition 0 * 40
.stage	vista_window.png ev05_181a05_mugai.png 0 0
.message	310	yuk-415_02-0009	�D�@�q	���̻�ǰ����
.message	320	mik-415_02-0007	#���@��	���ڽ̻�ǰ������ȥ�����ԣ���ʦ˵��
.message	330	mik-415_02-0009	#���@��	����Ϊ�г�������Σ�ա�Ҫ��Ļ����ڹ�԰�棬��ô˵��
.message	340	yuk-415_02-0011	�D�@�q	��ȷʵ��������Ŷ��
.message	350	mid-415_02-0035		ͻȻ������С��СС���������Դ���
.message	360	yuk-415_02-0013	�D�@�q	��Ϊʲôδ�����ڽ̻�ǰ�أ���
.transition 0 * 40
.stage	vista_window.png ev05_181a06_mugai.png 0 0
.message	370	mik-415_02-0011	#���@��	�����������������Լ����¡�
.message	380	yuk-415_02-0015	�D�@�q	���ѵ��ǡ�����
.transition 0 * 40
.stage	vista_window.png ev05_181a07_mugai.png 0 0
.message	390	yuk-415_02-0017	�D�@�q	�����ڵ�����ô����
.message	400	mik-415_02-0013	#���@��	�����ǣ���
.transition 0 * 40
.stage	vista_window.png ev05_181a08_mugai.png 0 0
.message	410	mik-415_02-0015	#���@��	�����ǡ����ߡ�


.transition 0 * 20
.stage	vista_window.png WHITE.png 0 0
.message	420	mid-415_02-0037		��Ϊ��į��
.transition 0 * 20
.stage	vista_window.png ago_base_40015o3.png 0 0
.message	430	mid-415_02-0039		��Ϊ����һ���ˡ�



.panel 0
.transition 0 * 10
.stage	vista_window.png ev05_209a01.png 0 0
.transition 0 * 10
.stage	vista_window.png ev05_209a01_mugai.png 0 0
.panel 3
.message	440	yuk-415_02-0019	�D�@�q	�����ˣ��������С�������Ҫ����ġ�����
.message	450	yuk-415_02-0021	�D�@�q	��������ȥ���ء�����
.message	460	mik-415_02-0017	#���@��	��������û��ϵ�ģ���
.message	470	yuk-415_02-0023	�D�@�q	��֮����ȥ���Ұɡ�����
.message	480	mik-415_02-0019	#���@��	�������¡���û��ϵ�ġ�����
.message	490	yuk-415_02-0025	�D�@�q	��δ����������Ŷ���������ֱ��顭����
.message	500	yuk-415_02-0027	�D�@�q	��Ů���ӣ�Ҫ����΢Ц�ţ�������õġ�����



.transition 0 * 20
.stage	vista_window.png ago_base_40015o1.png 0 0
.message	510	mid-415_02-0041		��֪���ˡ�
.transition 0 * 20
.stage	vista_window.png ago_base_40015o2.png 0 0
.message	520	mid-415_02-0043		Լ���ˡ�
.transition 0 * 20
.stage	vista_window.png ev04_136a01.png 0 0
.message	530	mid-415_02-0045		���ԣ������ʧ����
.message	540	mid-415_02-0047		����С�㡭��
.panel 0
.transition 0 * 10
.stage	vista_window.png WHITE.png 0 0




.transition 0 * 10
.stage	vista_window.png ev04_134a01.png 0 0
.panel 3
.message	550	mid-415_02-0049	#�~�Y�L	������������Ҫ���ϵ�л�������ء�
.message	560	mid-415_02-0051		�ҿ��Ž̻���ǰ���ĵ�·��

.message	570	him-415_01-0081	�@�[�@	��������ʲô��������Ϊ����ȥ��˫�ף�����ǰ����ɽˮ��������ô����

.message	580	mid-415_02-0053	#�~�Y�L	�����ǡ���Ϊ���깬����С������ġ�
.message	590	him-415_02-0005	�@�[�@	��������������
.message	600	mid-415_02-0055	#�~�Y�L	����Ȼ��ģ���Ҫ�������ĵط����ϵ��ء�
.message	610	him-415_02-0007	�@�[�@	�����ǡ�����
.message	620	mid-415_02-0057	#�~�Y�L	������
.panel 0
.vscroll	800	10
.endScroll f
.panel 3
.message	640	him-415_02-0009	�@�[�@	������˭����
.transition 0 * 20
.stage	vista_window.png ago_base_40015l.png 0 0
.message	650	mid-415_02-0061		����������ţ���ֱ�ͺ���һ��ľ�������һ���������Ӻڰ�������������վ�š�
.message	660	mid-415_02-0063		��ک�������������������У�ֻ���������ƾܾ�����һ��ĺڰ����ڡ�
.message	670	mid-415_02-0065		������ʶ�Ľ������¡�
.message	680	mid-415_02-0067	#�~�Y�L	���Ǹ�������


.transition 0 * 20
.stage	vista_window.png ev04_137a02.png 0 0

.message	690	him-415_02-0011	�@�[�@	��Ҫ��ڵ�������ʲô��
.message	700	mid-415_02-0069		�������ʣ�����˵��ڵ�ʵ�������
.message	720	mid-415_02-0073		����ס��̧���˺�����
.message	730	mid-415_02-0075	#�~�Y�L	���Ǹ��������ǣ�������̻������ġ�����
.message	740	mid-415_02-0077		���﹣���ˡ�
.message	750	mid-415_02-0079		���޷��������������������
.message	760	mid-415_02-0081		���������˵��Ҳ����Ҫ������ɡ�
.message	770	mid-415_02-0083		���ԣ�������ĺ������£����Լ��������侲������
.transition 0 * 10
.stage	vista_window.png ev04_138a01.png 0 0
.message	780	mid-415_02-0085	#�~�Y�L	�������Һܺ��±��ˡ�
.message	790	mid-415_02-0087		ÿ����˭Ҫ�����ҵ�ʱ��
.message	800	mid-415_02-0089		����ֵ����顣
.message	810	mid-415_02-0091		�Ҿ͸о�Ҫ���Ҳ��ӡ�
.message	820	mid-415_02-0093		Ҫ�������뺣��һ����
.transition 0 * 20
.stage	vista_window.png ev04_138a02.png 0 0
.message	830	mid-415_02-0095	#�~�Y�L	���Ǹ�ʱ�򡭡���
.message	840	mid-415_02-0097		��Ȼ�������������ᡣ
.message	850	mid-415_02-0099		ֱ������,�Ǹ�ʱ�ھ����Ŀֲ������ɲд����Ժ����ĳ�����䡣
.message	860	mid-415_02-0101		�ҵ���Ƭ��
.message	870	mid-415_02-0103	#�~�Y�L	��ѧУҲ��ȥ��ԭ���ڹ¶�Ժ��Ŀ�������Ҳ���¡�����
.transition 0 * 20
.stage	vista_window.png ev04_138a03.png 0 0
.message	880	mid-415_02-0105	#�~�Y�L	����Ϊ��㱻������ĸɱ���������Ը��������ű��ˡ�
.message	890	mid-415_02-0107	#�~�Y�L	������������һ���к���û���������
.message	900	mid-415_02-0109	#�~�Y�L	������Է�����һ���˵Ļ�θ�ͽ��ܲ��ˡ������˭��һ��˵���Ļ����Ҿͱ���޷�����������
.transition 0 * 20
.stage	vista_window.png ev04_138a03_mugai_a.png 0 0
.message	910	mid-415_02-0111	#�~�Y�L	���������û���������ҵ��ˣ���һֱ�ڽ̻����Ա��š�
.message	920	mid-415_02-0113		���ڴ���������
.transition 0 * 20
.stage	vista_window.png ev04_138a05.png 0 0
.message	930	mid-415_02-0115	#�~�Y�L	���Ǹ�ʱ���Һ��Ǹ��������ˡ�����


.transition 0 * 20
.stage	vista_window.png ev04_178.png 0 0
.message	940	yuk-415_02-0029	�D�@�q	����ô���أ���


.transition 0 * 20
.stage	vista_window.png ev04_138a06.png 0 0
.message	950	mid-415_02-0117	#�~�Y�L	��������������Ц�ţ�ȫ�������Ǹ��˵Ĺ��͡�
.message	960	mid-415_02-0119		�������ˡ�
.transition 0 * 20
.stage	vista_window.png ev04_138a01.png 0 0
.message	970	mid-415_02-0121	#�~�Y�L	���������ˡ���Ϊ�˱�������ȥ�ˡ�
.transition 0 * 20
.stage	vista_window.png ev04_139.png 0 0
.message	980	mid-415_02-0123		�������ҡ�
.transition 0 * 20
.stage	vista_window.png ago_base_40015m.png 0 0
.message	990	mid-415_02-0125		��������ȫû�ж�Ӧ��ֵ�ĺ��ӡ�
.transition 0 * 20
.stage	vista_window.png ev04_138a04.png 0 0
.message	1000	mid-415_02-0127	#�~�Y�L	���������ǡ�
.message	1010	mid-415_02-0129		���ǡ�
.transition 0 * 20
.stage	vista_window.png ev04_138a02.png 0 0
.message	1020	mid-415_02-0131	#�~�Y�L	������Ϊ��ˣ��Ҳ����Զ�ҡ��
.message	1030	mid-415_02-0133		�������׵���ͷ��


.transition 0 * 20
.stage	vista_window.png ev04_138a01.png 0 0
.message	1040	mid-415_02-0135	#�~�Y�L	����ʹ�Լ�û�м�ֵ�����塭����
.transition 0 * 20
.stage	vista_window.png ev04_140a01.png 0 0
.message	1050	mid-415_02-0137	#�~�Y�L	������Ҫ��������Ư�������ǲ����ܵġ�����
.transition 0 * 20
.stage	vista_window.png ev04_140b01.png 0 0
.message	1060	mid-415_02-0139	#�~�Y�L	��������������Ϊ�˸����Ǹ��ˣ�����Ŭ����
.transition 0 * 40
.stage	vista_window.png ev04_140b02.png 0 0
.message	1070	mid-415_02-0141	#�~�Y�L	���Ҿ����ˣ�Ҫ�����������ս�������һ�̣���
.transition 0 * 20
.stage	vista_window.png ev04_141a01.png 0 0
.message	1080	mid-415_02-0143		����ҪЦ�����һ�̡�
.message	1090	mid-415_02-0145	#�~�Y�L	�����ң�������������С�㡹
.message	1100	mid-415_02-0147	#�~�Y�L	��Ҳ�г�Ϊ��Ŀ���ǰ���ǡ�



.transition 0 * 20
.stage	vista_window.png ev01_032_mugai.png 0 0
.message	1110	mid-415_02-0149	#�~�Y�L	�����˽̻����ң�Ϊ���ܼ���ʵ���Լ������롪��Ϊ���ػ�ס��Ҫ���ˣ�ѡ�����ѵĵ�·����Ҫ�ԡ�

.panel 0
.transition 1 fadeSide.png 20
.stage	vista_window.png ev01_032b01.png 0 0
.transition 1 fadeSide.png 20
.stage	vista_window.png ev01_203_mugai02.png 0 0
.panel 3
.message	1120	mid-415_02-0151	#�~�Y�L	�����˽̻����ң���ʹ����Ҳ���ٶ�վ������������

.panel 0
.transition 1 fadeSide.png 20
.stage	vista_window.png ev01_203_mugai.png 0 0
.transition 1 fadeSide.png 20
.stage	vista_window.png ev03_046_mugai.png 0 0
.panel 3
.message	1130	mid-415_02-0153	#�~�Y�L	���Ǽһ�Ҳ�ǣ���˭����ȥ�����ò�������״���£�ץס��һ��һ���ϣ������


.panel 0
.transition 1 fadeSide.png 20
.stage	vista_window.png ev03_046.png 0 0
.transition 1 fadeSide.png 20
.stage	vista_window.png ev04_141b01.png 0 0
.panel 3
.message	1140	mid-415_02-0155	#�~�Y�L	���������ҵ����У����ֻ���һ��һ���������š�
.transition 0 * 20
.stage	vista_window.png ev04_141b02.png 0 0
.message	1150	mid-415_02-0157	#�~�Y�L	����Ȼ������û����ȫ�Ĵ𰸡�
.transition 0 * 20
.stage	vista_window.png ev04_141b03.png 0 0
.message	1160	mid-415_02-0159	#�~�Y�L	������Ϊ�����Լ��Ҹ������ñ��˿��������飬Ҳ������Ϊ���±��˷����˺��˱��˵����顭����
.transition 0 * 20
.stage	vista_window.png ev04_141b04.png 0 0
.message	1170	mid-415_02-0161	#�~�Y�L	�����ǣ��������ֵĲ���ȫ��Ҳֻ��һ����Ƭ��
.message	1180	mid-415_02-0163	#�~�Y�L	�����޷������ֶ����ϣ��ƿ��ҵ����ߡ�
.message	1190	mid-415_02-0165	#�~�Y�L	����ֱ��������ǿ������С����������ʵ������Щ��Ŷ���ͬ���һ����
.message	1200	mid-415_02-0167	#�~�Y�L	��������ֻ����ǲ��еġ�ֻ�У�ֻ�ɶԣ�����չ��������������
.transition 0 * 20
.stage	vista_window.png ev04_141a02.png 0 0
.message	1220	mid-415_02-0171	#�~�Y�L	�����࡭��һ��֮����������������ʮ�����޵ġ�
.transition 0 * 20
.stage	vista_window.png ev04_141a03.png 0 0
.message	1230	mid-415_02-0173	#�~�Y�L	�����ǣ�����Ϊ����������õġ�
.transition 0 * 20
.stage	vista_window.png ev04_141a01.png 0 0
.message	1240	mid-415_02-0175	#�~�Y�L	���ܳ������������ȫ������̫���ˣ���������ô��Ϊ��
.transition 0 * 20
.stage	vista_window.png ev04_141a04.png 0 0
.message	1250	mid-415_02-0177	#�~�Y�L	�����ԣ�����Ϊһ���˺ܼ�į�����ԲŻ�ȥѰ����ˡ�
.message	1260	mid-415_02-0179		��ţ�����С��Ҳ�������İɡ�
.message	1270	mid-415_02-0181		�������Ǹ��·�����ʹһ����ˣ�Ҳ��������֪������Ϊ��ͨ�˵�һ��ɡ�
.message	1280	mid-415_02-0183		���ң�������������Ҳһ����
.transition 0 * 20
.stage	vista_window.png ago_base_40015n.png 0 0
.message	1290	mid-415_02-0185		�����ǰ���
.message	1300	mid-415_02-0187		�����ڣ����ڷ����ˡ�
.message	1310	mid-415_02-0189		����������������Ϊ�Ǹ��ˣ�������С�����ơ�
.transition 0 * 20
.stage	vista_window.png ago_base_40015n2.png 0 0
.message	1320	mid-415_02-0191	#�~�Y�L	�����ԡ������ԡ�����
.message	1330	mid-415_02-0193	#�~�Y�L	���Ǹ���������
.message	1340	mid-415_02-0195		���֣�
.message	1350	mid-415_02-0197		��ͻȻ��һ��ʼ����������ˡ�
.transition 0 * 20
.stage	vista_window.png ago_base_40015n3.png 0 0
.message	1360	mid-415_02-0199		��������ղţ�����ʲô���ţ�
.message	1370	mid-415_02-0201		����������
.message	1380	mid-415_02-0203	#�~�Y�L	���ܣ��ܶ���֮����Ҫ��Ϊ����С�������츣��ҵ��ˣ���
.message	1390	mid-415_02-0205	#�~�Y�L	�����ϣ���
.message	1400	mid-415_02-0207		��Ȼ���ķ��Ժܣϣңڣ��������������е�ȫ����

.transition 0 * 20
.stage	vista_window.png ev04_142a02.png 0 0

.message	1410	him-415_02-0013	�@�[�@	������������
.message	1420	mid-415_02-0209		��������������Ŀ�⡣
.transition 0 * 20
.stage	vista_window.png ev04_143_mugai_a.png 800 0

.hscroll	0	-14

.endScroll f
.message	1430	mid-415_02-0211		����������֡�
.transition 0 * 20
.stage	vista_window.png ev04_143_mugai_b.png 0 0
.message	1440	mid-415_02-0213		��ͷ������
.transition 0 * 20
.stage	vista_window.png ev04_143.png 0 0
.message	1450	him-415_02-0015	�@�[�@	������������

.transition 0 * 20
.stage	vista_window.png ev04_142b01_mikage.png 0 0

.message	1460	him-415_02-0017	�@�[�@	������������
.message	1470	mid-415_02-0215	#�~�Y�L	�����٣���

.transition 0 * 20
.stage	vista_window.png ev04_142b01.png 0 0

.message	1480	mid-415_02-0217		������������ֱ۴���̾�˿�����������Ҵ���ľ���ˡ�
.transition 0 * 40
.stage	vista_window.png ev04_142c01.png 0 0
.message	1490	him-415_02-0019	�@�[�@	���������ɶ��������ڵģ���
.transition 0 * 20
.stage	vista_window.png ev04_142b02.png 0 0
.message	1500	him-415_02-0021	�@�[�@	��������Ϊ����һ�ɶ����ˡ�����
.transition 0 * 20
.stage	vista_window.png ev04_134a01.png 0 0
.message	1510	mid-415_02-0219		���ֿ�ǰ����������ա�
.message	1520	him-415_02-0023	�@�[�@	���Ǹ����˵����鵽��������������ˡ�������Ƶ�һ���
.message	1530	him-415_02-0025	�@�[�@	����ã�Ų�֪������ô�����Ҳ̫���˰���
.message	1540	him-415_02-0027	�@�[�@	������������������ŵĻ���
.message	1550	him-415_02-0029	�@�[�@	���Ѿ���û���ˡ�
.transition 0 * 20
.stage	vista_window.png ev04_142b04.png 0 0
.message	1560	mid-415_02-0221	#�~�Y�L	��������
.transition 0 * 40
.stage	vista_window.png ev04_142b05.png 0 0
.message	1570	him-415_02-0031	�@�[�@	����ˡ�㡹
.transition 0 * 20
.stage	vista_window.png ev04_142b05_mugai_a.png 0 0
.message	1580	mid-415_02-0223		�������������������ҵļ��
.transition 0 * 20
.stage	vista_window.png ev04_142b05.png 0 0
.message	1590	mid-415_02-0225		��Ϊ̫ͻȻ�ˣ���û��Ӧ�ϡ�
.message	1600	him-415_02-0033	�@�[�@	��������ڰɡ�
.message	1610	mid-415_02-0227	#�~�Y�L	�����������ԡ�
.message	1620	him-415_02-0035	�@�[�@	�������Ļ��ҵ�������ǿ�ˡ�㡹
.transition 0 * 40
.stage	vista_window.png ev04_142b06.png 0 0
.message	1630	him-415_02-0037	�@�[�@	����Ϊ���˵������������������ˡ��

.transition 0 * 40
.stage	vista_window.png ev04_142b07.png 0 0

.message	1640	mid-415_02-0229		���ű��˵�Ц�š�


.message	1650	him-415_02-0039	�@�[�@	�������ٱ��������ˣ����Ǹ����⻨��һ���������ɡ�
.message	1660	mid-415_02-0231	#�~�Y�L	����������
.message	1670	mid-415_02-0233		Ϊʲô�������һ��Ҫ˵������ز����Ҳ��Ǻ����ס�
.message	1680	mid-415_02-0235		���ǣ��Ҳ��Ծ��ذ����ˡ�
.message	1690	mid-415_02-0237		�����������һ˵�Ļ�������
.message	1700	mid-415_02-0239		��֪��Ϊʲôȫ��������������
.message	1710	mid-415_02-0241	#�~�Y�L	������������
.transition 0 * 40
.stage	vista_window.png ev04_142b08.png 0 0
.message	1720	him-415_02-0041	�@�[�@	�������У��㣬˵�Ƕ����һ��ǲ���һ�¡�
.message	1730	mid-415_02-0243		���ص���ƽʱ���ſ������ת�ƿ������ߡ�
.transition 0 * 40
.stage	vista_window.png ev04_142b09.png 0 0
.message	1740	him-415_02-0043	�@�[�@	�������Ҫ�ñ����Ҹ��Ļ�����Ҫ���Լ��Ҹ�������
.message	1750	him-415_02-0045	�@�[�@	�����������Ҫ�����项
.message	1760	mid-415_02-0245	#�~�Y�L	�������յ����һ�Ŭ���ġ�
.transition 0 * 40
.stage	vista_window.png ev04_142b10.png 0 0
.message	1770	him-415_02-0047	�@�[�@	������Ҳ���и����ˡ�
.message	1780	mid-415_02-0247	#�~�Y�L	��������
.transition 0 * 40
.stage	vista_window.png ev04_142b11.png 0 0
.message	1790	him-415_02-0049	�@�[�@	���ҿ�û�������Ǽһ���ʲô�ഺ����
.message	1800	mid-415_02-0249		��������ô���ء�
.message	1810	mid-415_02-0251		��������ԳԵ�Ц�š����о���������������ʲô�����а��һ��Ц��������á�
.message	1820	him-415_02-0051	�@�[�@	�����Ը���֧���𣿡�
.message	1830	mid-415_02-0253	#�~�Y�L	���������������롹
.message	1840	mid-415_02-0255		��΢ɨ��һ�ۣ���һ֧���ŵĲ���Ļ��ݸ��˻��������
.message	1850	mid-415_02-0257		��һ�߽����Ǹ�һ�߿�Ц��˵��
.transition 0 * 20
.stage	vista_window.png ev04_142d01.png 0 0
.message	1860	him-415_02-0053	�@�[�@	�����ٸ�һ֧����ȻС���Ҳ����
.message	1870	mid-415_02-0259	#�~�Y�L	�������õġ�
.transition 0 * 20
.stage	vista_window.png ev04_142e01.png 0 0
.message	1880	him-415_02-0055	�@�[�@	��лл��
.message	1890	mid-415_02-0261		��֧����ʲô������
.message	1900	mid-415_02-0263		�������ת�Ż����ս����ӡ�
.transition 0 * 20
.stage	vista_window.png ev04_142f01.png 0 0
.message	1910	him-415_02-0057	�@�[�@	�������������ζ��
.message	1920	mid-415_02-0265	#�~�Y�L	�����ۡ�
.transition 0 * 40
.stage	vista_window.png ev04_142f02.png 0 0
.message	1930	him-415_02-0059	�@�[�@	����ô�ˣ���
.message	1940	mid-415_02-0267	#�~�Y�L	������������ûʲôûʲô��
.message	1950	mid-415_02-0269		˧�Ĳ���ұ�Ѫ�������ˡ�
.message	1960	mid-415_02-0271		��Ȼ���о�����ǧ��֮�⣬������һ�̣�ֻ����й¶����һ�����飬����˾ͱ�÷ǳ���˧��
.transition 0 * 20
.stage	vista_window.png ev04_144a01_big.png 800 750
.message	1970	him-415_02-0061	�@�[�@	�����ǣ�ΪʲôͻȻ�û�������ÿ�궼�͵��𣿡�
.panel 0
.hscroll	428	-10
.endScroll f
.panel 3
.message	1980	mid-415_02-0273	#�~�Y�L	�����ǣ�ֻ����������
.panel 0
.vscroll	299	-10
.endScroll f
.panel 3
.message	1990	mid-415_02-0275		��������ǧѰǰ�����ռǡ�
.panel 0
.scroll	800 0	10
.endScroll f
.panel 3
.message	2000	mid-415_02-0277		����֪�����ǲ����ܵġ�
.panel 0
.scroll	428 750	10
.endScroll f
.panel 3
.message	2010	mid-415_02-0279	#�~�Y�L	����˵���깬����С���������Ľ̻��
.panel 0
.hscroll	800	10
.endScroll f
.panel 3
.message	2020	him-415_02-0063	�@�[�@	������������
.transition 0 * 20
.stage	vista_window.png ago_base_40015h3.png 0 0
.message	2030	mid-415_02-0281	#�~�Y�L	����Ȼ�������������ǲ����ܵġ������ǣ���Ҷ������ˣ��깬����С�㡹
.transition 0 * 20
.stage	vista_window.png ev04_144a01.png 0 0
.message	2040	mid-415_02-0283		�Ұ��ַ��ڷ��ȵ�ʯ���ϣ�������΢����󣬷����˻�����
.transition 0 * 20
.stage	vista_window.png ago_base_40015h1.png 0 0
.message	2050	mid-415_02-0285		��Ҳ�Ѿ�л�ˡ�
.transition 0 * 20
.stage	vista_window.png ago_base_40015h2.png 0 0
.message	2060	mid-415_02-0287		Ϊ�������ұ������۾���
.transition 0 * 20
.stage	vista_window.png ago_base_40015h2_close.png 0 0
.message	2070	mid-415_02-0289	#�~�Y�L	������һֱ�����ڵ���ʲô�ˡ�
.transition 0 * 10
.stage	* vista_white.png 0 0
.panel 0
.playBGM *
.transition 0 * 10
.stage	* WHITE.png 0 0
.transition 0 * 10
.stage	* WHITE.png 0 0
.wait 100

.chain 416_01.sc
