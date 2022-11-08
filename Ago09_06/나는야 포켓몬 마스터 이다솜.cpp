#include <iostream>
#include <map>


using namespace std;
int main(void)
{
	int m, n;
	string name;
	map<string, int> map;

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> name;
		map.insert({ name , i + 1 });
	}

	string serch;
	std::map<string, int>::iterator iter;
	for (int i = 0; i < n; i++)
	{
		cin >> serch;
		//if(isdigit((int)serch) == 4)
	}
}