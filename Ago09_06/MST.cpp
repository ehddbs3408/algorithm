#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent[1001];
int unf[1001];
struct Edge
{
	int s, e, val;
	Edge(int a, int b, int c)
	{
		s = a;
		e = b;
		val = c;
	}
	bool operator<(const Edge& b) const {
		return val < b.val;
	}
};

int Find(int v)
{
	if (v == parent[v]) return v;
	return Find(parent[v]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b) parent[a] = b;
}
int main(void)
{
	vector<Edge> Ed;

	int i, n, m, a, b, c, cnt = 0, res = 0;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		Ed.push_back(Edge(a, b, c));
	}

	sort(Ed.begin(), Ed.end());
	
	for (i = 0; i < m; i++)
	{
		int fa = Find(Ed[i].s);
		int fb = Find(Ed[i].e);
		if (fa != fb)
		{
			res += Ed[i].val;
			Union(fa, fb);
		}
	}

	cout << res;
	return 0;
}