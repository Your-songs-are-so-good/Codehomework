#include "Trapzint.h"
#include<cmath>

double MyFunction::operator () (double x)const
{
	//Ϊ�˷��������ֵ�и����ĵ����������fabs,������Ӻ�������ʽ
	return fabs(log(1.0 + x) / (1.0 + x * x));   
}



double Trapz::operator () (double a, double b, double eps) const
{
	bool done = false;
	int n = 1;
	double h = b - a;
	double tn = h * (f(a) + f(b)) / 2;
	double t2n;
	do
	{
		double sum = 0, smc = 0;
		for (int k = 0; k < n; k++)
		{
			double x = a + (k + 0.5) * h;
			sum += f(x);
		}
		t2n = (tn + h * sum) / 2.0;

		//��ֹ���ֱ߽����е�Ϊ��ȣ���Ϊ0�������,��߾���
		//***************************************
		/*for (int k = 0; k < (2*n); k++)
		{
			double x = a + (k + 0.5) * h / 2;
			smc += f(x);
		}
		double smck = (t2n + h * smc / 2) / 2.0;*/
		//***************************************
		//�����t2n�жϣ�ǰ�������ǻ��ִ��ڣ����������ѭ��
		if ( (fabs(t2n - tn) < eps) && t2n )
		{
			done = true;
		}
		else
		{
			tn = t2n;
			n *= 2;
			h /= 2;
		}

	} while (!done);
	return t2n;
}