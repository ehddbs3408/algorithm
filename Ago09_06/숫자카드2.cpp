#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int i, n, m, temp;

	vector<int> vec;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	cin >> m;

	for (i = 0; i < m; i++) {
		cin >> temp;
		cout << upper_bound(vec.begin(), vec.end(), temp) - lower_bound(vec.begin(), vec.end(), temp) << " ";
	}

}