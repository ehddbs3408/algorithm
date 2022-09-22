#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_VTXS 256
#define INF = 9999;

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
	void chooseVertex()
	{
		//int min = INF;
		//int minpos = -1;
		//for (int i = 0; i < size; i++)
		//{
		//	if ()
		//	{

		//	}
		//}
		//return minpos;
	}
};
int main(void)
{
	SearchGraph p;

	for (int i = 0; i < 4; i++)
	{
		p.insertVertex('A' + i);
	}
	p.insertEdge(0, 1);
	p.insertEdge(0, 3);
	p.insertEdge(1, 2);
	p.insertEdge(1, 3);
	p.insertEdge(2, 3);

	cout << "인접 행렬로 표현한 그래프" << endl;
	p.display();
	cout << "DFS 탐색 => ";
	p.resetVisited();
	p.DFS(0);
	cout << endl;
	cout << "BFS 탐색 => ";
	p.resetVisited();
	p.BFS(0);
}