; �ե�����: 200_01.txt
;�������£��ϣУ�
;�������������^���ģ������r
;�����������̾��飺�Ʒ����ģ�
;�������������پ����Ʒ����ģ�
.setGlobal EYE_SEQ_DEFAULT = 2

.transition 0 * 10
.stage	* WHITE.png 0 0
;.wait 500
;.wait 250
.wait 100
.transition 0 * 10
.stage	* ago_base_second.png 0 0
.message	101			\a��
;.wait 450
.wait 300
.transition 0 * 10
.stage	* WHITE.png 0 0

;.transition 0 * 10
.transition 0 * 8
.stage	* ago_base_20001a.png 0 0
;.stage	* ev02_001a01.png 0 0
.panel 1
.message	100			��һ�죬�ҿ���һ����Ů��
.transition 0 * 20
.stage	* ago_base_20001b.png 0 0
.message	110			����Ŀ���������е����򣬷��Ʋ�����վ�����賓��
.transition 0 * 20
.stage	* ago_base_20001c.png 0 0
.message	120			��������б������ĳ��������е���Ӱ������һ˲��Ϊ����һ�����µ���ż��
;.transition 0 * 20
.transition 0 * 10
.stage	* ev02_002a01.png 0 0
;������Υ����ߥ󥰣�ע�⤷�ơ��ե��`�ɥ��ԩ`�ɤˤ�ע�⡣���ԩ`�ɸФ��������ˣ��ʤ�٤��Ϥ䤯����
.message	130			������Ҫ��ʲô������ʼ����
.message	140			�ǳ���������������Ԥ�е���
.message	150			Ϊʲô����ˡ�
.message	160			Ϊʲôƫƫ������ʱ��ȴû�д����������
.message	170			��ô������ҲҪ����⾰����������С�
.transition 0 * 20
.stage	* ev02_002b01.png 0 0
;���ΤǤ��ΣãǤ򣿣�
;�������ޤǥӥ����ǣ�ָ�Ǉ�ä����ȣ������\��Ϥ����ݳ��ǣ���
.message	180			����˫�ֵ�Ĵָ��ʳָ����Ľ��ε�ȡ����
.message	190			����һֻ�ۣ�����Ů��Ȧ��ȡ�����С�
.playSE kei_dribble_twice.ogg f 0 *
.transition 0 * 20
.stage	* ev02_002c01.png 0 0
;���ե��`�ɥ��ԩ`�ɤ�ע�⤷�ƣ�
.message	200			�ˣ��ˡ�
.message	210			������������

;.playSE kei_shoot.ogg f 0 *
.transition 0 * 20
.stage	finder_finger.png ev02_002c02_mugai_a.png 0 32
.vscroll	0	-5
.endScroll f
;��¤˰פϳ��Ƥʤ����������å��Ϥ��ä���ȣ�

;.transition 0 * 20
;.stage	* ev02_002c02.png 0 0
.message	220			Ȼ��ͻȻ������������ְڳ����ơ�
;���Τ��ӣŤ��ä��ۤ����������⡣�ܩ`���Ť����ʤ�Ƥ��뤫��
.playSE kei_shoot.ogg f 0 *
;����ä�ǰ���Q�餹�Τ���ͨ�ʤΤ��⤷��ޤ��󤬣������Ƥ����ǣ�
.transition 0 * 20
.stage	* ev02_003.png 0 0
;��ָ�Ǉ�äƤ��ݳ��ϣ�Ҫ�����뤳�ȣ�
.message	230			Ȼ�����ޱ���˳������Ͷ������

.transition 0 * 20
.stage	finder_finger.png ev02_004a01_big.png 800 600
.transition 0 * 20
.stage	finder_finger.png ev02_004b01_big.png 600 400
.transition 0 * 20
.stage	finder_finger.png ev02_004c01_big.png 400 200

;.transition 0 * 20
;.stage	finder_finger_second.png ev02_004a01_mugai.png 0 0
;.transition 0 * 20
;.stage	finder_finger_second.png ev02_004b01_mugai.png 0 0
;.transition 0 * 20
;.stage	finder_finger_second.png ev02_004c01_mugai.png 0 0
;���B�A�Ǳ�ʾ�����Ƥޤ��������ѥ󤵤��뤫�ɤ����ϱ������ѥͥ�ȥ룿��
;.transition 0 * 20
;.stage	* ev02_005a01.png 0 0
;���ե��`�ɥ��ԩ`�ɤˤ�ע�⤷�ƣ�
.message	240			����ķ�Χ׷Ѱ��������ƶ���
.transition 0 * 20
.stage	* ev02_005a01.png 0 0
.message	250		���@��	����������
.playSE kei_ring.ogg f 0 *
.transition 0 * 20
.stage	* ev02_005b01.png 0 0
.message	260			�ˡ�
.playSE kei_round.ogg f 0 *
.transition 0 * 20
.stage	* ev02_005c01.png 0 0
.message	270			���ǣ���ʲô�ط���̫����
.transition 0 * 20
.stage	* ev02_005d01.png 0 0
.message	280			�����������������һ�ܣ�Ȼ������˵ذ��ϡ�
.playSE kei_ball_korogaru.ogg f 0 *
;������������äȥܩ`�뤬�ϤͤƤ�ФΤ�Τ򣿤��Ȥʤ�������ݤ⤹��Τǣ�
.transition 0 * 20
.stage	finder_finger.png ev02_001b01.png 0 0
.message	290			����΢Ť��ͷ�����ŵ��ڵذ��ϵ�����Ĺ�����
.transition 0 * 20
.stage	* ev02_002b02.png 0 0
;������002b02�ΣãǤ�ʹ���ɤ���ע�⤷�ƣ�
;��������Ʊ�Ů���Ҋ�������������������ݳ���ע�⤷�ƣ�
.message	300			���ʱ���ҲŸո���ʶ����Ů������Ĵ��ڡ�
;.message	300			���ΤȤ�������Ʊ�Ů���Ҋ������
.message	310			��Щȱ�ٻ������Ǹ���ɫ����ǰ�ǵú�����ʲô�ط���������
.message	320			�Ǹ�Ů���ӽ�ʲô�������š�����
.message	330	kei-200_01-0003	@�@�i�@	����û�С��𡭡���
.message	340			��������˵�š�
.message	350			�ǻ���û���κθ��顣
.message	360			��Ϊ�������޻��ʰ�ĸо���ȴ����˵����ҵ����顣
.transition 0 * 20
.stage	* ev02_002b03.png 0 0
.message	370			����һ�ᣬ��Ů��Ŀ��������ƿ���
;���Գ���ζ��
.transition 0 * 20
.stage	finder_finger.png ev02_001b01.png 0 0
;��001b01��ʹ�äƤޤ���������ҕ���Ͼ�����򤤤Ƥޤ�������Ҋ���ʤ��褦�ʤ�����
;.transition 0 * 20
;.stage	finder_finger.png ev02_001c01.png 0 0
;�ָ�ե�`���e�쥤��`��ʹ�����ϣ��Ϥ����ϤˤϤ褯�褯ע�⤷�ƣ�
;���ե��`�ɥ��ԩ`�ɣ���ʾ�����ߥ󥰤ˤ�ע�⤷�ƣ�
.message	380	kei-200_01-0005	@�@�i�@	�����أ���ǰ�����򲿵ġ�����Ȼ�Լ�˵������̫�񻰣��������ܻ�Ծ��Ŷ��
.transition 0 * 20
.stage	* ev02_001b01.png 0 0
;.stage	* ev02_001c01.png 0 0
;�������ǡ��ե�`������äƤ����֡����¤���Τǣ�ע�⤷�ƣ�
.message	390			�ҷ���ȡ�����֡�
.message	400		���@��	��ע�⵽�˰����ѵ�˵�������𣿡�
.message	410	kei-200_01-0007	@�@�i�@	������������ν�������Ƿ��˿��ţ��ҵ��򶼲����ܻ���ġ�
.message	420		���@��	�����ǲ����кܱ�׼��������
.transition 0 * 20
.stage	* ev02_001c01.png 0 0
;�����ΣãǤ�ʹ���ɤ���ע�⤷�ơ�����ˤ������飬�ɤ�����Τ��⣩
.message	430			��������ת�����������濴���ҡ�
.message	440	kei-200_01-0009	@�@�i�@	����Ȼ��Щʧ�񣬵���ûʲô�۲����ء�
.message	450		���@��	��������
;�������
.transition 0 * 20
.stage	* ev02_007a01_mugai_a.png 0 0
;�������Ф�����Ϥ���äȱ����������}�������Ϥ�ꤿ���ʤ��Τǣ��¤������٥�ȣãǤ����äƤ�餦���餤��ҙ���
.message	460	kei-200_01-0011	@�@�i�@	���ҵ�Ͷ��ʲô������ˡ�
.message	470			ͻȻ������Ȼ�ı䡣
.transition 0 * 20
.stage	* ev02_007a02_mugai_a.png 0 0
;��ե��`�ɥ��ԩ`�ɤ�20�Ǥ�����������
;������仯��ע�⡣�ΤǤ��α���򣿣�
.message	480	kei-200_01-0013	@�@�i�@	�����������ñ�׼��������Ͷ�����򣬾��Բ��᲻����������˵��������û�˷��ص�״̬��
.message	490	kei-200_01-0015	@�@�i�@	�������ǰ��ʱ����ң����Բ����ܲ����ġ������ڡ�����
;�������Ŀ�Ĥ��򣿣�
.message	500	kei-200_01-0017	@�@�i�@	�����ǲ��ܿ��ء�
.message	510		���@��	�����������������û��ʲô�۲����ء�
.message	520			Ϊʲô�����������żһ���ء�
.message	530			���Ů��������˼��ҩ���ӵ��������ĸ�����
.message	540			������ȴ��һЩ�Ա������ĸо���
.transition 0 * 20
.stage	* ev02_007a03_mugai_a.png 0 0
;��ե��`�ɥ��ԩ`�ɤ�20�Ǥ�����������
.message	550	kei-200_01-0019	@�@�i�@	���������Ҫ�����ء����ϲ��Ż���˾ͻ����ˡ�
.message	560			�ͺ���ʲô�¶�û�з�����һ�������Ŀ����ָ���ƽ����
.message	570			�ղŵļ��Ҹ�����һ����ʧ���ˡ�
.message	580		���@��	���������ǰ�����Ҳ������˵ĺá�
.transition 0 * 20
.stage	* ev02_007a03_mugai_c.png 0 0
;������Ф�����Ϥ���ä�ע�⣩
.message	590	kei-200_01-0021	@�@�i�@	���ţ��������ȥ�Ļ��ǻᱻ���ȥ��Ŷ�����򲿺����򲿵Ĳ����˶��ܱ�����ء�
.message	600		���@��	���ǻ����ǿ����ء�
;���������Ф�����򣿣�
.transition 0 * 20
.stage	* bg_up002a01_01_mugai_a.png 0 0
;��ե��`�ɥ��ԩ`��ע�⤷�ơ�����ä��W������
.message	610	kei-200_01-0023	@�@�i�@	����ô���Ҿ��ȸ���ˡ�
.message	620			����ʧ��֮���������Ͻ��ĸ��

;����Ӱ�����å�
;.message	630			�ޤ����Ʒ���Ҋ��а��Τۤ�����݅���äƤ狼��������飬���줬��Ȼ�Ȥ����е�Ȼ������

.message	640		���@��	���Ǹ���
.message	650			�Һ�ס���Ѿ�̤���Ų����Ǹ�Ů����
.transition 0 * 20
.stage	* ev02_106a01_mugai_a.png 0 0
.message	660	kei-200_01-0025	@�@�i�@	����ô����
.message	670			������ʾ������վ�����Ȼ��ȥ�������Ƕ�������
;������
.transition 0 * 20
.stage	* ev02_006a01_mugai_a.png 0 0
.message	680	kei-200_01-0027	@�@�i�@	�������Ǹ�����
.message	690		���@��	�����ùܣ����ž��ǡ�
.transition 0 * 10
.stage	* ev02_006a01.png 0 0
;���ե��`�ɥ��ԩ`�ɤ�20�ǣ���
.message	700			����סʰ�������վ����Ů������ߡ�
.message	710			Ȼ�����ص�ѡ��Ŀ�ꩤ��
;.transition 0 * 20
;.stage	* ev02_006b01.png 0 0
.transition 0 * 20
.stage	* ev02_006b01_mugai_a.png 0 0
.message	720			Ͷ��
.playSE kei_board.ogg f 0 *
.transition 0 * 20
.stage	* ev02_100c01.png 0 0
;�b01��ʹ���Τ���ͨ�ʤΤ��⤷��ޤ��󤬣��Ҥͤ���Ƥ���ǣ�
;.transition 0 * 20
;.stage	* ev02_006b01.png 0 0
.message	730			�ˡ�
.playSE kei_round.ogg f 0 *
.transition 0 * 20
.stage	* ev02_006b01.png 0 0
.message	740			���ˡ�
.message	750			���������ӹ�����һ����ײ�������ϣ����������ϻ�����һ�©���
.playSE kei_goal.ogg f 0 *
.transition 0 * 20
.stage	* ev02_006c01.png 0 0
.message	760			Ȼ��৵ģ�������������
;.transition 0 * 20
;.stage	* ev02_006c01.png 0 0
.message	770		���@��	��OK����
.message	780		���@��	����Σ��ҵ����򣿡�
;������Ŀ
.transition 0 * 20
.stage	* ev02_007a01.png 0 0
.message	790	kei-200_01-0029	@�@�i�@	�����Ҫ����
.message	800			������Ц�ݵ�˵����
;��ҕ���ݤ餷
.transition 0 * 40
.stage	* ev02_007a02.png 0 0
;���ե��`�ɥ��ԩ`�ɤϤ�������40�ˤ��Ƥޤ�����ע�⤷�ƣ�
.message	810	kei-200_01-0031	@�@�i�@	�����ǡ�����
.message	820			��΢��Щ��ԥ֮��������һֻ�֡�
.transition 0 * 20
.stage	* ev02_007b01.png 0 0
.message	830	kei-200_01-0033	@�@�i�@	������
.message	840			˵�ţ�������¶����Щ���΢Ц��
.playSE hirate.ogg f 0 *
;��Ϥ뤪�Ȥ�ƽ�������ä��Ƥޤ��������}����褦�ʤ顤��Ц��
;.transition 0 * 20
.transition 0 * 40
.stage	* ev02_007c01.png 0 0
;���ե��`�ɥ��ԩ`�ɤ�40�ǣ���
.message	850		���@��	��л����
.message	860			��ҲЦ�ţ�����������������˹�ȥ��
.message	870			ž��������Щ��������������
.transition 0 * 20
.stage	past_window.png ev02_007c01.png 0 0
;���������ݳ��Ϥ���äȱ�����
.message	880			���˲�䩤���һ������������顣
.transition 0 * 20
.stage	* ago_base_20001d.png 0 0
.message	890			һ���Ƕ�ȥ����֮ʱ��һ�����Ѵ���ѧ԰��ȥ��
.transition 0 * 20
.stage	past_window.png ev02_007d01_mugai01.png 0 0
;.stage	* ago_base_20001e.png 0 0
;.transition 0 * 20
;.stage	past_window.png ev02_007d01.png 0 0
;�����ΣãǤؤ����Х����ߥ󥰣�ע�⤷�ƣ�
.message	900			��һ�����Ǳ�ҵ֮�󣬺��Ǽһ�Ҳ�����������Ƹ��
.transition 0 * 20
.stage	past_window.png ev02_007d01_mugai02.png 0 0
;.stage	* ago_base_20001f.png 0 0
.message	910		���@��	�����������Ǽһ���
.transition 0 * 20
.stage	* ev02_007d01.png 0 0
.message	920			������û�������ҵ����Ļ���ȴ��֪Ϊ�ν��������Լ������ơ�
.message	930			������������������������
.transition 0 * 20
.stage	* ev02_007a03.png 0 0
;���ե��`�ɥ��ԩ`�ɤˤ�ע�⤷�ƣ�
.message	940	kei-200_01-0035	@�@�i�@	����ô�������ġ����и���ˡ�
.message	950		���@��	��������
.transition 0 * 20
.stage	* ev02_008b01.png 0 0
;.stage	* bg_up002a01_01.png 0 0
;����å��ñ��������ä��Ƥ��ޤ�������������ݳ��ˤ�ע�⤷�ƣ�
.message	960			�������������ݵ����뿪���ҽ�������ȭͷ��
.message	970			��ѧ԰�뿪�����ѣ����˵����ð�Ĵ��ڡ�
.message	980			1�꼶�������򲿵�����������������2�꼶֮ǰ�뿪���ŵ�Ů����
.transition 0 * 20
.stage	* ev02_008a01.png 0 0
;�����ȡ�����ˤ��뤫����
;.stage	* bg_up002a01_01_mugai_b.png 0 0
.message	990		���@��	�����ˡ�
.message	1000		���@��	���ǽ����پ�ͬѧ����û��ɡ�
.message	1010			�Ǿ����������֡�
.transition 0 * 20
.stage	* WHITE.png 0 0
;���פˤ����Ҫ�Ϥʤ����⤷��ޤ��󤬡��ե��`�ɥ��ԩ`�ɤˤ�ע�⤷�ƣ�
.message	1020			��һ��ȹ�������ȵļ��ڵ����پ���������������������������ˡ�



;����Ӱ�����å�
.panel 0
.wait 50
;.wait 170
;.transition 0 * 9
;.transition 0 * 10
;.stage	* WHITE.png 0 0
;.wait 260
.wait 100
.transition 0 * 8
.stage	* second_title.png 0 0
.message	1021			\a��
.wait 350


;.panel 0
;.transition 0 * 10
;.stage	* WHITE.png 0 0
;.transition 0 * 10
.transition 0 * 8
.stage	* WHITE.png 0 0
;.wait 100
.wait 50

.chain 201_01.sc
;��201_01�ء�

;.end
