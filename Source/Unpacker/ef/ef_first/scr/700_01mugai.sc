; �ե�����: 700_01.txt
;��Ļ�g�������¤ȣ��¤��g��
;���̻��ڣ������������������r
;�������������Ϧ����˽������
;�����������깬���ӣ�˽������


;;����Ӱ�����å�
;;�������L�äη�᪥�����ץ�����
;;��----------------------------------------------
.if ef_700 == 1 ef_700_b
.if ef_700 <= 0 ef_700_a
;
.label ef_700_a

;����Ӱ�����å�
;�������`�����o��
.pragma disable_control

.goto ef_700_b
.end
;
.label ef_700_b
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
.playBGM efBGM026mix.ogg
.transition 0 * 10
.stage	vista_window2.png ev00_017.png 0 0
;.stage	* bgc_normal012a01_03.png 0 0
;���m���˒���ǣ�������`�뤵���Ƥޤ���
.vscroll	600	10
.endScroll f
.transition 0 * 10
.stage	vista_window2.png ev00_015a03.png 0 0
;���䤷�����äѤ�����Ǥޤ��������ĵؐ����褦�ʤ�����
.panel 3
.message	100			����ĺ���һ��������������΢Ц������\a
.wait 270
.message	110			��Ȼ������䣬��������Ц��ȴ������������Щ��\a
.wait 290
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_015a01.png 0 0
;������ȥե��`�ɥ��ԩ`�ɤ�ע�⤷�ƣ�
.panel 3
.message	120	yuk-700_01-0003	#�D�@�q	���͹�Ұ�������������Ѿ�����һ�����ء�����\v\a
.wait 100
:.wait 300
.message	130	him-700_01-0003	#�@�[�@	������1������ں��Ǹ���Ƨ��С���򽻵�����\v\a
.wait 100
;.wait 300
.message	140	yuk-700_01-0005	#�D�@�q	�������������������ء���Ұ����������æ���������ǿ����ء�\v\a
:.wait 300
.transition 0 * 20
.stage	vista_window2.png ev00_015a02.png 0 0
;�������Ǳ���䤨�Ƥ�������ע�⤷�ƣ�
.message	150	yuk-700_01-0007	#�D�@�q	����Ȼ2���˺��ƶ������࣬���ǡ�����\v\a
:.wait 300
;��Ц�
.transition 0 * 20
.stage	vista_window2.png ev00_015a03.png 0 0
;���ե��`�ɥ��ԩ`�ɉ䤨�Ƥޤ���
.message	160	yuk-700_01-0009	#�D�@�q	��ȴ�����ų�ʵ�ı��项\v\a
:.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_014a02.png 0 0
.message	170	him-700_01-0005	#�@�[�@	��������Ҳ�ܸ��˰���\v\a
:.wait 100
;.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_012a02.png 0 0
;��ev00_013�ΣãǤǣ���
.message	180	yuk-700_01-0011	#�D�@�q	���������������𣿡�\v\a
:.wait 200
.panel 3
.message	190			���ӺǺǵ�Ц������\a
.wait 200
.message	200			������ߵ��˵ĳɳ���ֵ�������¡�\a
.wait 240
.message	210			��㣬���ڵ���Ҳʮ�������\a
.wait 230
.panel 3
.message	220	him-700_01-0007	#�@�[�@	�����һ���ػ���Ӧ�ú�����ɣ���\v\a
:.wait 300
;��΢Ц
.transition 0 * 20
.stage	vista_window2.png ev00_013a02.png 0 0
.message	230	yuk-700_01-0013	#�D�@�q	���Ҷ�����ʲô��û��Ŷ��\v\a
.wait 100
:.wait 300
.message	240	yuk-700_01-0015	#�D�@�q	����ҡ����������Լ����뷨ѡ��ǰ���ĵ�·��Ȼ��õ�����컶Ц��ÿһ�ա�\v\a
:.wait 300
.transition 0 * 20
.stage	vista_window2.png ev00_013a04.png 0 0
.message	250	yuk-700_01-0017	#�D�@�q	���Ӵ�֮���ܲ��ܼ���Ц������ȥҪ����Щ�������Լ��ء�\v\a
:.wait 300
.panel 3
.message	260			����������������Ů�ǵĹ��¡�\a
.wait 220
.message	270			���Եĸ��齻���ںϣ�Ȼ�󩤩�\a
.wait 240
.panel 3
.message	280	him-700_01-0009	#�@�[�@	���ǰ���\v\a
:.wait 100
;.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_013a01.png 0 0
;�����Ӥα��飬ע�⤷�ơ��ե��`�ɥ��ԩ`�ɉ䤨�Ƥޤ���
.message	290	yuk-700_01-0019	#�D�@�q	��������\v\a
:.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_014a03.png 0 0
;��Ϧ�α��飬ע�⤷�ƣ�
.message	300	him-700_01-0011	#�@�[�@	�����������ڣ����ǲŻ�Ц�����ڡ�������ô��ġ�\v\a
:.wait 300
;����Ц
.message	310	yuk-700_01-0021	#�D�@�q	����ô���ܣ���û����ô�������Ŷ��\v\a
:.wait 300
.message	320	yuk-700_01-0023	#�D�@�q	��Ϧ�����ǵģ�̫�������������������뿪ʼ����Ŷ����\v\a
:.wait 300
.transition 0 * 40
.stage	vista_window2.png ev00_014a02.png 0 0
;��Ϧ�α��飬ע�⤷�ơ�a04��֤�ʹ�����Ȥ⿼�]�����ơ��ե��`�ɥ��ԩ`�ɤˤ�ע�⤷�Ƥ���������
.message	330	him-700_01-0013	#�@�[�@	���ٹ�������\v\a
:.wait 200
.panel 3
.message	340			��Ц��ҡҡͷ��\a
.wait 220
.panel 3
.message	350	him-700_01-0015	#�@�[�@	����ֻ���������ŵ���������ѡ�\v\a
:.wait 200
.message	360	him-700_01-0017	#�@�[�@	��˵����������Ұ����������\v\a
:.wait 300
.panel 3
.message	370			������ʲô��ϡ�ٵ����ϡ�\a
.wait 240
.message	380			��������ȴȷ���ǽ�����ߡ�\a
.wait 230
.message	390			����Ǹ�������Ұ�����ꡭ����\a
.wait 250
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_014a01.png 0 0
.panel 3
.message	400	him-700_01-0019	#�@�[�@	�����ӡ��㲻�ǵ����𣿡�\v\a
.wait 100
:.wait 300
.message	410	yuk-700_01-0025	#�D�@�q	��������ָʲô����\v\a
:.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_014a05.png 0 0
.message	420	him-700_01-0021	#�@�[�@	��û������\v\a
:.wait 200
.transition 0 * 20
.stage	vista_window2.png ev00_014a03.png 0 0
.message	430	him-700_01-0023	#�@�[�@	���������پ���Ů���ӵ������أ���\v\a
:.wait 300
.panel 3
.message	440			���Ӱ�ͷ����һ�ߡ�\a
.wait 210
.panel 3
.message	450	yuk-700_01-0027	#�D�@�q	���ѵ�˵�������˺���ǰ������ʲô��ϵ�𡭡���\v\a
:.wait 300
.transition 0 * 20
.stage	vista_window2.png ev00_014a05.png 0 0
;�������α���仯��ע�⤷�ƣ�
.message	460	him-700_01-0025	#�@�[�@	�������������ˡ�\v\a
:.wait 200
.panel 3
.message	470			����������Щ��֣���Ȼû��\a
.wait 250
;���Ť���
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_014_mugai_b.png 0 0
;������餬�·��ˤ����ꤹ���Ƥ��`�͸Ф�������Ϥϣ��ȥ뤳�ȡ��⤷���τe���Ф�����ǣ���
.panel 3
.message	480	yuk-700_01-0029	#�D�@�q	���Բ����ء�\v\a
.wait 100
:.wait 200
.message	490	yuk-700_01-0031	#�D�@�q	�����أ�����ʧȥ�˸��ָ����Ķ��������ӡ�����\v\a
:.wait 300
.panel 3
.message	500			��Ȼ�����\a
.wait 240
.message	510			�����ҵ�����˵��������ġ�\a
.wait 250
.message	520			����������ˡ�\a
.wait 200
.message	530			�������Ҳ����ν��\a
.wait 250
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_014a02.png 0 0
;��Ϧ������Ф�������饤�󤹤룿����ǴΤˤ��λ���ˤߤ����ʣ�
.panel 3
.message	540	him-700_01-0027	#�@�[�@	�����ӣ�����������Щ�𣿡�\v\a
:.wait 300
.message	550	yuk-700_01-0033	#�D�@�q	��������\v\a
:.wait 200
.message	560	him-700_01-0029	#�@�[�@	���ղŵĹ��µĺ�������\v\a
:.wait 200
.message	570	him-700_01-0031	#�@�[�@	�����1��ǰ�Ĺ���û��ɡ������Ժ󵽽��첻����ʲô��û������\v\a
:.wait 300
.panel 3
.message	580			�ţ�����Ľ���������һ�о����սᡣ\a
.wait 240
.panel 3
.message	590	him-700_01-0033	#�@�[�@	����ЩС��Ĺ��£�Ӧ�ò�ֻһ���ɣ���\v\a
:.wait 300
.panel 3
.message	600			�����ǹ�����δ����������������ס�\a
;.message	600			�����ޤ��K���ǤϤʤ����Ȥ򣬰��Ϥ狼�äƤ��롣
.wait 220
.panel 0
.transition 0 * 20
.stage	vista_window2.png ev00_015_mugai_a.png 0 0
.panel 3
.message	610	yuk-700_01-0035	#�D�@�q	���ǰ�������\v\a
.wait 100
.panel 3
.message	620			������͵ĸ���΢Ц��������˵�ͷ��\a
.wait 220
.panel 3
.message	630	yuk-700_01-0037	#�D�@�q	��������ת���������쩤����һ��������\v\a
:.wait 300
.wait 30
.message	640	yuk-700_01-0039	#�D�@�q	�������￪ʼ������һ���µĹ��¿�ʼ�ˡ�����\v\a
:.wait 300
.panel 3
;���������Ф�����򣿣�
.message	650			�����������Ҷ���Щ�ɡ�\a
.wait 270
.transition 0 * 20
.stage	vista_window2.png ev00_015a03_mugai_c.png 0 0
;��Ц�ʹ�äƤޤ�����Ŀ�Ĥ��Ǥ⤤���Τ��⤷��ޤ��󡣥ϥåԩ`����ɤ��ڴ������뤿��ˣ�Цˤ��Ƥ��ޤ���
.message	660			�����ڵ������йص����ǵĹ��£�����Ļ��\a
.wait 260
.message	670			��Щ�õ��Ҹ������ǵģ���һ�����©���\a
.wait 280
.panel 0
.transition 0 * 10
.stage	vista_window2.png WHITE.png 0 0
.wait 100
.playBGM *
.transition 0 * 10
.stage	* WHITE.png 0 0



;����Ӱ�����å�
;������Ļ�g�����i�����ե饰��
;��----------------------------------------------
.setGlobal ef_700 = 1
;��----------------------------------------------



;����Ӱ�����å�
;�������`�����Є���
.pragma enable_control



.chain 200_01.sc
;��200_01�ء�
;.end
