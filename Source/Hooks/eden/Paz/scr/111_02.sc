; �ե�����: 111_02.txt
;�����Ӥ�Ҋ���Ф���
.message	100			��֮��ȥ��һ�������ɡ�
.message	110			����������������Ϊ��͵�����Է��ǹ��ӵĻ�������ν��
;���������ץХå�
.transition 0 * 20
.stage	* ev01_141a01.png 0 0
;���ץХå��ǤϤʤ����٥�ȣãǤǄI���Ƥޤ���
.message	120		�@�h�@	��ι�������ӡ�
.message	130		�@�h�@	������������
.message	140			û�лش�
.message	150		�@�h�@	����˵ι�����ӣ���
.playSE hiro_knock.ogg f 0 *
;���ɥ�ɥ�ã�������������ʤ��Τǣ�ע�⤵�줿����Ҫ�ӹ��Τ��ȣ�
.transition 0 * 40
.stage	* ev01_141b01.png 0 0
;���ե����ɥ��ԡ��ɤˤ�ע�⡣������������Τ��ȣ�

;����Ӱ�����å�
;����SE�����¤�����ʤ��ʡ�
;���������ޤǏ���ߵ���ۤɻŤƤ�r�g����ʤ�����
;.message	160			�ɥ�ɥ�ɥ�
;.message	170			�������˾A���ɥ���ߵ���ʤ�����Ӥ����Ƥߤ롣
.message	160			���ˡ�
.message	170			��һ�����Ÿ����ҵ���һ�ߺ���

.transition 0 * 20
.stage	* ev01_141a01.png 0 0
;���ե����ɥ��ԡ��ɤ�ע�⡣�Τ�̨�~�Ǥ��ΣãǤ򣿣�
.message	180		�@�h�@	������������
.message	190			��Ȼû�з�Ӧ��
.message	200		�@�h�@	��������ȥ��Ŷ��
;�������ӹ�
.message	210	miy-111_02-0003	�݂₱	��������ʱ��Ҫ�򱨸�Ŷ����
.message	220		�@�h�@	���㻹�����𣡡�
;�������ӹ�
.message	230	miy-111_02-0005	�݂₱	�����Ѿ�������Ҫ�������ķ�һ�����ȥ�˰�����
.message	240		�@�h�@	���һ�û������
.message	250			�ɶ񣬰׵����ˡ�
.message	260			���ְ׳գ����²��ܺ��ˡ�
;�������ӹ�
.message	270	miy-111_02-0007	�݂₱	��лл�㡫��
.message	280		�@�h�@	��������
.message	290			��ͣ����׼��̤��ȥ�Ľš�
;�������ӹ�
.message	300	miy-111_02-0009	�݂₱	���ҡ��ո�˯���ˡ�
.message	310		�@�h�@	�������㻹��û����������
;�������ӹ�
.message	320	miy-111_02-0011	�݂₱	�������ھͳ�ȥ�����ܲ���׼��һЩ���Ķ����ء�
.message	330			ԭ����ˣ�������ȫ��ͷ���˰���
.message	340		�@�h�@	��������ʱ��ע��Ŷ��
;�������ӹ�
.message	350	miy-111_02-0013	�݂₱	���ˡ��⡹
.panel 0
.transition 0 * 10
.stage	* WHITE.png 0 0


;�����������μҤ�ǰ�����������r
;������������Ұ��������˽��������
;�������������幬�ӣ��Ʒ�������
;.screen sc_night01.png sc_night01.png
;.overlay * or_miyako03a01.png
.playBGM efBGM027.ogg
.transition 1 fadeSide.png 10
.overlay	or_miyako03a01_620p.png * *
.screen	sc_night01_620p.png sc_night01_620p.png sc_night01_620p.png
.stage	st_miyako12a05-.png 0 0 bg_scl008a01_03.png 0 0 bg_scl008a01_03.png 0
.effect	WScroll2 * 60 -2


;.transition 1 fadeSide.png 10
;.stage	* bgw_normal015a01_03.png 0 0 st_miyako08a03.png 410
;������ע�⡣��ä�Ԫ�ݤʱ���ǣ�����
;��Ȥꤢ����ͨ�������ǥ��󤷤Ƥޤ������g�H����åךi�����������
.panel 1
.message	360	miy-111_02-0015	�݂₱	���������������ء���
.message	370			�Ա����ŵĹ��ӣ�ž�žવĽ⿪��ۡ�
.message	380		�@�h�@	��ιι���������㡹
.message	390			��Ȼ�������������ں��ȣ����������ð�İ���
.transition 0 * 40
.stage	st_miyako11a08-.png 0 0 bg_scl008a01_03.png 0 0 bg_scl008a01_03.png 0
;.transition 0 * 40
;.stage	* bgw_normal015a01_03.png 0 0 st_miyako08a02.png 410
.message	400	miy-111_02-0017	�݂₱	���������𣿡�
.message	410			����������ô�ɰ����ʷ�Ҳ�ǲ����ԡ�
.message	420			��ҡҡͷ��
.message	430		�@�h�@	�����˸Ͽ���Ҹ�ס��
.transition 0 * 40
.stage	st_miyako11a02-.png 0 0 bg_scl008a01_03.png 0 0 bg_scl008a01_03.png 0
;.transition 0 * 40
;.stage	* bgw_normal015a01_03.png 0 0 st_miyako07a02.png 410
;��07a03�Ǥ⣿��
.message	440	miy-111_02-0019	�݂₱	���ǡ���
.chain 111_04.sc
;��111_04�ء�

;.end
