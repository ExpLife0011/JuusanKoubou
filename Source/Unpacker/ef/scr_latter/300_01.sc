.setGlobal EYE_SEQ_DEFAULT = 2



.if ef_321_01 == 1 ef_300_b1
.if ef_321_01 <= 0 ef_300_a1

.label ef_300_a1

.pragma disable_control


.transition 0 * 10
.stage	* WHITE.png 0 0
.wait 400
.transition 0 * 10
.stage	* ago_base_30001e.png 0 0
.panel 1
.message	100	chi-300_01-0003	@��@�q	���ڡ�ѻ��Ŷ��Ϊ�Ρ�����������ѻ�ڡ�ɽ��ͷ���ϡ�����Ϊ���С��ߡ������ɰ��ġ�����Ӵ����\v\a
.goto ef_300_c1
.end


.label ef_300_b1

.pragma enable_control

.transition 0 * 10
.stage	* WHITE.png 0 0
.wait 400
.transition 0 * 10
.stage	* ago_base_30001e.png 0 0
.panel 1
.message	100	chi-300_01-0003	@��@�q	���ڡ�ѻ��Ŷ��Ϊ�Ρ�����������ѻ�ڡ�ɽ��ͷ���ϡ�����Ϊ���С��ߡ������ɰ��ġ�����Ӵ����
.goto ef_300_c1
.end


.label ef_300_c1








.transition 0 * 10
.stage	* ago_base_30001d.png 0 0

.playBGM efBGM031.ogg

.pragma enable_control

.panel 1
.message	110			��ѧ��·�ϣ���������һ�˵ĳ�վʱ�������˸�����
.message	120			���˻���ĺͷ�衣
.message	130			����������
.transition 0 * 20
.stage	* ago_base_30001c.png 0 0
.message	140			����Ҳ����˵�������ǿ���һ�˵İɡ�
.message	150		�@�@��	�������������ء�
.transition 0 * 20
.stage	* ago_base_30001k.png 0 0
.message	160			����������������ɢ���ڵ����ϵ�ʯ�ӷ������졣
.transition 0 * 20
.stage	* ago_base_30001i.png 0 0
.message	170			�������������վ�ڡ�

.playVoice *

.transition 0 * 20
.stage	* ago_base_30001j.png 0 0
.message	180			����������Һ��������ˡ�




.transition 0 * 15
.stage	* ago_base_30003f.png 0 0
.message	190			���������Ǵӹ��µĽ�β��ʼ˵��ɡ�
.message	200			���Ǻͽ�ֶ�Ӧ�ŵĹ��¡�
.message	210			�����������������ļ���Ĺ��¡�
.message	220			һ��д���˵�ͯ����
.transition 0 * 10
.stage	past_window.png BLACK.png 0 0
.message	230			��ͬ����ȷ��¼��һ����һ����ռ��и��֧�������������������Ĺ��¡�����




.transition 0 * 10
.stage	* ago_base_30001f.png 0 0
.message	240	mid-300_01-0003	@�~�Y�L	���㡭�����������ô����


.message	250			��������һ��֮�󣬵绰��ͷ�ı����������ҡ�
.transition 0 * 20
.stage	* ago_base_30001h.png 0 0
.message	260			���յ���ҹ�
.message	270			�Ҿþ�����������������֮�У��Ǹ���Ŀ�����һ���شӽŵ״����ҵ����¡�
.message	280			��ɫ������ҹ��
.message	290			�ž�����ͬ����ɫ����֮ɳĮ֮�С�

.transition 0 * 10

.stage	* ev03_001a.png 0 0
.message	300			�������ȵ�ҹ�����˲����������ţ��Ѿ��������ء��ĸо���
.transition 0 * 20
.stage	* ev03_003a03.png 0 0
.message	310	mid-300_01-0005	�~�Y�L	���������ܸ������𣿡�
.message	320			��Ϊ��û�лش�ɣ����á�����ɽ��ϣ�Ŀ�������
.transition 0 * 20
.stage	* ev03_002a01.png 0 0
.message	330		�@�@��	���������ǡ�����ڣ���
.message	340	mid-300_01-0007	�~�Y�L	���ǵģ���ڡ�
.transition 0 * 20
.stage	* ev03_002a02.png 0 0
.message	350		�@�@��	����΢��һ�¡�
.transition 0 * 20
.stage	* ev03_001a_mugai_a.png 0 0

.message	361			������ô��������ѯ���Լ������ġ�

.message	370			�����������һ�����Щ���ӡ�
.message	380			����������ı��롣
.transition 0 * 20
.stage	* ev03_002a01.png 0 0
.message	390		�@�@��	���ţ��Ǻ�ڰɡ�
.message	400			����ʵ�ػش����
.message	410		�@�@��	���������ܹ��и���ͬ�����ˡ��������統ʱ�����ø���һ�㡱��
.message	420		�@�@��	���������Լ����и�ǿ������������֮��ġ�
.transition 0 * 20
.stage	* ev03_002a03.png 0 0
.message	430		�@�@��	���Ҳ��롭���پ������ֺ�ں�ʹ�ĵĸо��ˡ�
.message	440	mid-300_01-0009	�~�Y�L	������������
.transition 0 * 20
.stage	* ev03_003a01.png 0 0
.message	450	mid-300_01-0011	�~�Y�L	�����Σ�����Ц�ɣ���
.message	460		�@�@��	��ʲô����
.message	470	mid-300_01-0013	�~�Y�L	����������о��ó�����
.message	480		�@�@��	������ȷʵ�к�ڡ����Ǵ�δ�й���ô�Ҹ���ʱ�䡻
.message	490			����ʵ�����
.message	500			�����ǲ���˼���ػش������
.message	510	mid-300_01-0015	�~�Y�L	������ô����


.transition 0 * 20
.stage	* ev03_003a05.png 0 0
.message	530	mid-300_01-0017	�~�Y�L	��������������Ҷ���Ŭ���ء�
.message	540		�@�@��	����ң���
.transition 0 * 20
.stage	* ev03_003a04.png 0 0
.message	550	mid-300_01-0019	�~�Y�L	���Ǻǡ�������������ѡ�
.transition 0 * 40
.stage	* ev03_003a02.png 0 0
.message	560	mid-300_01-0021	�~�Y�L	���Ѿ������ˣ���Ҫ���绰�ѣ����ȹҶ���Ŷ��
.message	570	mid-300_01-0023	�~�Y�L	���´�����������ɡ����������ʺá�
.transition 0 * 20
.stage	* ev03_002a01.png 0 0
.message	580		�@�@��	������лл�ˣ���ϣ��
.transition 0 * 20
.stage	* ev03_003a01.png 0 0
.message	590	mid-300_01-0025	�~�Y�L	������ΪʲôҪ��л�أ���
.transition 0 * 20
.stage	* ev03_002a04.png 0 0
.message	600		�@�@��	����ͨ�绰�������ڵ����Ұɡ�
.message	610			�ҿ�Ц��Ʋ���졣
.message	620			һֱ������ߴߴ������������ı��ã�����û�б��ֳ����������һ���ء�
.transition 0 * 20
.stage	* ev03_003a05.png 0 0
.message	630	mid-300_01-0027	�~�Y�L	��������
.transition 0 * 40
.stage	* ev03_003a04.png 0 0

.message	640	mid-321_01-0029	�~�Y�L	����ô���������Ŷ���Ρ�

.transition 0 * 20
.stage	* ev03_002a01.png 0 0
.message	650		�@�@��	��������ϣ��
.transition 0 * 20
.stage	* ev03_001b.png 0 0
.message	660			ȷ����������ͨ���жϵ��������ҷ����˻�Ͳ��
.message	670			��ɫ������ҹ��
.message	680		�@�@��	�����ʲô�ġ����ǵ�Ȼ�ġ�����
.transition 0 * 20
.stage	* ev03_254.png 0 0
.message	690			������ʼ������
.message	700			�о��۽Ǻ�ͷ����Щ���ȡ�
.message	710			�ӽ�����Ҳ��һֱ�����ȥ�ɡ�
.message	720			��ȫû��˯�⡣
.message	730			�����Ѿ���͸�������̶������ֹͣ��Щ�뷨��
.message	740			������ۣ�ͷ�Ժ����ѡ�
.transition 0 * 20
.stage	* ev03_005.png 0 0
.message	750		�@�@��	������������
.message	760			�ӿڴ����ó��������ҵļ��±���
.message	770			���������ʱ�õ��ļ��±���
.message	780			Ҳ��������ļ��䡣
.message	790			���¹��������𽥸��ֳ�����
.message	800			һ��һ�εĻ������ʶ�����
.message	810			׷Ѱ���ռ��ϵ����֡�
.message	820			��ʹ����ô������Ҳ���Ѱ�������������������������Ρ�����������Լ�����������Ĺ��¡�
.transition 0 * 20
.stage	* ev03_255.png 0 0
.message	830			��ͷ��һҳ����д�š�
.message	840			�÷ǳ��ǳ�����Բ��������д�š�
.panel 1
.transition 0 * 10
.stage	* WHITE.png 0 0
.transition 0 * 5
.stage	* ev03_263.png 0 0

.message	850	chi-300_01-0005	@��@�q	���D�D��������ң�д��������ҡ�\v\a
.wait 400

.panel 0
.transition 0 * 10
.stage	* WHITE.png 0 0
.playBGM *
.transition 0 * 10
.stage	* WHITE.png 0 0
.wait 100





.playBGM ef#01.ogg

.transition 0 * 10
.stage	* ev03_061c01_mugai_b2.png 0 0


.panel 1
.message	860			��վ̨�ϱ��õĳ����ϣ�����һ����Ů��
.transition 0 * 20
.stage	* ev03_006a01.png 0 0
.message	870			�����������Һ�ϲ���ĵط�������Ȼ��û��������ú�Ư���ĸ�ʾ�ƣ�Ҳû������д�š�ռ�����ı�ǩ��
.message	880			��Ů�߸ߵذ���ͷ����������ա�
.message	890			�����ܺ��䡣
.message	900			��Ů�����ź��޷����Ѻ�����¶��������ƣ��ǲ��ǳ����ڸոշ���ĺ���ɻ������������أ�������������С���ڵ���ιʳ�����ӡ�
.message	910			������û�л�������ĳ����𡭡���
.message	920		�@�@��	������������


.message	930			�Ҵ�������������Ů����Ȼ�䣬�����ˡ���Ӧ�ô��ŵ��������������顣
.message	940			�������Ϊ�������̫���˰ɡ�
.message	960			�һ��ڿ������ǲ���Ҫ�����뿪��վ��ʱ�򡭡���


.transition 0 * 20
.stage	* ev03_006d01.png 0 0
.message	970			��Ůһ�������ŵĵ�����ʲô�أ��������ţ����ɵ�˳���������߿�ȥ��
.transition 0 * 20
.stage	* bgw_sky001a01_02.png 0 0
.message	980			ʲôҲû�С�
.message	990			��������������
.message	1000			���յ���ϼ���������ź���һ�������ź��⡣
.message	1010		�@�@��	������������
.message	1020			�������������Ŵ�Ҳȷʵ�����ֵ�ɡ�
.message	1030			�Ҵ�������ƻ����ߡ�
.transition 0 * 20
.stage	* ev03_006b01.png 0 0
.message	1040	chi-300_01-0007	@��@�q	������������
.message	1050			��֪ʲôʱ��ʼ����Ů���������ڶ����ҿ���

.message	1070			�ǻ�����������ֻ��û��������ס�����ۿ����ҡ�

.message	1080			���˴�ʱ��������˼�������������ô��������ˡ�
.message	1090		�@�@��	�������վ�����е糵����Ŷ��
.message	1100	chi-300_01-0009	@��@�q	��������
.message	1110		�@�@��	����Ǹ��ûʲô��
.message	1120			��ڷ��ܵ�һ�仰��ȴ�����������ػ�Ӧ�ˣ��ҷ����Եص���Ǹ��
.message	1130			�Ի�û�м�����ȥ��
.message	1140			������û�п��Լ�����ȥ�Ļ��⣬����������Ȼ�ġ�
.message	1150			��Ϊ�ǶԷ������ģ�Ӧ���뿪�����Ұɡ����Ұ��ճ����������ǡ�
.message	1160		�@�@��	���������ˡ�
.message	1170			��������������˻ӡ�

.message	1180	chi-300_01-0011	@��@�q	�������š�
.transition 0 * 20
.stage	* ev03_006c01.png 0 0
.message	1190			��Ȼ������һ��ãȻ����ŮҲ�������һ��˻�����ϸ��С�֡�
.transition 0 * 5
.stage	* WHITE.png 0 0
.message	1200			�����������ǵĵ�һ�����������ˡ�


.message	1210			�Һ��������������ڶ��ա�


.message	1220			����һ�β��㣴��������ˡ�����
.panel 0
.transition 0 * 10
.stage	* WHITE.png 0 0


.wait 100

.transition 0 * 7
.stage	* title_chap3.png 0 0
.message	999			\a��
.wait 500

.transition 0 * 7
.stage	* WHITE.png 0 0
.wait 300


.chain 301_01.sc
