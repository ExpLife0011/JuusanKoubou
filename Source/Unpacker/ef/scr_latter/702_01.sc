

.setGlobal EYE_SEQ_DEFAULT = 2

.pragma enable_control


.if ef_702_01 == 1 ef_702_01_b1
.if ef_702_01 <= 0 ef_702_01_a1


.label ef_702_01_a1

.pragma disable_control

.goto ef_702_01_b1
.end

.label ef_702_01_b1





.playBGM *
.panel 3
.transition 0 * 10
.stage	* WHITE.png 0 0
.wait 300
.playBGM efBGM026mix.ogg
.transition 0 * 10
.stage	vista_window2.png ev00_012a01_70002a.png 1500 500
.scroll	400 1167	10
.endScroll f



.wait 100

.transition 0 * 20
.stage	vista_window2.png ev00_015a02_70002a.png 0 0
.message	140	yuk-702_01-0003	#�D�@�q	�����Ǳ��˵������ء�����\v\a
.wait 50
.message	150	yuk-702_01-0005	#�D�@�q	��ʧȥ�ļ��䡭������Ҳȡ�������ˣ�ʲô�ġ�����\v\a
.wait 50
.transition 0 * 20
.stage	vista_window2.png ev00_014a01_70002b.png 0 0
.message	160	him-702_01-0003	#�@�[�@	��������ȡ����������Ȼ��ʧȥ�˼��䣬����ǧѰ���������ȹ���ʱ�����������Ҳ������ʧ�ġ�\v\a
.wait 40
.message	170	him-702_01-0005	#�@�[�@	������ʧ�ĺ��޺ۼ�֮������顪�����Բ��ᷢ����\v\a
.wait 50
.transition 0 * 20
.stage	vista_window2.png ev00_012a01.png 0 0
.message	180	yuk-702_01-0007	#�D�@�q	����ʹ�ǲ����εĶ�����Ҳһ���ܴ��ﵽʲô�ط�ȥ��\v\a
.wait 50
.message	190	yuk-702_01-0009	#�D�@�q	�����������������飬û��ϵ�𣿡�\v\a
.wait 50
.message	200	him-702_01-0007	#�@�[�@	�����Űɣ����ǲ��ò��š�\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_014a03.png 0 0
.message	240	him-702_01-0009	#�@�[�@	����ʹ����Ļ��䣬Ҳû����ʧ��\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_013a05_close.png 0 0
.message	250	yuk-702_01-0011	#�D�@�q	���ҵĻ��䡭����\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_013a05.png 0 0
.message	260	yuk-702_01-0013	#�D�@�q	�����ǣ���ʧȥ�Ķ����Ѿ�����ʤ�����ء�\v\a
.wait 120
.transition 0 * 20
.stage	vista_window2.png ev03_056a03.png 0 0
.message	280	yuk-702_01-0015	#�D�@�q	�����������������������������ܲ������ӡ�����\v\a
.wait 150
.message	290	yuk-702_01-0017	#�D�@�q	��������������һ��ȹ���ʱ�䣬���Ǳ�����ô�������项\v\a
.wait 70
.message	300	yuk-702_01-0019	#�D�@�q	�����������Ҳ�Ѿ���ʧ��ң���ɼ���\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_014a03_mugai_a.png 0 0
.message	320	him-702_01-0011	#�@�[�@	���һ��ǵá�����һ��ȹ���ʱ�䣬���ڡ����κ����鶼û�����ǡ�\v\a
.wait 70
.transition 0 * 20
.stage	vista_window2.png ev00_017.png 0 600
.message	330	yuk-702_01-0021	#�D�@�q	�����������һ��������𣿡�\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png prologue_mugai_i2.png 0 0
.message	340	him-702_01-0013	#�@�[�@	�����������ɡ�\v\a
.wait 80
.transition 0 * 20
.stage	vista_window2.png prologue_mugai_d.png 0 0
.message	350	him-702_01-0015	#�@�[�@	����ݼ��䲻�������ҵĶ�����\v\a
.wait 100
.message	360	him-702_01-0017	#�@�[�@	����Ȼ�кܶ�ʹ������飬���Ƕ���������˵���Ǿ��Բ�������Ļ��䡹\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png prologue_mugai_c.png 0 0
.message	370	yuk-702_01-0023	#�D�@�q	�������ǡ�\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_014a01_mugai_a.png 0 0
.message	380	him-702_01-0019	#�@�[�@	����Ϊ��Ԥ���ŵļ��䡪�����ڿ�ʼ�������㡹\v\a
.transition 0 * 10
.stage	vista_window2.png WHITE.png 0 0
.wait 100
.playBGM *
.transition 0 * 10
.stage	* WHITE.png 0 0

.setGlobal ef_702_01 = 1

.pragma enable_control



.chain 400_01.sc
