.setGlobal EYE_SEQ_DEFAULT = 2

.transition 0 * 10
.stage	* WHITE.png 0 0
.wait 500

.transition 0 * 10
.stage	vista_window.png ago_base_40000a.png 0 0
.panel 3
.message	100	yuk-400_01-0003	�D�@�q	���ҽ�������Ӵ��
.message	110	mid-400_01-0003		�̻�֮ǰ��Ư����Ů����΢Ц�š�
.transition 0 * 20
.stage	vista_window.png ago_base_40000c4.png 0 0
.message	120	mid-400_01-0005		���ǣ��һ�������������֮ǰ�������Ĺ��¡�
.transition 0 * 20
.stage	vista_window.png ago_base_40000c5.png 0 0
.message	130	mid-400_01-0007		���ǣ��ں��յ�ĳ�վ�Ļ�������ͬ�ģ����վ�ͷ��һĻ��
.transition 0 * 20
.stage	vista_window.png ago_base_40000c6.png 0 0
.message	140	mik-400_01-0003	#���@��	�����ӡ�
.transition 0 * 20
.stage	vista_window.png ago_base_40000c7.png 0 0
.message	150	yuk-400_01-0005	�D�@�q	������������
.transition 0 * 20
.stage	vista_window.png ago_base_40000c1.png 0 0
.message	160	yuk-400_01-0007	�D�@�q	�����ţ������ӡ���������ǣ���
.message	170	mid-400_01-0009		Ů����΢�����£�ѯ�����������֡�
.message	180	mik-400_01-0005	#���@��	������������
.transition 0 * 20
.stage	vista_window.png ago_base_40000c2.png 0 0
.message	190	yuk-400_01-0009	�D�@�q	����������
.transition 0 * 20
.stage	vista_window.png ago_base_40000c3.png 0 0
.message	200	yuk-400_01-0011	�D�@�q	����㣬��֪���������Ӵ����
.message	210	yuk-400_01-0013	�D�@�q	����֪��Ӵ����
.message	220	mik-400_01-0007	#���@��	��������ϣ��
.message	230	mid-400_01-0011		�ں��Ӱ�������к��У�����³�Ļش�
.message	240	yuk-400_01-0015	�D�@�q	����ϣ�����𣿡�
.message	250	mik-400_01-0009	#���@��	��δ����
.message	260	yuk-400_01-0017	�D�@�q	���������ĸ�������
.message	270	mik-400_01-0011	#���@��	��д����δ�����ͣ�ң�飩�������Ƕ�������ϣ���ͣ�ˣ飩��������
.message	280	yuk-400_01-0019	�D�@�q	������ԭ����������
.message	290	mid-400_01-0013		���������ʲô�Ƶģ��Գƽ������ӵ�Ů�ˣ�¶���������Ц�ݡ�
.message	300	yuk-400_01-0021	�D�@�q	���ţ��Ǹ��������ء�
.message	310	mik-400_01-0013	#���@��	�����¡�

.playSE yuuko_kachin.ogg f 0 *

.transition 0 * 10
.stage	vista_window.png WHITE.png 0 0


.message	330	mid-400_01-0017		ֻ������΢���Ŀ���������������������һʱ���ԣ��໥�����ŶԷ���
.message	340	mid-400_01-0019		����һ��ƽ�������������
.message	350	mid-400_01-0021		���ǣ�һ�е�Դͷ����ȷ�Ǵ����￪ʼ�ġ�
.transition 0 * 10
.stage	* vista_white.png 0 0
.panel 0
.playBGM *



.panel 0
.transition 0 * 8
.stage	* BLACK.png 0 0
.wait 400





.if ef400_01 == 1 400_01_b1
.if ef400_01 <= 0 400_01_a1

.label 400_01_a1
.movie2 op2.avi 800 600 op2.ogg 44100 2 f

.pragma disable_control

.goto 400_01_c1
.end

.label 400_01_b1
.movie2 op2.avi 800 600 op2.ogg 44100 2 t
.goto 400_01_c1
.end


.label 400_01_c1



.setGlobal ef400_01 = 1




.transition 0 * 8
.stage	* BLACK.png 0 0
.wait 300

.transition 0 * 10
.stage	* WHITE.png 0 0


.pragma enable_control


.chain 400_02.sc
