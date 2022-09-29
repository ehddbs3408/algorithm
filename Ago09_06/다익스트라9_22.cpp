#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_VTXS 256
#define INF = 9999;

int V, E, start, u, v, w;
vector<pair<int, int>> weight[20001];
//priority_queue<pair<int,int>> , vector<pair<int,int>> ,


class AdjMatGraph
{
protected:
	int size;
	char vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];
public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }
	void reset()
	{
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
		{
			for (int j = 0; j < MAX_VTXS; j++)
			{
				setEdge(i, j, 0);
			}
		}
	}
	void insertVertex(char name)
	{
		vertices[size] = name;
		size++;
	}
	void insertEdge(int i, int j)
	{
		setEdge(i, j, 1);
		setEdge(j, i, 1);
	}
	void display()
	{
		cout << "정점의 개수 : " << size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << getVertex(i) << " ";
			for (int j = 0; j < size; j++)
			{
				cout << getEdge(i, j) << " ";
			}
			cout << endl;
		}
	}
};
class SearchGraph : public AdjMatGraph
{
	int visited[MAX_VTXS];
public:
	void resetVisited()
	{
		for (int i = 0; i < size; i++)
		{
			visited[i] = 0;
		}
	}

	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	void DFS(int v)
	{
		visited[v] = 1;
		cout << getVertex(v) << " ";
		for (int i = 0; i < size; i++)
			if (isLinked(v, i) && visited[i] == 0)
			{
				DFS(i);
			}

	}
	void BFS(int v)
	{
		fill_n(visited, MAX_VTXS, -1);
		visited[v] = 0;
		queue<char> q;
		q.push(v);
		while (!q.empty())
		{
			int i = q.front();
			cout << getVertex(i) << " ";
			q.pop();
			for (int j = 0; j < size; j++)
			{
				if (isLinked(i, j) && visited[j] < 0)
				{
					visited[j] = visited[i] + 1;
					q.push(j);
				}
			}
		}
		cout << endl << "A에서 각 정점까지의 거리 : ";
		for (int i = 0; i < size; i++)
		{
			cout << " " << visited[i];

		}
	}
};
class shotestPath : public AdjMatGraph
{
	int dist[MAX_VTXS];
	int parent[MAX_VTXS];
	bool found[MAX_VTXS];
public:
	void printDistance()
	{
		for (int i = 0; i < size; i++)
		{
			cout << dist[i] << " ";
		}
		cout << endl;
	}
	int chooseVertex()
	{
		int min = 9999;
		int minpos = -1;
		for (int i = 0; i < size; i++)
		{
			if (!found[i]&& min>dist[i])
			{
				min = dist[i];
				minpos = i;
			}
		}
		return minpos;
	}
	void dijikstra(int start,int end)
	{
		for (int i = 0; i < size; i++)
		{
			dist[i] = getEdge(start, i);
			found[i] = false;
		}
		fill_n(parent, size, -1);
		found[start] = true;
		dist[start] = 0;
		parent[start] = start;
		int next, current = start;
		cout << "정점에서 시작?!!" << endl;
		for (int i = 0; i < size; i++)
		{
			if (current == end)
			{
				cout << "목적 정점 " << end << "에 도착" << endl;
				break;
			}
			cout << "Step " << i + 1 << " : ";
			printDistance();
			next = chooseVertex();
			found[next] = true;
			for (int w = 0; w < size; w++)
			{
				if (found[w] == false)
				{
					if (dist[next] + getEdge(next, w) < dist[w])
					{
						dist[w] = dist[next] + getEdge(next, w);
						parent[w] = next;
					}
				}
					
			}
			current = next;
		}
	}
};
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


}