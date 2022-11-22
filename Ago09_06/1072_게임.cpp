#include <iostream>
using namespace std;

int main(void)
{
	long long a,b;
	float x, y;
	cin >> x >> y;
	if (x == y)
	{
		cout << -1;
		return 0;
	}

	long long left = 0, right = 1000000 , mid = 0;
	int ans = 0;
	while (left <= right)
	{
		mid = (right + left) * 0.5f;
		a = (y) * 100.f / (x);
		b = (y + mid) * 100.f / (x + mid);
		cout << left << "   " << mid << "  " << right << endl;	
		if (a < b)
		{
			right = mid - 1;
			ans = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << ans;
}