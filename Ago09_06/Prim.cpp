#include<iostream>
#include<algorithm>
#include<vector>
#include <queue>
using namespace std;
int ch[30];

struct Edge {
    int n;
    int val;
    Edge(int a, int c) {
        n = a;
        val = c;
    }
    bool operator<(const Edge& b) const {
        return val > b.val;
    }
};


int main() {
    priority_queue<Edge> Q;
    vector<pair<int, int>> node[30];
    int i, count_n, count_e, n1, n2, val, res = 0;
    cin >> count_n >> count_e;
    for (i = 1; i <= count_e; i++)
    {
        cin >> n1 >> n2 >> val;
        node[n1].push_back(make_pair(n2, val));
        node[n2].push_back(make_pair(n1, val));
    }
    Q.push(Edge(1, 0));

    while (!Q.empty())
    {
        Edge tmp = Q.top();
        int v = tmp.n;
        int cost = tmp.val;
        if (ch[v] == 0)
        {
            ch[v] = 1;
            res += cost;
            for (i = 0; i < node[v].size(); i++)
            {
                if (ch[node[v][i].first] == 0)
                {
                    Q.push(Edge(node[v][i].first, node[v][i].second));
                }
            }
        }
    }
    cout << res;
    return 0;
}