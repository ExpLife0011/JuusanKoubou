; �ե�����: 701_01.txt
;��Ļ�g�������½K���ᣩ
;���̻��ڣ������������������r
;�������������Ϧ����˽������
;������������m���ӣ�˽������



;;����Ӱ�����å�
;;�������L�äη�᪥�����ץ�����
;;��----------------------------------------------
.if ef_clear == 1 ef_701_b
.if ef_clear <= 0 ef_701_a
;
.label ef_701_a

;����Ӱ�����å�
;�������`�����o��
.pragma disable_control

.goto ef_701_b
.end
;
.label ef_701_b
;;��----------------------------------------------



.setGlobal EYE_SEQ_DEFAULT = 2
.transition 0 * 10
.stage	* WHITE.png 0 0
.wait 500
;.transition 0 * 10
;.stage	* terop_10001a.png 0 0
;.wait 450
;.transition 0 * 10
;.stage	vista_window2.png WHITE.png 0 0
;.playBGM efBGM053_2.ogg


;����Ӱ�����å�
;�����򾮤��󤫤�ָժ�����ä��Τ�����
;�������ä��Τۤ��������ä����������_���ˡ�
;.playBGM efBGM026mix.ogg
.playBGM efBGM016.ogg


.transition 0 * 10
.stage	vista_window2.png ev00_017.png 0 0
;.stage	* bgc_normal012a01_03.png 0 0
;���m���˒���ǣ�������`�뤵���Ƥޤ���
.vscroll	600	10
.endScroll f
.transition 0 * 10
.stage	vista_window2.png ev00_015a01.png 0 0
;���䤷�����äѤ�����Ǥޤ��������ĵؐ����褦�ʤ�����
.panel 3
.message	100	yuk-701_01-0003	#�D�@�q	��Ȼ�󩤩���\v\a
:.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_015a03.png 0 0
;������ȥե��`�ɥ��ԩ`�ɤ�ע�⤷�ƣ�
;���m�����ä��Ƥ��ǣ����Ҫ����Τ��ȣ�
.message	110	yuk-701_01-0005	#�D�@�q	����Щ�����ǣ�����Ҳ����������ﻶ��Ц�\v\a
.wait 100
.panel 3
.message	120			���Ӵ���Ц��˵���ģ�����Ƴ������Ƴ��ޱȵĹ������ڽ����ˡ�\a
.wait 290
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_013a02.png 0 0
;���ΤǤ�һ�ر���仯�����뤿��ˣ�������a01�ǣ���
.panel 3
.message	130	yuk-701_01-0007	#�D�@�q	����ʵ�أ�����������һ��ȥ���ء�\v\a
:.wait 300
.transition 0 * 20
.stage	vista_window2.png ev00_013a04.png 0 0
;��������a04����ǣ���
.message	140	yuk-701_01-0009	#�D�@�q	��������ֳ��������˵ļ���֮�����ء�\v\a
:.wait 200
.panel 3
.message	150			��Ȼ����ź���˵�ţ������ӵ������г���������ı��顣\a
.wait 300
.message	160			��ţ����Ѿ������Լ����������е����˰ɡ�\a
.wait 280
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_014a02_mugai_a.png 0 0
.panel 3
.message	170	him-701_01-0003	#�@�[�@	���賓����\v\a
:.wait 100
;.wait 200
.wait 30
;.transition 0 * 20
.transition 0 * 15
.stage	vista_window2.png ev00_014a04_mugai_a.png 0 0
;������仯���ե��`�ɥ��ԩ`�ɤˤ�ע�⤷�ƣ�
.message	180	him-701_01-0005	#�@�[�@	��������Ҫһ���棬Ҳ���ܺ���������һ�𰡡�\v\a
:.wait 300
.transition 0 * 20
.stage	vista_window2.png ev00_013a03.png 0 0
;������Ȼ���������Ȥ�������ˤ�ע�⤷�ơ��ޤ���������夬���줷���ʤ���ʣ�������
.message	190	yuk-701_01-0011	#�D�@�q	����ѽ��\v\a
:.wait 100
;.wait 200
;�����Ӥ�Ŀ���Ĥ�餻�룿��
.message	200	yuk-701_01-0013	#�D�@�q	��������أ��һ����е�Ŷ��\v\a
:.wait 300
.panel 3
.message	210			����ת˲��Щʧ����\a
.wait 220
.message	220			���Ǻ�����Щ�������������������֡�\a
.wait 270
.panel 3
.message	230	him-701_01-0007	#�@�[�@	����Ǹ��˵Ц������������⡹\v\a
:.wait 200
.wait 20
.message	240	yuk-701_01-0015	#�D�@�q	�������������ŵ����ء�����\v\a
:.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_014a01_mugai_a.png 0 0
;��Ϧ�α���ˤϚݤ�Ĥ��ơ���ä���餫����Τ򣿣�
.message	250	him-701_01-0009	#�@�[�@	��Ȼ��������������Ĺ��𣿡�\v\a
:.wait 200
;.wait 300
.transition 0 * 20
.stage	vista_window2.png ev00_013a03.png 0 0
;��a05��close�Ǥ⣿��
.message	260	yuk-701_01-0017	#�D�@�q	�������ڻ�ˮ����Ŷ�������������ŵ����ء�����\v\a
:.wait 300
.panel 3
.message	270			��������̾�˿�����\a
.wait 250
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_013a02.png 0 0
.panel 3
.message	280	yuk-701_01-0019	#�D�@�q	���͹�������һ��Ŷ��\v\a
:.wait 200
.message	290	yuk-701_01-0021	#�D�@�q	���Ѿ������ټ�������С��͵��������ء�\v\a
:.wait 300
.transition 0 * 20
.stage	vista_window2.png ev00_014a05_mugai_a.png 0 0
.message	300	him-701_01-0011	#�@�[�@	�����𡭡���\v\a
:.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_013a01.png 0 0
;�����Ҥ�������Ц�äơ�����������ˤ�ע�⤷�ƣ�
.message	310	yuk-701_01-0023	#�D�@�q	�����ǣ�����Ҳ�ܺ��ء�\v\a
:.wait 200
.message	320	yuk-701_01-0025	#�D�@�q	����Ϊ���Ƕ��Ѿ��������Լ��Ľ��߳�ȥ���ء�\v\a
:.wait 300
.message	330	him-701_01-0013	#�@�[�@	������������\v\a
:.wait 200
.panel 3
;��������014�ãǤ����У���
.message	340			���Ӵ��ĵ׸��˵�Ц������Ȼ����������Զ����\a
.wait 290
.message	350			��˫�۾��峺͸�������ҳ�����ůů�����ᡭ����\a
.wait 310
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_014a01.png 0 0
;��Ϧ�α���ˤ�ע�⤷�ƣ�
.panel 3
.message	360	him-701_01-0015	#�@�[�@	�������������ֵ��������ء�\v\a
:.wait 200
.message	370	yuk-701_01-0027	#�D�@�q	���ҡ�������\v\a
:.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_014a03.png 0 0
.message	380	him-701_01-0017	#�@�[�@	���ԡ�\v\a
:.wait 200
.wait 50
.message	390	him-701_01-0019	#�@�[�@	����Ϊ�㣬��ʧȥ�Ķ�����\v\a
:.wait 300
.message	400	yuk-701_01-0029	#�D�@�q	�������ԡ�\v\a
:.wait 200
.panel 3
.message	410			���Ӱ�Ŀ���ջأ�������������˵�ͷ��\a
.wait 260
.panel 3
.message	420	yuk-701_01-0031	#�D�@�q	������Ҫ�Ķ������Ѿ����Ҷ�ȥ��\v\a
.wait 100
:.wait 300
.message	430	yuk-701_01-0033	#�D�@�q	���������µģ�ֻ��Щ��ļ����Ƭ������\v\a
:.wait 300
.message	440	him-701_01-0021	#�@�[�@	���������ԡ�\v\a
:.wait 200
.panel 3
.message	450			����ű��˵����ӣ���������¶����ԡ�\a
.wait 270
.message	460			������һֱ����;���������ԣ���������������ȷ�ĵط���\a
.wait 320
.message	470			��ֻ���������Լ���һֱ��ʧ����Ҫ�Ķ���ͣ�����⩤��\a
.wait 310
.panel 3
.message	480	him-701_01-0023	#�@�[�@	����ʧ�Ķ�������ȡ�����ͺá�\v\a
.wait 100
:.wait 300
.message	490	him-701_01-0025	#�@�[�@	���һ�Ϊ��ȡ������\v\a
:.wait 200
;��΢Ц
.transition 0 * 20
.stage	vista_window2.png ev00_012a01.png 0 0
;�����ˤα��飬���ΣãǤǤ����Τ��ˤ�ע�⤷�ƣ�
.message	500	yuk-701_01-0035	#�D�@�q	�����������ӣ��㻹����ôǿӲ��Ƣ���ء�\v\a
:.wait 300
.message	510	him-701_01-0027	#�@�[�@	����Ҳ���뿴���������Ұɣ���\v\a
.wait 100
:.wait 300
.message	520	yuk-701_01-0037	#�D�@�q	���㵽����Ϊֹһֱ��û�ж�ʧ����Ƿݼ�ǿ�ء�\v\a
.wait 100
:.wait 400
;.wait 300
.message	530	yuk-701_01-0039	#�D�@�q	����Ȼ�����㽵ģ���ǿ������Ļ���������\v\a
.wait 200
;���愇
.message	540	yuk-701_01-0041	#�D�@�q	������ȴ��һ����\v\a
:.wait 200
.message	550	him-701_01-0029	#�@�[�@	��û�в�һ����\v\a
:.wait 200
.message	560	yuk-701_01-0043	#�D�@�q	���ǲ�һ���İ������Ѿ����ˡ�����\v\a
:.wait 300
.panel 3
.message	570			һ����Ǹ�����ӣ����ӵı�������������\a
.wait 250
.message	580			����ʧȥ�������Ķ�������\a
.wait 270
.panel 3
.message	590	him-701_01-0031	#�@�[�@	��������㡣���ٶ�����˵��������\v\a
.wait 150
;.wait 100
;���Ť���Ц��
.message	600	yuk-701_01-0045	#�D�@�q	����Ȼ�㻹������Ĺ����ء�����\v\a
:.wait 300
.wait 40
.panel 3
.message	610			�����������ᡣ\a
.wait 270
.message	620			������һֱ���š�\a
.wait 270
.message	630			������Ȼ���Ǹ����ӡ�\a
.wait 300
.message	640			ֻ�Ƕ�����Щ����ɥʧ���Ѱɣ�\a
.wait 280
;���愇
.panel 3
.message	650	yuk-701_01-0047	#�D�@�q	����һ����������𣿡�\v\a
:.wait 200
.message	660	him-701_01-0033	#�@�[�@	��ʲô����\v\a
.wait 100
.message	670	yuk-701_01-0049	#�D�@�q	����Ҳ��֪���ء�\v\a
:.wait 200
.message	680	him-701_01-0035	#�@�[�@	����֪������\v\a
:.wait 200
.message	690	yuk-701_01-0051	#�D�@�q	��������֪������Ĺ��©������������ɡ�\v\a


.panel 0
.wait 200
;.playBGM * 0 7
.playBGM * 0 10
.transition 0 * 7
.stage	* BLACK.png 0 0

;��----------------------------------------------
.if ef_clear == 1 mozi

;.movie 10000 ef_first.avi 800 600 f
.movie 10000 ed_moji_test.avi 800 600 f
.goto movie
.end
;��----------------------------------------------
.label mozi
;.movie 10000 ef_first.avi 800 600 t
.movie 10000 ed_moji_test.avi 800 600 t
;��----------------------------------------------

.label movie



;.wait 320
.wait 120
.playBGM *
.wait 80


;����Ӱ�����å�
;�������`�����Є�
.pragma enable_control


;����`�ө`�����趨�w����
;���⤷λ�ä����ä��Ȥ��Ƥ⣬�ؤ�����`�ө`ͻ��ǰ��
;�����`�������Є��ˤ��뤳�ȡ�
;��----------------------------------------------
.if ef_clear == 1 2nd

;������Ļ�g�����i����裦��first tale�����ꥢ�ե饰
.setGlobal ef_clear = 1
;.movie 10000 ef_first.avi 800 600 f
.movie2 ef_first.avi 800 600 ef_first.ogg 44100 2 f

;.transition 0 * 4
;.stage	* BLACK.png 0 0
.wait 120

;.movie2 ef_ED.avi 800 600 ef_ED.ogg 44100 2 f
.movie2 ef_ED.avi 800 600 ef_ED2.ogg 44100 2 f
.wait 600

.end
;��----------------------------------------------

.label 2nd
;.movie 10000 ef_first.avi 800 600 t
.movie2 ef_first.avi 800 600 ef_first.ogg 44100 2 t

;.transition 0 * 4
;.stage	* BLACK.png 0 0
.wait 120

;.movie2 ef_ED.avi 800 600 ef_ED.ogg 44100 2 t
.movie2 ef_ED.avi 800 600 ef_ED2.ogg 44100 2 t
.wait 600

.end
;��----------------------------------------------





;����Ӱ�����å�
;�������¤Υ�����ץȤϣ����٤ƥ����ȥ����Ȥ��ޤ���
;����ʹ��ʤ��ãǤ�ʤˤ������Ҥä����äƤ��ޤ�����ʤΤǡ�

;��----------------------------------------------
;��----------------------------------------------

;:.wait 300
;.panel 3
;.message	700			�擴�ʤޤʤ������򤱤��Ƥ��롣\a
;.wait 280
;.message	710			���Ӥ��v��äƤ������Z�򰳤�֪�ꤿ���ä��褦�ˡ�\a
;.wait 290
;.message	720			��Ů�ϿհפΕr�g���٤��Ǥ���᤿����äƤ���Τ�������\a
;.wait 300
;.panel 3
;.message	730	him-701_01-0037	#�@�[�@	��������ˤϴ󤷤����ȤϤʤ��ä��ʡ����ƽ�����ա����ä��衹\v\a
;.wait 100
;:.wait 300
;.transition 0 * 20
;.stage	vista_window2.png ev00_015a01.png 0 0
;.message	740	yuk-701_01-0053	#�D�@�q	��Ϧ����ƽ����������\v\a
:.wait 200
;;����Ц
;.transition 0 * 20
;.stage	vista_window2.png ev00_015a03.png 0 0
;.message	750	yuk-701_01-0055	#�D�@�q	���ʤ󤫤����󤯤����Ǥ��͡�\v\a
;:.wait 200
;.transition 0 * 20
;.stage	vista_window2.png ev00_014a05.png 0 0
;;����äȡ�����ϵ���Τ򣿣�
;.message	760	him-701_01-0039	#�@�[�@	�����ޤ����ˤ�ɤ�����Ŀ��Ҋ�Ƥ�����\v\a
;:.wait 300
;.panel 3
;.message	770			���������Ӥ����ࡣ\a
;.wait 250
;.panel 0
;.transition 0 * 20
;.stage	vista_window2.png ev00_014a03.png 0 0
;;��Ϧ�α��飬ע�⤷�ƣ�
.panel 3
;.message	780	him-701_01-0041	#�@�[�@	��������Τ��ȤϤȤ⤫����\v\a
;.wait 100
;:.wait 100
;;.wait 200
;.transition 0 * 20
;.stage	vista_window2.png ev00_014a01.png 0 0
;.message	790	him-701_01-0043	#�@�[�@	���Ť����ʤ��褦�����g�Ȼ�ä��ꤷ���ʡ�\v\a
;:.wait 300
;.transition 0 * 20
;.stage	vista_window2.png ev00_013a01.png 0 0
;.message	800	yuk-701_01-0057	#�D�@�q	�����飬�l�Ǥ�������\v\a
;:.wait 200
;.message	810	him-701_01-0045	#�@�[�@	�������Ԓ���ˤϤ���äȕr�g�򤵤��Τܤ�ʤ��㤤���ʤ���\v\a
:;.wait 300
;.message	820	him-701_01-0047	#�@�[�@	�����Ȥ��ޤ����^ȥ�ˤ��v�S�Τ��뤳�Ȥ���\v\a
:;.wait 300
;.transition 0 * 20
;.stage	vista_window2.png ev00_013a03.png 0 0
;.message	830	yuk-701_01-0059	#�D�@�q	��˽�����Ρ�������\v\a
;:.wait 200
;.message	840	him-701_01-0049	#�@�[�@	����������\v\a
;:.wait 200
;.message	850	him-701_01-0051	#�@�[�@	�����䩤������ǰ�ˤ����ӤΤ��Ȥ�Ԓ���Ƥ����ʤ��㤤���ʤ��ʡ�\v\a
;:.wait 300
;.message	860	yuk-701_01-0061	#�D�@�q	�������ӣ���\v\a
;.wait 100
;:.wait 200
;;������Ŀ
;.message	870	yuk-701_01-0063	#�D�@�q	�������Ӥä�Ů���Ӥʤ�Ǥ��ͣ���\v\a
;:.wait 200
;.wait 30
;.message	880	him-701_01-0053	#�@�[�@	����ʤȤ����䄤��ʣ����ޤ��ϡ�\v\a
;:.wait 200
;.message	890	yuk-701_01-0065	#�D�@�q	������Ǥ�˽��Ů���ӤǤ��Τǡ�\v\a
;:.wait 200
;.panel 3
;.message	900			�٤��C�Ӥ������ʤä��褦����\a
;.wait 270
;.panel 0
;.transition 0 * 20
;.stage	vista_window2.png ev00_014a01.png 0 0
;;��Ϧ�α����ע�⤷�ƣ�
.panel 3
;.message	910	him-701_01-0055	#�@�[�@	�����������Τ���ʤ�������������\v\a
;.wait 100
;.transition 0 * 20
;.stage	vista_window2.png ev00_014a03_mugai_a.png 0 0
;;��a01_mugai_a�ǣ���
;.message	920	him-701_01-0057	#�@�[�@	�������ӤΤ��Ȥ�Ԓ���ʤ��ȣ����������ˤ������ɤ��Z��ʤ������\v\a
;:.wait 300
;.panel 3
;.message	930			���Ӥ�Ԓ�������Z��\a
;.wait 250
;.message	940			�����˵ǈ�����Ȥ��ƬF������Ӥ򰳤�֪��ʤ��ä���\a
;.wait 300
;.message	950			ͬ���褦�ˣ����Ӥ�֪��ʤ����⤤��Τ���\a
;.wait 290
;.panel 3
;.message	960	him-701_01-0059	#�@�[�@	����Ů���������飬�������Ӥ������Ǵ��äƤ���ä�֪�뤳�Ȥ��Ǥ�������衹\v\a
;.wait 100
;.transition 0 * 20
;.stage	vista_window2.png ev00_014_mugai_b.png 0 0
;;�����ΣãǤ����ФǤ����Τ���ע�⤷�ƣ�
;.message	970	yuk-701_01-0067	#�D�@�q	��˽�Τ��Ȥ򡭡������Ӥ�Ϧ����ˣ���\v\a
;:.wait 300
;.message	980	him-701_01-0061	#�@�[�@	���������衣ֱ�ӤäƤ櫓����ʤ����ɤʡ��٤ʤ��Ȥ⣬���ä��������ä����g��һ�ˤ���\v\a
;.wait 100
;:.wait 500
;.message	990	him-701_01-0063	#�@�[�@	������ˣ����ޤ���Ԓ�������Z�Ȥ���v����֤äƤ��롹\v\a
;:.wait 300
;.message	1000	yuk-701_01-0069	#�D�@�q	�����������Ӥϣ��l�ʤ�Ǥ�������\v\a
;:.wait 200
;.message	1010	him-701_01-0065	#�@�[�@	����Ů����ǰ�ϣ�����ǧ����\v\a
;:.wait 200
;.transition 0 * 20
;.stage	vista_window2.png ev00_013a03.png 0 0
;.message	1020	yuk-701_01-0071	#�D�@�q	�����١�������\v\a
;.wait 100
;.transition 0 * 20
;.stage	vista_window2.png ev00_014a03.png 0 0
;.message	1030	him-701_01-0067	#�@�[�@	��������\v\a
;:.wait 200
;.panel 3
;.message	1040			�����ӤΩ�������ǧ����ͫ��×�Y�˸����֡�\a
;.wait 290
;.message	1050			��Ů�����ʤ���У��������Ӥ򤤤ĤޤǤ���������ޤޣ��ա����^�����Ƥ��ä����`���ʤ���\a
;.wait 310
;.message	1060			���x���ʤ��Ȥʣ������Ӥˤϡ�\a
;.wait 290
;.panel 0
;.transition 0 * 20
;.stage	vista_window2.png ev00_014a01_mugai_a.png 0 0
;;������ˤ�ע�⤷�ƣ�
.panel 3
;.message	1070	him-701_01-0069	#�@�[�@	�����ƣ��ɤ�����Ԓ������������\v\a
;:.wait 200
;;�Ŀ��Ĥ�餻�룿��
;.panel 0
;.transition 0 * 10
;.stage	vista_window2.png WHITE.png 0 0
;.wait 100
;.playBGM *
;.transition 0 * 10
;.stage	* WHITE.png 0 0
;
;;��300_01�ء�
.end
