// float.cpp : Defines the entry point for the console application.
//
#include <windows.h>
#include <stdio.h>
#include <math.h>
���ں�����Ϊmath.h��stdlib.h��string.h��float.h
int      abs(int i)                                      �������Ͳ���i�ľ���ֵ
double cabs(struct complex znum)        ���ظ���znum�ľ���ֵ
double fabs(double x)                           ����˫���Ȳ���x�ľ���ֵ
long    labs(long n)                                 ���س����Ͳ���n�ľ���ֵ
double   exp(double x)                             ����ָ������ex��ֵ
double frexp(double value,int *eptr)       ����value=x*2n��x��ֵ,n������eptr��
double ldexp(double value,int exp);        ����value*2exp��ֵ
double   log(double x)                             ����logex��ֵ
double log10(double x)                           ����log10x��ֵ
double   pow(double x,double y)             ����xy��ֵ
double pow10(int p)                                ����10p��ֵ
double sqrt(double x)                             ����+��x��ֵ
double acos(double x)                 ����x�ķ�����cos-1(x)ֵ,xΪ����
double asin(double x)                 ����x�ķ�����sin-1(x)ֵ,xΪ����
double atan(double x)                 ����x�ķ�����tan-1(x)ֵ,xΪ����
double atan2(double y,double x)        ����y/x�ķ�����tan-1(x)ֵ,y��xΪ����
double   cos(double x)                 ����x������cos(x)ֵ,xΪ����
double   sin(double x)                 ����x������sin(x)ֵ,xΪ����
double   tan(double x)                 ����x������tan(x)ֵ,xΪ����
double cosh(double x)                 ����x��˫������cosh(x)ֵ,xΪ����
double sinh(double x)                 ����x��˫������sinh(x)ֵ,xΪ����
double tanh(double x)                 ����x��˫������tanh(x)ֵ,xΪ����
double hypot(double x,double y)        ����ֱ��������б�ߵĳ���(z),
                                       x��yΪֱ�Ǳߵĳ���,z2=x2+y2
double ceil(double x)                 ���ز�С��x����С����
double floor(double x)                 ���ز�����x���������
void   srand(unsigned seed)            ��ʼ�������������
int     rand()                         ����һ������������������
double poly(double x,int n,double c[])�Ӳ�������һ������ʽ
double modf(double value,double *iptr)��˫������value�ֽ��β���ͽ�
double fmod(double x,double y)        ����x/y������
double frexp(double value,int *eptr)   ��˫������value�ֳ�β���ͽ�
double atof(char *nptr)               ���ַ���nptrת���ɸ��������������������
double atoi(char *nptr)               ���ַ���nptrת���������������������
double atol(char *nptr)               ���ַ���nptrת���ɳ������������������
char   *ecvt(double value,int ndigit,int *decpt,int *sign)
         ��������valueת�����ַ��������ظ��ַ���
char   *fcvt(double value,int ndigit,int *decpt,int *sign)
         ��������valueת�����ַ��������ظ��ַ���
char   *gcvt(double value,int ndigit,char *buf)
         ����valueת�����ַ���������buf��,������buf��ָ��
char *ultoa(unsigned long value,char *string,int radix)
         ���޷���������valueת�����ַ��������ظ��ַ���,radixΪת��ʱ���û���
char   *ltoa(long value,char *string,int radix)
         ����������valueת�����ַ��������ظ��ַ���,radixΪת��ʱ���û���
char   *itoa(int value,char *string,int radix)
         ������valueת�����ַ�������string,radixΪת��ʱ���û���
double atof(char *nptr) ���ַ���nptrת����˫������,�����������,���󷵻�0
int    atoi(char *nptr) ���ַ���nptrת����������, �����������,���󷵻�0
long   atol(char *nptr) ���ַ���nptrת���ɳ�������,�����������,���󷵻�0
double strtod(char *str,char **endptr)���ַ���strת����˫������,�����������,
long   strtol(char *str,char **endptr,int base)���ַ���strת���ɳ�������,
                                               �����������,
int          matherr(struct exception *e)
              �û��޸���ѧ���󷵻���Ϣ����(û�б�Ҫʹ��)
double       _matherr(_mexcep why,char *fun,double *arg1p,
                      double *arg2p,double retval)
                �û��޸���ѧ���󷵻���Ϣ����(û�б�Ҫʹ��)
unsigned int _clear87()   �������״̬�ֲ�����ԭ���ĸ���״̬
void         _fpreset()   ���³�ʹ��������ѧ�����
unsigned int _status87() ���ظ���״̬��
int main(int argc, char* argv[])
{
	double b;

	b = argc;
	if (b <= 0)
		printf("Hello World! %f %f\n", sqrt(b));
	return 0;
}

