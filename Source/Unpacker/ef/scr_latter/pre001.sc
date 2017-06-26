
.setGlobal EYE_SEQ_DEFAULT = 2


.pragma enable_control

.transition 0 * 10
.stage	* BLACK.png 0 0



.if pre001 == 1 ef_000_b1
.if pre001 <= 0 ef_000_a1

.label ef_000_a1

.movie2 latter_intro.avi 800 600 latter_intro.ogg 44100 2 f

.pragma disable_control

.goto ef_000_c1
.end


.label ef_000_b1

.movie2 latter_intro.avi 800 600 latter_intro.ogg 44100 2 t

.goto ef_000_c1
.end
.label ef_000_c1





.transition 0 * 10
.stage	* BLACK.png 0 0

.transition 0 * 10

.panel 3
.stage	vista_window2.png ev00_013a02_WB.png 0 0
.message	130	yuk-701_01-0007	�D�@�q	����ʵ�أ����������һ��ȥ���ء�\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_013a04_WB.png 0 0
.message	140	yuk-701_01-0009	�D�@�q	��������ֳ��������˵ļ���֮�����ء�\v\a
.wait 50
.transition 0 * 20
.stage	vista_window2.png ev00_014a02_mugai_a_WB.png 0 0
.message	170	him-701_01-0003	�@�[�@	�������\v\a
.transition 0 * 30
.stage	vista_window2.png ev00_014a04_mugai_a_WB.png 0 0
.message	180	him-701_01-0005	�@�[�@	��������Ҫһ���棬Ҳ���ܺ���������һ�𰡡�\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_013a03_WB.png 0 0
.message	190	yuk-701_01-0011	�D�@�q	���ߡ�\v\a
.message	200	yuk-701_01-0013	�D�@�q	��������أ��һ����е�Ŷ��\v\a
.wait 20
.message	230	him-701_01-0007	�@�[�@	����Ǹ��˵Ц������������⡹\v\a
.message	240	yuk-701_01-0015	�D�@�q	�������������ŵ����ء�����\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_014a01_mugai_a_WB.png 0 0
.message	250	him-701_01-0009	�@�[�@	��Ȼ��������������Ĺ��𣿡�\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_013a03_WB.png 0 0
.message	260	yuk-701_01-0017	�D�@�q	�������ڻ�ˮ����Ŷ��������������ŵ����ء�����\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_013a02_WB.png 0 0
.message	280	yuk-701_01-0019	�D�@�q	���͹�������һ��Ŷ��\v\a
.message	290	yuk-701_01-0021	�D�@�q	���Ѿ������ټ�������С��͵��������ء�\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_014a05_mugai_a_WB.png 0 0
.message	300	him-701_01-0011	�@�[�@	�����𡭡���\v\a
.wait 30
.transition 0 * 20
.stage	vista_window2.png ev00_013a01_WB.png 0 0
.message	310	yuk-701_01-0023	�D�@�q	�����ǣ�����Ҳ�ܺ��ء�\v\a
.message	320	yuk-701_01-0025	�D�@�q	����Ϊ��Щ�����Ƕ��Ѿ��������Լ��Ľ��߳�ȥ���ء�\v\a
.message	330	him-701_01-0013	�@�[�@	������������\v\a
.wait 150

.transition 0 * 20
.stage	vista_window2.png ev00_014a01_WB.png 0 0
.message	360	him-701_01-0015	�@�[�@	�������������ֵ��������ء�\v\a
.message	370	yuk-701_01-0027	�D�@�q	���ҡ�������\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_014a03_WB.png 0 0
.message	380	him-701_01-0017	�@�[�@	���ǵġ�\v\a
.message	390	him-701_01-0019	�@�[�@	����Ϊ�㣬��ʧȥ�Ķ�����\v\a
.wait 50
.message	400	yuk-701_01-0029	�D�@�q	�������ǵġ�\v\a
.wait 100
.message	420	yuk-701_01-0031	�D�@�q	������Ҫ�Ķ������Ѿ����Ҷ�ȥ��\v\a
.wait 100
.message	430	yuk-701_01-0033	�D�@�q	���������µģ�ֻ��Щ��ļ����Ƭ������\v\a
.wait 50
.message	440	him-701_01-0021	�@�[�@	���������ԡ�\v\a
.wait 130
.message	480	him-701_01-0023	�@�[�@	����ʧ�Ķ�������ȡ�����ͺá�\v\a
.wait 100
.message	490	him-701_01-0025	�@�[�@	���һ�Ϊ��ȡ������\v\a

.transition 0 * 20
.stage	vista_window2.png ev00_013a01_WB.png 0 0

.message	500	yuk-701_01-0035	�D�@�q	�����������ӣ��㻹����ôǿӲ��Ƣ���ء�\v\a
.message	510	him-701_01-0027	�@�[�@	����Ҳ���뿴���������Ұɣ���\v\a
.wait 80
.message	520	yuk-701_01-0037	�D�@�q	���㵽����Ϊֹһֱ��û�ж�ʧ����Ƿݼ�ǿ�ء�\v\a
.wait 80

.transition 0 * 20
.stage	vista_window2.png ev00_013a04_WB.png 0 0

.message	530	yuk-701_01-0039	�D�@�q	����Ȼ�����㽵ģ���ǿ������Ļ��Ϧ��������\v\a
.wait 150

.transition 0 * 20
.stage	vista_window2.png ev00_012a01_WB.png 0 0

.message	540	yuk-701_01-0041	�D�@�q	������ȴ��һ����\v\a
.message	550	him-701_01-0029	�@�[�@	��û�в�һ����\v\a
.message	560	yuk-701_01-0043	�D�@�q	���ǲ�һ���İ������Ѿ����ˡ�����\v\a



.playBGM efBGM053mix.ogg * * 100
.panel 0

.transition 0 * 200
.stage	vista_window2.png WHITE.png 0 0
.wait 100
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_a.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_b.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_c.png 0 0
.wait 80
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_d.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_e.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_p3.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_k.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_g.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_b2.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_c2.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_d2.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_m2.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_n2.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_r2.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_s2.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_a3.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_b3.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_f3.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_g3.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_k3.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_l3.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_q3.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_r3.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_u3.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_v3.png 0 0
.transition 0 * 210
.stage	vista_window2.png vista_mugai_omake_z3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_w2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_f.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_a4.png 0 0
.wait 140
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_n3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_h.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_i.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_j.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_l.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_m.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_n.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_o.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_p.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_q.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_r.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_s.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_t.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_u.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_v.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_w.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_x.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_z.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_e2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_f2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_g2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_h2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_i2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_j2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_k2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_l2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_o2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_p2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_q2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_t2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_u2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_v2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_x2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_y2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_z2.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_c3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_d3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_e3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_h3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_i3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_j3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_m3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_y.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_s3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_t3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_w3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_x3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_y3.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_b4b.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_c4.png 0 0
.transition 0 * 200
.stage	vista_window2.png vista_mugai_omake_o3.png 0 0
.transition 0 * 5
.stage	vista_window2.png ev00_012a01_WB.png 0 0
.transition 0 * 5
.stage	vista_window2.png ev00_012a01.png 0 0
.transition 0 * 3
.stage	vista_window2.png title_latter_mikage.png 0 0

.playBGM *
.wait 30
.wait 200
.panel 3
.message	570	him-701_01-0031	�@�[�@	��������㡣���ٶ�����˵��������\v\a
.wait 300





.playBGM efBGM016.ogg
.transition 0 * 3
.stage	vista_window2.png ev00_012a01.png 0 0
.panel 3
.message	600	yuk-701_01-0045	�D�@�q	����Ȼ�㻹������Ĺ����ء�����\v\a
.wait 300

.panel 3
.message	650	yuk-701_01-0047	�D�@�q	���ᣱ����������𣿡�\v\a
.message	660	him-701_01-0033	�@�[�@	��ʲô����\v\a
.wait 80
.message	670	yuk-701_01-0049	�D�@�q	����Ҳ��֪���ء�\v\a
.message	680	him-701_01-0035	�@�[�@	����֪������\v\a
.message	690	yuk-701_01-0051	�D�@�q	��������֪������Ĺ��¡������������ɡ�\v\a
.wait 140
.message	730	him-701_01-0037	�@�[�@	��������Ҳû����ʲô�˲�������顣��������ƽ����ÿһ����ˡ�\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_015a01.png 0 0
.message	740	yuk-701_01-0053	�D�@�q	��Ϧ������ƽ���ġ�������\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_015a03.png 0 0
.message	750	yuk-701_01-0055	�D�@�q	���ܾ���ʮ�ֿ����ء�\v\a




.transition 0 * 20
.stage	vista_window2.png ev00_014a03.png 0 0
.message	780	him-701_01-0041	�@�[�@	�����Լ����������Ҳ�˵��\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_014a01.png 0 0
.message	790	him-701_01-0043	�@�[�@	���������������ŵ������ġ�\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_013a01.png 0 0
.message	800	yuk-701_01-0057	�D�@�q	������������˭�أ���\v\a
.message	810	him-701_01-0045	�@�[�@	��Ҫ˵����Ļ��Ͳ��ò���΢��ʱ�������ء�\v\a
.message	820	him-701_01-0047	�@�[�@	���������Һ���Ĺ�ȥҲ�й��������项\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_013a03.png 0 0
.message	830	yuk-701_01-0059	�D�@�q	�����ǵġ�������\v\a
.message	840	him-701_01-0049	�@�[�@	���ǵġ�\v\a
.wait 30
.message	850	him-701_01-0051	�@�[�@	���������ڴ�֮ǰ����˵һ���Ǹ����ӿɲ��С�\v\a
.message	860	yuk-701_01-0061	�D�@�q	���Ǹ����ӣ���\v\a
.wait 100
.message	870	yuk-701_01-0063	�D�@�q	���Ǹ����ӣ���Ů�����ǰɣ���\v\a
.message	880	him-701_01-0053	�@�[�@	������ֵĵط��ر��������㡹\v\a
.message	890	yuk-701_01-0065	�D�@�q	����Ϊ��Ҳ��Ů���ӵ�˵��\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_014a01.png 0 0
.message	910	him-701_01-0055	�@�[�@	������������ɡ�ֻ����������\v\a
.wait 60
.transition 0 * 20
.stage	vista_window2.png ev00_014a03_mugai_a.png 0 0
.message	920	him-701_01-0057	�@�[�@	����˵˵�Ǹ����ӵĻ����Ҿ�˵�����ҵ��������������ˡ�\v\a
.wait 130
.panel 3
.message	960	him-701_01-0059	�@�[�@	����Ϊ�����ҲŻ�֪�����������ﲻͣ�ĵȴ���\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_014_mugai_b.png 0 0
.message	970	yuk-701_01-0067	�D�@�q	��Ϧ�����Ǹ����������֪�����ҵ����飿��\v\a
.message	980	him-701_01-0061	�@�[�@	���ǵġ���Ȼ������ֱ�ӵ�֪���������٣�������ǣ�ߴ��ŵ����á�\v\a
.wait 100
.message	990	him-701_01-0063	�@�[�@	��Ȼ���Ǻ�����˵�Ĺ���Ҳ����Ī��Ĺ�ϵ��\v\a
.wait 40
.message	1000	yuk-701_01-0069	�D�@�q	�������Ǹ����ӣ���˭�أ���\v\a
.message	1010	him-701_01-0065	�@�[�@	�����������ǣ�����ǧѰ��\v\a
.transition 0 * 20
.stage	vista_window2.png ev00_013a03.png 0 0
.message	1020	yuk-701_01-0071	�D�@�q	�����١�������\v\a
.wait 100
.transition 0 * 20
.stage	vista_window2.png ev00_014a03.png 0 0
.message	1030	him-701_01-0067	�@�[�@	��������\v\a
.wait 150

.transition 0 * 20
.stage	vista_window2.png ev00_014a01_mugai_a.png 0 0
.message	1070	him-701_01-0069	�@�[�@	����ô��������˵����ء�����\v\a
.panel 0
.transition 0 * 10
.stage	vista_window2.png WHITE.png 0 0
.wait 100
.playBGM *
.transition 0 * 10
.stage	* WHITE.png 0 0


.setGlobal pre001 = 1

.pragma enable_control


.chain 300_01.sc
