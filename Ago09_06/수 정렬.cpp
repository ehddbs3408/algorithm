#include <iostream>

using namespace std;

int main(void)
{
	int n, temp;
	int a[1001];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int idx = 0;
	for (int i = 0; i < n - 1; i++)
	{
		idx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[idx] > a[j])
			{
				idx = j;
			}
		}
		temp = a[i];
		a[i] = a[idx];
		a[idx] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}