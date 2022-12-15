#include <iostream>

using namespace std;
long long arr[101] = {0,1,1,1,2,0};
long long p(long long n)
{
	if (n < 0) return 0;

	if (arr[n] != 0)
	{
		return arr[n];
	}
	arr[n] = p(n - 1) + p(n - 5);
	return arr[n];
}
int main(void)
{
	int a;
	int ar[100];
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> ar[i];
	}

	for (int i = 0; i < a; i++)
	{
		cout << p(ar[i]) << endl;
	}
}