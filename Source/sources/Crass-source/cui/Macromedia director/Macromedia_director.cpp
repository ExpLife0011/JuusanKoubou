/*
J:\(ͬ�˥��ե�) [�����󥻥��] [dxr]���~¶������BMŮ�{�̡�\���~¶������BMŮ�{�̡�
K:\(ͬ�˥��ե�) [�\������] Ů�̎�����������I��\Ů�̎�����������I��\dir
H:\tools\ency-0.8.6\ency-0.8.6\scan.c

1.���n��.cxt(���b���Y�ϙn)+.dxr(�����n)

���׽�˻`��"�������磳"�n���M��:

2.ʹ�õēܷ�������ʽ�n���YӍ���Կ��ĵ�"Macromedia Projector"�ִ��Ͱ汾̖

CTX��Macromedia Director�ܱ�����(���ɱ༭��)ͶӰ�ļ� 

dxr �� cxt�Ǳ�Director�����ĵ��������� dir �� cst ��������ת���ɱ�����״̬�ĵ�����Ҳ����ʹ�����޷����˱������ĵ��������޸ġ������౻�����ĵ�����ʽΪ dxr �� cxt�� 
����뽫�����ĵ�ת����������ʽ���ļ�����������Director����򿪣�Ȼ������������Ӧ���͵��ļ����ɣ��������һ������������˵��MP3���͵��ļ�������������WAV��������ʽ���ļ��������������Χ��MP3��ʽ�� 
�ο����ϣ�http://www.ourspc.com/bbs/dispbbs.asp?boardid=2&id=41

���Director������ 
    ������û���ʹ������Director�����ĳ����Ҫ��������һ�װ����Director��Ȼ�ǲ�����ģ�
	���Ҫ�����Ǳ���������õĶ�ý����������Ƴɿ���ֱ����Windows�����е�EXE�ļ��������û��Ϳ�������Director�༭����ʹ�á�
	�������е��ļ��������ͬһ��EXE�ļ�֮��������õ�ͬʱҲ�ǲ���ȡ����������Ϊ������ʹ�ļ����󣬳���װ���ڴ��ʱ�䣬
	���һЩЧ����ʧ����������������������ȣ������ǽ���������ǣ���������Ҳ���ǵ�һ��ִ�еĳ�����ΪEXE�ļ���
	Ҳ������ν�Ĺ����ļ�Projector����������Xtras�˵��е�Update Movies�����������dir�ļ����Ϊdxr�ļ���
	��External Cast��Ҳ����*.cst�ļ�����ͬ����������Ϊcxt�ļ���ʽ�������Ϳ���ʹ�ó���ִ�п�һЩ��ͬʱҲ�ɱ����Լ��ĳ���D�档

	dxr �����Ѿ����� ˭�ܸ�����cxt�ģ�
dxr �Ѿ����� ��������ǣ� �½�һ��movie �ٱ�дscript ����Ϊ
on outputdir input,output
window().new(input).open()
window(input).movie.saveMovie(output)
forget(window(input))
end 
��дmessageΪoutputdir"C:\Documents and Settings\MPC2006\����\unit2-1.dxr" "C:\Documents and Settings\MPC2006\����\abc.dir"�Ϳ��� �� ���Ǵ�cxt��������ô���� �����Ҳ�������ϲ�� cxt��script��message����ô����д�أ� save castlib���������ôд������ѧ�� ûѧ��lingo���� ��̣�������
*/

#include "stdafx.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

