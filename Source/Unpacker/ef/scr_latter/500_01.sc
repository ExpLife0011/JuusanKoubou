.setGlobal EYE_SEQ_DEFAULT = 2

.transition 0 * 10
.stage	* BLACK.png 0 0
.wait 200



.transition 0 * 10
.stage	* BLACK.png 0 0
.panel 3
.message	100	him-500_01-0003	#�@�[�@	���������Ļ������ܻ�����ôһ�ָо���\v\a
.wait 100
.message	110	him-500_01-0005	#�@�[�@	�Ҵ����类����ֿ��ĸо���\v\a
.wait 150
.message	120	him-500_01-0007	#�@�[�@	��Ȼϣ��������֪���Լ��Ĵ��ڣ�ȴ��֪���Լ�����Щʲô�á�\v\a
.wait 150
.message	130	him-500_01-0009	#�@�[�@	��˼�į��\v\a
.wait 100
.message	140	him-500_01-0011	#�@�[�@	��˱��ˡ�\v\a
.wait 200
.message	150	him-500_01-0013	#�@�[�@	�����ŵ�ʱ���У�ֻ�б��˵������ڲ��ϵ��ջ����ۣ������������޷������������顣\v\a
.wait 200
.message	160	him-500_01-0015	#�@�[�@	�ң���������\v\a
.panel 0


.transition 0 * 10
.stage	* WHITE.png 0 0

.playSE kane_ef.ogg f
.transition 0 * 10
.stage	* title_summer.png 0 0
.message	999			\a��
.wait 1000
.playSE *

.transition 0 * 10
.stage	* WHITE.png 0 0





.wait 150
.playBGM efLAT05_02.ogg




.transition 0 * 10
.stage	* bgc_sch002a01_02_pastm3.png 0 0
.panel 1

.message	858			������ͼ��ݵ�ѧϰ���������ȡ�
.transition 0 * 20
.stage	* bgc_sch002a01_02_pastm2.png 0 0
.message	868			���ܾ���������������Ӱ����������
.transition 0 * 20
.stage	* bgc_sch002a01_02_pastm.png 0 0
.message	878			ƽʱӦ�û������Ż����ίԱ�Ṥ����ѧ���ڵģ�Ϊʲô������˰����ء�
.message	888			���Լ�����������������˳Ծ���
.message	898			��Ⱦ��������������ȣ��ڰ�����Ȼ���ܲ������⡣
.message	908			���������Ŷ��ѣ������Ǻ���䤱���
.transition 0 * 20
.stage	past_window.png bgs_sch009a01_02.png 0 0
.message	918			����Ь�ӣ��߳���ѧ¥��
.message	928			��д�������������������ȵĿ�������ȫ��
.message	938			�ٴ����Ҿ��쵽�����������졣
.message	948			�Ҳ����������졣
.message	958			���������Ķ��죬�����ҵ��������������ɫ�͹�â�ļ��ڵ����ɡ�
.message	968			�������ᣬ��
.message	978			�ҷ���������ˡ�
.message	988			����ֻ�ᱻ�ҷ�Ϊ�����������������ֶ��ѡ�
.message	998			��Ʋ����ǽ�ȫ�����淽ʽ�������Ҷ��Կ�Ц������
.message	1008			���淽ʽ����
.transition 0 * 20
.stage	past_window.png ev00_004_mugai_h2.png 781 1037
.message	1018			������ա�
.message	1028			����ϣ�������淽ʽ�ǡ���
.message	1038		�@�[�@	������ʲô��������
.transition 0 * 20
.stage	past_window.png ev00_004_mugai_h2.png 781 1037
.scroll	581 837	6
.endScroll f
.message	1048			���Ǳ�Ϧ��Ⱦ�����գ�һƬϸС�İ�ɫ�����趯��
.transition 0 * 20
.stage	* ev00_004.png 0 0
.message	1058			���ǡ���һ��ֽ�ɻ���



.panel 0
.transition 0 * 10
.stage	* final_terop_a1.png 0 0
.wait 100
.transition 0 * 10
.stage	* final_terop_a2.png 0 0
.message	5999			\a��
.wait 500
.transition 0 * 10
.stage	* final_terop_a1.png 0 0
.wait 50



.transition 0 * 10
.stage	* ev00_005.png 0 0
.panel 1
.message	1068		�@�[�@	������ı����ӳ����ġ�
.message	1078			������Ʈ���ڵص�ֽ�ɻ���
.message	1088			�������ˣ�����ѧУ�ﻹ�����ĸ��������������Ķ�����
.transition 0 * 20
.stage	* ev00_006_mugai_d.png 0 600
.message	1098			�Ҵ���Щ��ľ��ȣ���ʼһ������ȷ�Ͻ�ѧ¥�Ĵ�����
.transition 0 * 20
.stage	* ev00_006_mugai_d.png 0 600
.vscroll	0	-10
.endScroll f
.message	1108			������Ϊ���˿����Ѿ���ʧ��ʱ�򡭡���
.message	1118		�@�[�@	����������
.transition 0 * 20
.stage	* ev00_006_mugai_a.png 0 0
.message	1128			һ����Ů����Ӱ���������ҵ����ߡ�
.message	1138			���Ҳ�֪Ϊ�Σ���Ů�������ݶ��ı�Ե������ҡ�����Լ���˫�㡣
.transition 0 * 20
.stage	* ev00_006.png 0 0
.message	1148			�����ֵط���ʲô�ء�
.message	1158			���������������
.message	1168			ͻȻ�������ҵ����ʽ���ӿ����ʱ��
.message	1178			��Ȼ���ź�Զ����ȴ����ؿ����ˡ�
.message	1188			��Ů��ֹͣ�˽ŵĻζ��������·����ҡ���΢Ц������




.transition 0 * 10
.stage	* bgs_sky001a01_02_mugai_a.png 0 0
.message	1198			�������ţ���ս��ķ·��ֿɼ���
.message	1208			���޵�糺�ɫ���쵽�����˲�������Ϧ�����ϱ��׹�½������ȼ���Ĵ����
.message	1218			����ƬŪʹ�۾����ɫ֮�С���
.transition 0 * 10
.stage	* ev00_007a01_mugai_a.png 0 0
.message	1228			��Ů��΢Ц�š�
.transition 0 * 20
.stage	* ev00_007a02.png 0 0
.message	1238		�@�[�@	������Ϊʲô�Ƕ�������
.message	1248			��Ȼ��������������������������ʹ�ȥ��
.message	1258			����˵�����޷�˵��ʲô���ʵĻ�����
.message	1268			��ǰ�Ĺ⾰��������������������ʧȥ��ʵ�С�
.message	1278			������Ȼ�ǵ�һ�����ݶ�����������Ȼ���е�դ��ȴû�����Ҳ��������Щ�Ծ���
.transition 0 * 40
.stage	* ev00_007a03.png 0 0
.message	1288	yuk-000_01-0055	@�D�@�q	����������
.message	1298			����ǿ�ҵĲ�Э��������Ⱦ���ľ�ɫ�У�������Ů����һ��ͷ��
.message	1308		�@�[�@	���㴩�Ĳ��Ƕ�����
.message	1318		�@�[�@	�����ǲ�֪��ʲô�л��·��أ���
.transition 0 * 40
.stage	* ev00_007a01.png 0 0
.message	1328	yuk-000_01-0057	@�D�@�q	������������·��������ķ�Ŷ��
.message	1338		�@�[�@	��������
.message	1348			�����·�����ô����������ѧ԰�Ķ�����
.message	1358			����������ʵʵ�������˾�����ֵ��������׶����š�
.transition 0 * 40
.stage	* ev00_007a02.png 0 0
.message	1368	yuk-000_01-0059	@�D�@�q	�����촩���·��Žж������������촩���������ķ��������𣿡�
.message	1378		�@�[�@	����ȫ���Եİɡ�����
.message	1388			�����ǲ����ó���˵���ˡ�
.transition 0 * 40
.stage	* ev00_007a01.png 0 0
.message	1398	yuk-000_01-0061	@�D�@�q	��������������Ȼż���ᱻ��˵�����ž;����ȵ����ܡ�����
.message	1408			������˵Ҳ��������Ȼ�İɡ�
.message	1418			���������ȵ�ʱ���ﴩ�������·�����Ȼ�����˾��ò��ʡ�
.transition 0 * 40
.stage	* ev00_007a02.png 0 0
.message	1428	yuk-000_01-0063	@�D�@�q	����̫�봩���䡹
.message	1438	yuk-000_01-0065	@�D�@�q	����ǰ����΢������Щ���ء�
.message	1448			��һ��˵�ţ�һ�߸����·����ḧĦ�Լ�������
.message	1458	yuk-000_01-0067	@�D�@�q	����ʱ�Ǿ�������ν���������ڵ���΢�����Ͱ�������
.message	1468		�@�[�@	����û��Ҫ�ٸ��ʵ׵���˼��
.message	1478			��������Ů������˼����������Ļ���
.message	1488			����ǣ�ͯ���ʱ���ܹ��˶����µĴ��ڰɡ�
.message	1498			�������͵�Ů�����������˿ڲ��뱻����Ҳ�޿ɺ�ǡ�
.message	1508			���̶ֳȵ������һ��Ƕ��ģ��������濴�����Ļ�����
.message	1518			��Ů�����Ŷ��������ֲ���˼����ʺϸС�
.message	1528			��Ȼ�������Ļ��ҿɲ���˵���ڡ�
.transition 0 * 40
.stage	* ev00_007a01.png 0 0
.message	1538	yuk-000_01-0069	@�D�@�q	��˵������������ר��Ϊ��˵���俴�������Ȳ����İɣ���
.message	1548		�@�[�@	����ô���ܡ�
.message	1558			��ҡ��ҡͷ�������˱�����Ŀ�ġ�
.transition 0 * 20
.stage	* ev00_008a01.png 0 0
.message	1568		�@�[�@	����˵�㰡���ݶ��ǽ�ֹ�����Ŷ��
.message	1578			�������Ӧ���Ǳ���ס�ĲŶ԰�������ΰ����򿪵�Ҳ��һ���ա�
.transition 0 * 40
.stage	* ev00_008a02.png 0 0
.message	1588	yuk-000_01-0071	@�D�@�q	���㲻��Ҳ��������
.message	1598			��Ů¶������ִ�ֵ����顣
.message	1608		�@�[�@	��������������ġ��ɱ𳶿�����Ŷ��
.transition 0 * 40
.stage	* ev00_008a03.png 0 0
.message	1618	yuk-000_01-0073	@�D�@�q	�����˿������ǵ�һ���ء���ϧ����ϧ��
.message	1628			����ȫ�벻����ΪʲôҪ˵��ϧ�����ɡ�
.message	1638		�@�[�@	�������Ҳ��ǽ�ʦ��������ô�����ģ���
.message	1648			����ѧ԰���ݶ���ֹ������롪��������ô˵��ֻ����ѧ֮�����˵����£�֮ǰ���������ݶ��Ĵ��ڰɡ�
.message	1658			�������˵����ط�ѧ����Ӧ�ò���Ϥ�Ŷԡ�
.transition 0 * 40
.stage	* ev00_008a01.png 0 0
.message	1668	yuk-000_01-0075	@�D�@�q	�����������������
.message	1678	yuk-000_01-0077	@�D�@�q	���������Ĳ���ԱŶ��ӵ�п��Խ����ݶ����ر���ɡ�
.message	1688		�@�[�@	��Ҫ���ѵĻ���Ҳ��Щ�������ĳ����ɡ�
.message	1698		�@�[�@	��������ʱ����ô���ܿ���ʲô���ǡ���˵������ѧУ�����Ĳ��𣿡�
.message	1708			����ȥ�Ļ���Ҳû����������Զ��֮������ߡ�
.transition 0 * 40
.stage	* ev00_008a03.png 0 0
.message	1718	yuk-000_01-0079	@�D�@�q	����Ȼ�а���ֻ�Ǵ�������ϲ��˶��ѡ�
.message	1728		�@�[�@	���ϲ�����
.transition 0 * 40
.stage	* ev00_008a04.png 0 0
.message	1738	yuk-000_01-0081	@�D�@�q	���ţ����꼶��ǰ������һ�������ˡ�û�У��꼶�Ĳ�Ա��ʣ�µ�ֻ�У��꼶���Ҷ��ѡ�
.message	1748		�@�[�@	��ֻ�У��꼶����
.message	1758			��Ȼ���ף������ŮӦ�����ҵĺ󱲡�
.message	1768			��ֱ�۵Ŀ������������������С�������ꡣ
.transition 0 * 40
.stage	* ev00_008a03.png 0 0
.message	1778	yuk-000_01-0083	@�D�@�q	����Ȼ�һ�����᲻������������ʱ�벿�ء�����ϧ�������û��ôһ����˳����
.message	1788		�@�[�@	��ֻ��һ���˵Ļ�ȷʵû������ʲô����Ȼ�ź�����Ҳ��û�취���¡�
.message	1798			������˵�ź��޸���Ļ���
.message	1808			����������Ǽ������ĵĻ���Ҳ����ͨ��������Ӧ�����Ǻ��ǻ����Ҳ��ۡ�
.transition 0 * 40
.stage	* ev00_008a01.png 0 0
.message	1818	yuk-000_01-0085	@�D�@�q	���ǰ���û�취�������ء�
.transition 0 * 40
.stage	* ev00_008a04.png 0 0
.message	1828	yuk-000_01-0087	@�D�@�q	�������ء�����
.transition 0 * 20
.stage	* ev00_008a_mugai_a.png 0 0
.message	1838		�@�[�@	����ô����
.message	1848	yuk-000_01-0089	@�D�@�q	�������йص��˻��£�����ӭ���ܻ��Ľ���ء�����
.message	1858		�@�[�@	������ʲô��˼��
.message	1868	yuk-000_01-0091	@�D�@�q	���������˵Ĵ���֮��ɣ����һ����Χ���˶��������
.message	1878	yuk-000_01-0093	@�D�@�q	����Ȼ�Ҳ�����ô���Ծ��ء�
.message	1888			��˵Щ���µ����顣

.message	1898			���������ڳ��μ�����˲�����ô̹�װɡ�

.message	1908		�@�[�@	���������������ν�ˡ���ֻ���������¶��ѡ���Ҫ��������ôΣ�յĵط��ˡ�
.transition 0 * 20
.stage	* ev00_008b02.png 0 0
.message	1918	yuk-000_01-0095	@�D�@�q	��������������λ��������ء�
.message	1928			������Ů�Ǻǵ�Ц����
.message	1938			�Ǹ�Ц�ݲ�֪Ϊ��������Щ�ջ�
.message	1948		�@�[�@	��������͵͵���ݶ���������Լ����¡����ǣ�ˤ��ȥ�����Ļ��ǻ�������ŵġ�
.transition 0 * 40
.stage	* ev00_008b03.png 0 0
.message	1958	yuk-000_01-0097	@�D�@�q	��Ϊʲô����������أ���
.transition 0 * 20
.stage	* ev00_008b01_mugai_c.png 0 0
.message	1968			������ͷ��������Ĳ��������ӡ�
.message	1978		�@�[�@	�������˵�����������������Ȼ�������𣿡�
.transition 0 * 20
.stage	* ev00_008a01_mugai_c.png 0 0
.message	1988	yuk-000_01-0099	@�D�@�q	����������˵ļ�ֵ�۰ɡ�
.message	1998			��������΢��Щ������˵����
.message	2008			˵�������޹˼ɡ�����Ů����������������ӡ��
.message	2018			ͬʱҲ�о���ʵ����Ҳ������ô���¡�
.transition 0 * 40
.stage	* ev00_008a04_mugai_c.png 0 0
.message	2028	yuk-000_01-0101	@�D�@�q	����Ȼ��ˣ���Ȼ���Ҳ�û�б����ļ�ֵ�۵���˼Ŷ��


.playVoice *


.transition 0 * 10
.stage	* ev00_008b01_mugai_b.png 0 0

.playBGM *

.message	2048	yuk-000_01-0103	@�D�@�q	�����Ϧǰ����
.message	2058			Ȼ����������������������ҵ����֡���
.message	2068		�@�[�@	����������˭����
.message	2078			��ͬһ��ѧУ��ѧ����֪���ҵ����ֱ���û��ʲô����˼�顣
.message	2088			���ǡ�
.message	2098			�Ҽǵ����������
.message	2108			���˵����ʽ�����Ц�ݣ�ȷʵ�������Ҿ�Զ�����ĳ����
.transition 0 * 20
.stage	* ev00_008a04_mugai_b.png 0 0
.message	2118	yuk-000_01-0105	@�D�@�q	����Ȼ�����Ұ�����΢��Щ�ܴ���ء���
.message	2128		�@�[�@	���ش��ҵ����⡹
.message	2138	yuk-000_01-0107	@�D�@�q	����Ҫ������ô���µı��������ر�����Ů������ǰŶ��
.message	2148			��ҡҡͷ������΢��Щ߳��Ŀ���˵����
.message	2158			Ϊʲô��ֱð�亹�ء�
.message	2168			��ʲô��������ǣ�������࣬���Ҳ�������Ҫֹͣ�����Ĵ����
.transition 0 * 20
.stage	* ev00_008a03_mugai_b.png 0 0
.message	2178			������Ů�ٴ�΢Ц������
.message	2188	yuk-000_01-0109	@�D�@�q	�������������Ӱ���
.message	2198		�@�[�@	�����ӣ���
.transition 0 * 40
.stage	* ev00_008a04_mugai_b.png 0 0
.message	2208	yuk-000_01-0111	@�D�@�q	���ţ������ҵ����󡭡��벻Ҫ˵�����������Ļ�����
.message	2218			���ӡ�����
.transition 0 * 40
.stage	* ev00_008a05_mugai_b.png 0 0
.message	2228	yuk-000_01-0113	@�D�@�q	����ֻ��һ�۾���������˭������ȴ���׵����������ء����ҵ����Ѿ����˺����޷������ˡ�
.transition 0 * 10
.stage	past_window.png ev00_008a05_mugai_b_close.png 0 0
.message	2238	yuk-000_01-0115	@�D�@�q	�������
.panel 0
.transition 0 * 10
.stage	* WHITE.png 0 0


.wait 200
.transition 0 * 10
.stage	* ev00_moshi.png 0 0
.message	2248		�D�@�q	����������˵Ļ����ͳ�Ĭ��������������\v\a
.wait 300


.transition 0 * 10
.stage	* WHITE.png 0 0
.wait 200





.transition 0 * 10
.stage	* ev05_001.png 0 0
.panel 1
.message	1590	yuk-500_01-0071	@�D�@�q	������ʲô��û�����������������Ҳ�á�����
.playSE kane_ef.ogg f
.transition 0 * 20
.stage	* ev05_004_mugai_a2.png 0 0
.message	1600			ͻȻ���Ժ���������������
.transition 0 * 20
.stage	* ev05_004_mugai_a3.png 0 0
.message	1610		�@�[�@	�����ǡ�����
.transition 0 * 20
.stage	* ev05_002_mugai_a.png 0 0
.message	1620			���Ǽ�ֱ��Ҫ�Ѷ�Ĥ���Ƶģ�����������������
.transition 0 * 20
.stage	* ev05_002_mugai_b.png 0 0
.message	1630			һ��Ѱ������Ҫ���ˣ�һ�߿޺��ŵĺ����ǡ�
.transition 0 * 20
.stage	* ev05_002.png 0 0
.message	1640		�@�[�@	���̻ᡭ����
.message	1650			�������������ǰ�������Ѿ�һ�����еľ���
.transition 0 * 20
.stage	* ev05_003_mugai_a.png 0 0
.message	1660			��Ϊ����Ķ��С�
.transition 0 * 20
.stage	* ev05_003_mugai_b.png 0 0
.message	1670			���Ѿ������������˳������Ľ�����ǰ��������ʲô�˵����֡�
.transition 0 * 20
.stage	* ev05_003_mugai_c.png 0 0
.message	1680			�����Ա��������̾Ϣ���Լ�˺���ѷΰ㱯ʹ�Ĳҽ�����
.transition 0 * 20
.stage	* ev05_003_mugai_d.png 0 0
.message	1690			���������׻�����ˣ��Ե�ε�ϣ�����������е��ˡ���
.transition 0 * 20
.stage	* ev05_003_mugai_f.png 0 0
.message	1700			���Ǹ��ճ������Ѿ����ݻٵĵط������Ǹ��ָ����ĸ��鱻���۳����С�
.transition 0 * 20
.stage	* ev05_003_mugai_e.png 0 0
.message	1710			���Ҿ��ֵĿ����Ǹ��Ѿ��췭�ظ������磬����סֹ����ǰ��ʱ�򡪡��ҵ�����������ů�Ķ�����
.transition 0 * 20
.stage	* ev05_004.png 0 0
.message	1720			ת���������ǡ���
.transition 0 * 20
.stage	* ev05_004_mugai_b.png 0 0
.message	1730		�@�[�@	����ô������
.playSE *
.transition 0 * 20
.stage	* ev05_001_mugai_a.png 0 0
.message	1740			��ȥ��Ӱ����ֹ���ҵ�Ŀ��۽�����ǰ����Ů���ϡ�
.transition 0 * 20
.stage	* ev05_001.png 0 0
.message	1750			������濴�Ļ����Ǹ�ʱ�����������ȷʵ�������ڼ����С���




.transition 0 * 10
.stage	* ev00_008a01.png 0 0
.message	1760		�@�[�@	���������������ˡ������������ˣ����ӡ�
.transition 0 * 10
.stage	* ev00_008b02.png 0 0
.message	1770	yuk-500_01-0073	�D�@�q	���ǳ���л����
.message	1780		�@�[�@	������˵��ô�����Ļ���
.message	1790			�ǵģ���Ҳ����������
.message	1800			���������ǹ�ȥ���ң���Ȼ����ĳ�����������ļ��䣬�Ǳ�Ȼ����
.message	1810		�@�[�@	�����ӣ��㡭����
.transition 0 * 40
.stage	* ev00_008b03.png 0 0
.message	1820	yuk-500_01-0075	�D�@�q	���ţ���
.message	1830		�@�[�@	������ûʲô��
.message	1840			����΢ҡ����ͷ��
.transition 0 * 20
.stage	* ev00_008b01_50001a.png 0 0
.message	1850			Ȼ���߽���һ����
.message	1860		�@�[�@	��������ֶ����ɳ�ȥ�����Ϊ�����ġ�
.transition 0 * 20
.stage	* ev05_006.png 0 0
.message	1870			һ�߾����ܵ��ò����˵Ŀ���˵�ţ�һ�߰Ѹղż񵽵�ֽ�ɻ����˹�ȥ��
.transition 0 * 20
.stage	* ev00_008b05_50001a.png 0 0
.message	1880	yuk-500_01-0077	�D�@�q	���ò������۳����ľ�Ʒ����˵��������̫������Ӵ��
.message	1890		�@�[�@	��������������Ļ��Լ�������Ҫ�Ķ������Ų��Ǹ���ô��
.transition 0 * 40
.stage	* ev00_008b02_50001a.png 0 0
.message	1900	yuk-500_01-0079	�D�@�q	��˵�����أ�Ӧ���Ǻ���Ҫ���ء�
.message	1910			����ͣ�ص���ͷ��
.transition 0 * 40
.stage	* ev00_008b01_50001a.png 0 0
.message	1920	yuk-500_01-0081	�D�@�q	���Ǿ��뵱����Ҫ�Ķ����ղ������ɡ���Ȼ�ѳ��������ʲô�Ļ���û��ϵ�ģ������ܶ���Ŷ��
.message	1930		�@�[�@	����һ�¡�������ʲô��˼��
.transition 0 * 40
.stage	* ev00_008b04_50001a.png 0 0
.message	1940	yuk-500_01-0083	�D�@�q	�����ֽ�ɻ������͸����ǰ����Ӵ��
.message	1950		�@�[�@	��ʲô����
.message	1960			���ӿ��ƺܸ��˵�΢Ц�ţ��������ҡ�
.transition 0 * 40
.stage	* ev00_008b01_50001a.png 0 0
.message	1970	yuk-500_01-0085	�D�@�q	����Ȼ�����е��ź��ء�
.message	1980		�@�[�@	���ź�����
.transition 0 * 40
.stage	* ev00_008b04_50001a.png 0 0
.message	1990	yuk-500_01-0087	�D�@�q	������������ֻ������һ���˵ĵط�������ȴ�����˲��������ˡ�
.transition 0 * 40
.stage	* ev00_008b02_50001a.png 0 0
.message	2000	yuk-500_01-0089	�D�@�q	������������Ļ�����ԭ��Ŷ��
.message	2010	yuk-500_01-0091	�D�@�q	����һֱ�����������һ�εļ��桹
.message	2020			���ӽӶ�������˵����
.transition 0 * 40
.stage	* ev00_008b04_50001a.png 0 0
.message	2030	yuk-500_01-0093	�D�@�q	����Ϊ�ٻ�ļ�������°ɡ�
.message	2040		�@�[�@	������˵ʲô�����������������
.message	2050		�@�[�@	�����ֶ������Ҳ���Ҫ��
.message	2060			�����Ӧ����ʲô�ٻ�ļ���һ��ġ�
.message	2070			���٣�������˵�ⲻ��ʲôֵ�ø��˵���̬��
.transition 0 * 10
.stage	* ev00_008a01_50001a.png 0 0
.message	2080	yuk-500_01-0095	�D�@�q	���ҡ�����
.message	2090			�Ұ�ֽ�ɻ��������֣�ͻȻ����һ�¡�

.message	2101	yuk-500_01-0096	�D�@�q	������Ϊֹ�����ڡ�����
.message	2102	yuk-500_01-0098	�D�@�q	���������㡹

.message	2110		�@�[�@	������������
.message	2120			����Բ��ǿ��š�
.message	2130			������˵������΢Ц�ı����︡�ֳ���ʲô��
.message	2140			Ϊʲô����˵ġ���
.transition 0 * 20
.stage	* ev00_008a04_50001a.png 0 0
.message	2150	yuk-500_01-0099	�D�@�q	���ţ�һֱ���ڡ�
.transition 0 * 20
.stage	* ev00_008a03_50001a.png 0 0
.message	2160	yuk-500_01-0101	�D�@�q	���ٶȼ�������̫���ˡ����ڿ���ȷ�����ء�
.message	2170		�@�[�@	��ȷ�ϡ�������
.transition 0 * 20
.stage	* ev00_008b01_50001b.png 0 0
.message	2180	yuk-500_01-0103	�D�@�q	���ţ�������Ϊֹ������
.transition 0 * 20
.stage	* ev00_008b05_mugai_c.png 0 0
.message	2190	yuk-500_01-0105	�D�@�q	�������������ס����ˣ�ȴ��������˦������ʹ����������Ϊֹ����֪���𣿡�
.transition 0 * 20
.stage	* ev00_008b05_50001c.png 0 0
.message	2200			�ҿ����������Ŀ־塣
.transition 0 * 20
.stage	* ev05_006_mugai_a.png 0 0
.message	2210			�о���ֱ��ͬ�������˼��һ�㣬������ȫ�޷�������
.message	2220			ʲô��������������
.transition 0 * 20
.stage	* ev05_007a01_mugai_a.png 0 0
.message	2230	yuk-500_01-0107	�D�@�q	�����������ڿ���ЦӴ����
.transition 0 * 20
.stage	* ev05_007a01_mugai_b.png 0 0
.message	2240			ͻȻ���ֵ������������˶����
.transition 0 * 20
.stage	* ev05_007a01_mugai_c2.png 0 0
.message	2250			��ֹ������������ŵĿռ�Ѹ�ٱ���ſ�����
.transition 0 * 20
.stage	* ev05_007a01.png 0 0
.message	2260	yuk-500_01-0109	�D�@�q	����������ô�����ı���Ӵ�����ǰ��������һ�������ة
.transition 0 * 20
.stage	* ev05_007a02.png 0 0
.message	2270	yuk-500_01-0111	�D�@�q	���������ֽ�ɻ��ҿ��������Ҫ�㵱����Ҫ�Ķ������ܵ�Ŷ���һᾭ��ͻ����鿴����û�ж����ġ�
.message	2280			����û��һ�㣬���ʵ������������ҵĶ��䡣
.message	2290			��Ȼ������������ϵ�ֽ�ɻ��ĳ嶯��������������������ô������������������
.transition 0 * 20
.stage	* ev05_007a04.png 0 0
.message	2300		�@�[�@	�������������۵ļ���Ʒ��
.transition 0 * 20
.stage	* ev05_007a03.png 0 0
.message	2310	yuk-500_01-0113	�D�@�q	���Ǻǣ��������һ�㶼û�䡹
.message	2320	yuk-500_01-0115	�D�@�q	��һ������Ļ��ĳ�������
.transition 0 * 20
.stage	* ev05_007b01.png 0 0
.message	2330			СС��̾����������Ů���������������
.transition 0 * 20
.stage	* ev05_008a01.png 0 0
.message	2340	yuk-500_01-0117	�D�@�q	����ô�ټ���Ŷ������硹
.playSE okuzyou_door_miyako.ogg f 0 *
.transition 0 * 20
.stage	* ev05_008b01.png 0 0
.message	2350		�@�[�@	������������
.playSE okuzyou_door_miyako_close.ogg f 0 *
.transition 0 * 20
.stage	* ev05_008c01.png 0 0
.message	2360			��û�ܽ�ס�뿪�����ӡ�
.transition 0 * 20
.stage	* ev05_008d01.png 0 0
.message	2370			��磬��
.message	2380			�Ѿ��ж�����û��������ƺ��ˡ�
.message	2390			���Ѿ����á����������ٴ������ˡ�
.message	2400			��˭�������ţ��Լ���������������顭����
.message	2410	aka-500_01-0003	#�@���@	����硻
.message	2420			�D�D�D�D��
.playSE town_dead_yuu.ogg true
.transition 0 * 20
.stage	* WHITE.png 0 0
.message	2430			�Ժ��б������˻��档
.transition 0 * 20
.stage	* ev05_009.png 0 0
.message	2440			���侲�ĵ����ź������Ѵ��˵Ļ����������ϡ�
.transition 0 * 20
.stage	* ev05_009_mugai_c.png 0 0
.message	2450			ֻ����������С���
.transition 0 * 20
.stage	* BLACK.png 0 0
.message	2460			���Բ���������ģ�����������������ļ��䡣
.playSE *
.transition 0 * 20
.stage	* ev05_007b01_mugai_a.png 0 0
.message	2470			�Ҿ���������ֽ�ɻ�����Ŀ�⡣
.message	2480			���������ʵ�Ļ������Ͳ������ý��ɵĹ�ȥ�������졣
.transition 0 * 20
.stage	* ev05_007b01_mugai_b.png 0 0
.message	2490		�@�[�@	����������
.message	2500			��΢̾��������
.message	2510			û�µģ���һֱ���ܺܺõĿ����Լ���
.message	2520			��������ʧ���ҡ�
.message	2530			��һֱ����������
.transition 0 * 20
.stage	* ev05_008d01_mugai_a.png 0 0
.message	2540		�@�[�@	���������ˡ���ȥ���ˡ�����
.message	2550			̫�����Ҫ��ɽ�ˡ�
.message	2560			���ڲ����������ĵĵط���������ʱ��
.panel 0
.transition 0 * 20
.stage	* ev05_007b01_big.png 0 600
.scroll	800 350	10
.endScroll f

.panel 1
.message	2570		�@�[�@	���߰ɡ�
.transition 0 * 20
.stage	* bgs_sky001a01_02.png 0 0
.message	2580			һ������ţ��ҿ�ʼ������
.message	2590			�ǵģ����߲��С�
.message	2600			û���й���ȥ�����Ѿ��޷��ع�Ĺ�ȥ����ֹ���ң�����Ϊ˭��������������
.playSE semishigure_b.ogg f 0 *
.transition 0 * 20
.stage	* WHITE.png 0 0
.message	2610			������������Ƶģ�����ʼ����������
.message	2620			���졪���Ҳ������ᡣ
.panel 0
.playBGM *
.transition 0 * 5
.stage	* WHITE.png 0 0
.playSE *

.transition 0 * 10
.stage	* BLACK.png 0 0
.wait 100

.chain 501_01.sc
.end
