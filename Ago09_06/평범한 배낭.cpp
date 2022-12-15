#include <iostream>
#include <algorithm>
using namespace std;
int DP[101][100001];
int w[101];
int v[101];

int main(void)
{
	ios_base::sync_with_stdio(0);

	cin.tie();
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (w[i] > j)
			{
				DP[i][j] = DP[i - 1][j];
			}
			else
			{
				
			}
		}
	}

	cout << DP[n][k];

}