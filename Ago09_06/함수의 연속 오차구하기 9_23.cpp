#include <iostream>
#include <math.h>
using namespace std;

double Func(double a)
{
	return pow(a,3) - ( 3 * a) + 1;
}
void Calculator(double a,double b)
{
	double left = Func(a), right = Func(b), mid = 0;
	 
	for (int i = 0; i < 20; i++)
	{
		if (left * right < 0)
		{
			
			mid = Func((left + right) / 2);

			if (left * mid < 0)
			{
				
				right = mid;
				continue;
			}
			if (right * mid < 0)
			{
				left = mid;
				continue;
			}
		}
	}
	//mid = Func((left + right) / 2);
	cout.precision(4);
	cout << "값 : " << mid << " 오차범위 : ±" << mid - left;
}
int main(void)
{
	double min, max;
	cin >> min >> max;
	Calculator(min, max);
}