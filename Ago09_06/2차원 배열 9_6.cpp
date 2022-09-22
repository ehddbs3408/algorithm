#include <iostream>
#include <vector>
using namespace std;
#define MAX_VTXS 256

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
	void insertEdge(int i,int j)
	{
		setEdge(i, j, 1);
		setEdge(j,i, 1);
	}
	void display()
	{
		cout << "정점의 개수 : " << size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << getVertex(i) << " ";
			for (int j = 0; j < size; j++)
			{
				cout<<getEdge(i, j) << " ";
			}
			cout << endl;
		}
	}
};
int main(void)
{
	AdjMatGraph p;

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
}