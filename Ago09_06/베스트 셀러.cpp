#include <iostream>
#include <map>


using namespace std;
int main(void)
{
	int n;
	string name;
	map<string, int> map;
	std::map<string, int>::iterator iter;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		if (map.find(name) == map.end())
		{
			map.insert({ name,1 });
		}
		else
		{
			map[name] += 1;
		}
	}
	int result = 0;
	string resultName;
	for (iter = map.begin(); iter != map.end() ;iter++)
	{
		if (iter->second > result)
		{
			result = iter->second;
			resultName = iter->first;
		}
		//cout << iter->first << "  " << iter->second << endl;
	}

	cout << resultName;
}