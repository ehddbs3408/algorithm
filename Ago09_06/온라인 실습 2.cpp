#include <iostream>	
#include <map>

using namespace std;

int main(void)
{
	string s;
	map<char, int> map;

	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (map.find(s[i]) != map.end())
			map[s[i]]++;
		else
			map.insert({s[i],1});
	}

	std::map<char, int>::iterator iter;
	std::map<char, int>::iterator iter2=map.begin();
	for (iter = map.begin(); iter != map.end(); iter++)
	{
		if (iter2->second < iter->second)
			iter2 = iter;
	}

	cout << iter2->first;

}