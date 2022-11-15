#include <iostream>	
#include <set>

using namespace std;

int main(void)
{
	int n;
	set<int> set;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		set.insert(val);
	}
	
	std::set<int>::iterator iter;
	int max=0, min=999999999;
	for (iter = set.begin(); iter != set.end(); iter++)
	{
		if (max < *iter)
			max = *iter;
		if (min > *iter)
			min = *iter;
	}

	cout << max - min;
}
