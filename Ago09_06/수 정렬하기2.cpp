#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

queue<int> a[10];
int num[100000];
void gisu(int n)
{
	int big = 0;
	for (int i = 0; i < n; i++)
	{
		if (big < num[i])
		{
			big = num[i];
		}
	}
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		if (big > 0)
		{
			big = big / 10;
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		for (int j = 1; j < n;j++)
		{
		
		}
	}
}
int main(void)
{

}