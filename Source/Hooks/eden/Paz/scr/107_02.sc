; �ե�����: 107_02.txt

.set favMiyako_a = favMiyako_a + 1
;����äƱ�Ҫ������
;�����Θ��Ӥ�Ҋ���Ф����x�k��
;��������ѧ�@�����£����������r
;������������Ұ�����Ʒ�������
;�������������پ����Ʒ�������
.message	100			1�꼶�Ľ���Ҳ�Ǻܾò������ء�
.message	110			����ȥ���һ������������ȴ������Щ��ϰ�ߡ�
.message	120			���㲻ϰ��ҲҪ��ǰ�ߡ�
.message	130			����ʱ��ȥ������Ⱥ�󱲡�
.playSE kyoushitsu_door_open.ogg f 0 *
.message	140			������


;������������
.transition 1 fadeSide.png 20
.stage	* ev01_084_mugai_b.png 0 0
;.stage	* ev01_084_mugai_a.png 0 0
;������ޤ����Ф�������˷�����ʤ���⣩
;.stage	* ev01_083a01.png 0 0
;�����ΣãǤα�ʾ�����ߥ󥰣�ע��Τ��ȡ�һ�����ν��ҤʤΤǣ�ͨ���������������Ϥϥ�֤ˤ�ע�⡣������ң���������ʤ��ƣ�����Ҥ�һ�w�Υ�֤���ޤ����Ȥ���
.message	150			��Ŀ��Ľ����ţ����ӵ��󱲾��ÿ��ɵ�Ŀ�⣬�߽��Ǽһ�Ŀ�����
.message	160			Ŀ����һ�����Ż�ȥ��׼����һ�ߺ͸�����λ��Ů�������졣
.message	170		�@�h�@	��ι��
;.transition 0 * 40
.transition 0 * 20
.stage	* ev01_083a02.png 0 0
;���ݤ���Ȥ��륿���ߥ󥰤�ע�⡣a01�ΥΡ��ޥ�����ʹ���ɤ���⿼���Ƥ������ȣ�
.message	180	kei-107_02-0003	�@�i�@	����������ô���ˡ�
.message	190			�������������쿴��վ����ǰ���ҡ�
.message	200		�@�h�@	�����ã���ûȥ�μӲ��Ż���ǰɡ���΢�����ºðɣ���
.transition 0 * 40
.stage	* ev01_083a03.png 0 0
;�����ݱ����ʹ���ɤ���Ϥ����Ǥ����Τ�ע�⣩
.message	210	kei-107_02-0005	�@�i�@	����Ȼ���ԣ���Ҳ��Ҫ���������ľ��߽����꼶�Ľ��Һðɡ���һ����ʲô�µİ���
.message	220			�羰���ԣ����ڽ������1�꼶ѧ���Ƕ�����¶���ɻ�ı��顣
.message	230		�@�h�@	��ʲô�¶�û�����߰ɡ�
.message	240			�����𾰵��ֿ�ʼ��������
.transition 1 fadeSide.png 20
.stage	* ev01_084.png 0 0
;��ͨ���ե����ɤǣ���
.message	250	kei-107_02-0007	�@�i�@	���ԣ��Ե�һ�°����穤���ȱ�����


;��������ѧ�@���A��
.overlay * or_kei02a.png
.transition 1 fadeSide.png 20
.stage	* bgc_sch003a01_02.png 0 0 st_kei01a06.png 380
.message	260	kei-107_02-0009	�@�i�@	�����ǵġ���Ҫ�����ðɣ���
.message	270			�ߵ�¥�ݵĵط�ʱ����ž���ĵ����ҵ��֡�
.message	280		�@�h�@	�������̫��������
.transition 0 * 40
.stage	* bgc_sch003a01_02.png 0 0 st_kei05a07.png 400
.message	290	kei-107_02-0011	�@�i�@	��ǰ��̫��ע���˺ðɣ���Ҫ�Ǵ���ʲô��ֵ�������ô�찡��
.message	300		�@�h�@	�����������͸��һ��˵ʲô�ء���˵�㣬û���ɣ���
.transition 0 * 40
.stage	* bgc_sch003a01_02.png 0 0 st_kei01a10.png 380
;������ȥݡ���ע�⡣�����Ĥत�ơ��Ϥ��ʤ��Τǣ�������
.message	310	kei-107_02-0013	�@�i�@	����������
.transition 0 * 40
.stage	* bgc_sch003a01_02.png 0 0 st_kei01a09.png 380
;����ʾ�����ߥ󥰣�ע��Τ��ȣ�
.message	320			������������������������������ͷ��
.message	330		�@�h�@	����Ǹ����Ǹ��˵Ц������
.message	340	kei-107_02-0015	�@�i�@	��������������������
.message	350			���ڿ޻�������������
.message	360			����һ������鷳���Ը񰡣�����
.message	370	kei-107_02-0017	�@�i�@	������һ������㡭����
.message	380		�@�h�@	������������
.message	390			�ڣ��������ء�����
.transition 0 * 40
.stage	* bgc_sch003a01_02.png 0 0 st_kei01a03.png 380
.message	400	kei-107_02-0019	�@�i�@	�����ˡ����׸�����ʲô��Ҫ˵��������ʲô����û����ղ��������߳�PLAY�ɣ���
.message	410		�@�h�@	����˵�㣬ON/OFF̫�����˰ɡ�
.message	420			�ղŵ�Ҳ�㲻��ʲô�߳�PLAY����˵��
.transition 0 * 40
.stage	* bgc_sch003a01_02.png 0 0 st_kei01a06.png 380
.message	430	kei-107_02-0021	�@�i�@	������ǰ���㰴�Ŀ����𣡡��ֲ����ҵĴ���
.message	440			���һ�����������
.message	450			��̾��һ������ž�İ��ַ����˾���ͷ�ϡ�
.transition 0 * 20
.stage	* bgc_sch003a01_02_stm.png 0 0 stm_kei05a04.png 400
;������ȥݡ�����ע��Τ��ȣ�
.message	460	kei-107_02-0023	�@�i�@	����������˵�����������驤����
.message	470		�@�h�@	�����֮�����Ǿ����ŵġ�
.transition 0 * 40
.stage	* bgc_sch003a01_02_stm.png 0 0 stm_kei06a05.png 400
;��02a03�Ǥ⣿��
;.stage	* bgc_sch003a01_02.png 0 0 st_kei05a07.png 400
;������ȥݡ���ע�⣩
.message	480	kei-107_02-0025	�@�i�@	����Ҫһ�����Լ�������ͬ�ðɡ�
.message	490		�@�h�@	����Ȼ�����źá�����
.message	500		�@�h�@	��������һ�仰����˵��������Ҳ��΢�����°ɡ�
.message	510			ϣ������������ĸ�Ϊ��Ȼ��
.message	520			�ţ����Ǽһ�һ�������ţ�������ͨ��Ц�թ���
.transition 0 * 40
.stage	* bgc_sch003a01_02_stm.png 0 0 stm_kei05a08.png 400
.message	530	kei-107_02-0027	�@�i�@	�������ҿ���������ô��̵����𣿡�
.message	540		�@�h�@	�����ְɡ�
.message	550		�@�h�@	���ر���������㡣�����Լ�Ҳ˵���Լ��������
.message	560		�@�h�@	����Ȼ�����Ҳ�����˸��ָ������¡�
.transition 0 * 40
.stage	* bgc_sch003a01_02_stm.png 0 0 stm_kei05a03.png 400
.message	570	kei-107_02-0029	�@�i�@	��û�С�
.message	580			����Ķ���һ�仰��
.transition 0 * 40
.stage	* bgc_sch003a01_02_stm.png 0 0 stm_kei04a04.png 400
;��04a04�ζ��ã�ע�⣩
.message	590	kei-107_02-0031	�@�i�@	��û��ʲô���ָ�������֮���Ի���֣�ԭ��ֻ����һ�����ѣ���
.message	600		�@�h�@	��ʲô�����Ǹ�ԭ��

;����Ӱ�����å�
.playBGM *

.transition 0 * 20
.stage	* bgc_sch003a01_02.png 0 0 st_kei02a03.png 380
;����ʾ�����ߥ�ע�⡣������ǣ�01a06��ҕҰ�ˣ�
.message	610			ž�����˺���һ�i��
.message	620	kei-107_02-0033	�@�i�@	����ܷ�������������Լ�ȥ������

;����Ӱ�����å�
;.playBGM *
.playBGM efBGM013.ogg 0 *

.message	630	mid-107_02-0003	�~�Y�L	����ǰ����������
.message	640			ͻȻ����¥�����洫��һ�����ĺ�����
.message	650		�@�h�@	������
.transition 0 * 40
.stage	* bgc_sch003a01_02.png 0 0 st_kei01a10.png 380
.message	660	kei-107_02-0035	�@�i�@	����ϣ�������𣿡�
.message	670			������΢��Щ���ȵ�����˵����
.transition 0 * 20
;.stage	* bgc_sch003a01_02.png 0 0 st_kei01a10.png 200 st_mizuki_a01a03.png 600

;����Ӱ�����å�
;.stage	* bgc_sch003a01_02.png 0 0 st_kei01a10.png 200 st_mizuki_a01a03.png:[0,0,0]or_mizuki02a.png 600
.stage	* bgc_sch003a01_02.png 0 0 st_kei01a10.png 200 st_mizuki_a01a03.png:[0,0,0]or_mizuki02a.png 615

;������01��02�ݡ�������ϣ��K�Ф���ȣ��������L����`�ͤ��������ʣ������K�٤���Ϥ�01,02�ݡ�������Τ�Τ�ʹ�äƣ���
.message	680	mid-107_02-0005	�~�Y�L	�����ǣ������ϣ���ڴ˼��Σ���
.message	690			����Ҫҡ��β����������ɽ����˵�š�
.message	700	mid-107_02-0007	�~�Y�L	�����ȱ���ô���������֣�����������Ŷ����
.transition 0 * 40
;.stage	* bgc_sch003a01_02.png 0 0 st_kei02a02.png 200 st_mizuki_a01a03.png 600

;����Ӱ�����å�
;.stage	* bgc_sch003a01_02.png 0 0 st_kei02a02.png 200 st_mizuki_a01a03.png:[0,0,0]or_mizuki02a.png 600
.stage	* bgc_sch003a01_02.png 0 0 st_kei02a02.png 200 st_mizuki_a01a03.png:[0,0,0]or_mizuki02a.png 615

;�����α��飬ע�⣩
.message	710	kei-107_02-0037	�@�i�@	���ǣ����𡣱�Ǹ�ء�
.message	720			˵���������к͸������򲿵Ĺ�ͬ��ϰ���š�
.transition 0 * 40
;.stage	* bgc_sch003a01_02.png 0 0 st_kei02a02.png 200 st_mizuki_a02a01.png 600
.stage	* bgc_sch003a01_02.png 0 0 st_kei02a02.png 200 st_mizuki_a02a01.png:[0,0,0]or_mizuki02a.png 600
.message	730	mid-107_02-0009	�~�Y�L	��������ˣ�ȥ��ϰ��������Ҷ��Ѿ�����Ŷ����
.transition 0 * 40
;.stage	* bgc_sch003a01_02.png 0 0 st_kei02a02.png 200 st_mizuki_a02a01.png 600
.stage	* bgc_sch003a01_02.png 0 0 st_kei02a02.png 200 st_mizuki_a02a01.png:[0,0,0]or_mizuki02a.png 600
.message	740		�@�h�@	����˵������ɽ������ߵĻ���û������
.transition 0 * 40
;.stage	* bgc_sch003a01_02.png 0 0 st_kei02a03.png 200 st_mizuki_a03a03.png 600
.stage	* bgc_sch003a01_02.png 0 0 st_kei02a03.png 200 st_mizuki_a03a03.png:[0,0,0]or_mizuki02a.png 600
.message	750	mid-107_02-0011	�~�Y�L	����˵ʲô���𣿡�
.message	760			����Ծ���ȫ�෴�ı��飬��ɽһ�������˵�����˵����
.message	770		�@�h�@	���һ��е㻰Ҫ�;�������
.transition 0 * 40
;.stage	* bgc_sch003a01_02.png 0 0 st_kei02a03.png 200 st_mizuki_a03a06.png 600
.stage	* bgc_sch003a01_02.png 0 0 st_kei02a03.png 200 st_mizuki_a03a06.png:[0,0,0]or_mizuki02a.png 600
.message	780	mid-107_02-0013	�~�Y�L	�����������ҵľ�ǰ��˵������
.message	790		�@�h�@	��������ˡ�
.message	800	kei-107_02-0039	�@�i�@	��ʲôʱ���ҳ�����ϣ���������ˡ�����
.transition 0 * 40
;.stage	* bgc_sch003a01_02.png 0 0 st_kei02a03.png 200 st_mizuki_a03a02.png 600
.stage	* bgc_sch003a01_02.png 0 0 st_kei02a03.png 200 st_mizuki_a03a02.png:[0,0,0]or_mizuki02a.png 600
.message	810	mid-107_02-0015	�~�Y�L	���Ǿ�������Ŷ����ǰ����
.message	820			�������������Ļ�����ɽ�����˾����֡�
.transition 0 * 40
;.stage	* bgc_sch003a01_02.png 0 0 st_kei02a03.png 200 st_mizuki_a01a02.png 600
.stage	* bgc_sch003a01_02.png 0 0 st_kei02a03.png 200 st_mizuki_a01a02.png:[0,0,0]or_mizuki02a.png 600
.message	830	mid-107_02-0017	�~�Y�L	���Ǿ��ټ���Ŷ��<���ַ���>��
.transition 0 * 40
;.stage	* bgc_sch003a01_02.png 0 0 st_kei01a11.png 200 st_mizuki_a01a03.png 600
.stage	* bgc_sch003a01_02.png 0 0 st_kei01a11.png 200 st_mizuki_a01a03.png:[0,0,0]or_mizuki02a.png 600
;�����α��飬ע��Τ��ȣ�
.message	840	kei-107_02-0041	�@�i�@	�������ؼ���
.message	850			���Ÿ��ӵı��飬������Ļ������֡�
.transition 0 * 20
.stage	* bgc_sch003a01_02.png 0 0
.message	860			Ȼ��������ô����ɽ�����뿪�ˡ�
.message	870		�@�h�@	����ʲô����
.message	880			���ɵ����������
.message	890			��ɽ�ǰ׳գ�Ҳ̫������ʱ���˰ɡ�
.message	900		�@�h�@	��������������ˡ�
.message	910			Ҳ������û�о����Ժ���ʱ���ٶ���Щ�ɡ�
.message	920			����֮����һ���ء�
.panel 0
.overlay * *
.playBGM *
.transition 0 * 10
.stage	* WHITE.png 0 0

.chain 107_04.sc
;��107_04�ء�

;.end
