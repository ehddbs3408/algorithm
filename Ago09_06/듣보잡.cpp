#include <iostream>
#include <set>

using namespace std;
int main(void)
{
	int n, m;
	set<string> set;
	std::set<string>::iterator iter;
	string a;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		set.insert(a);
	}
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		iter = set.find(a);
		if (iter != set.end())
		{
			count++;
		}
	}

	cout << count;
	
	


}