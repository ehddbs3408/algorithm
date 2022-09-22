#include <iostream>
using namespace std;

const int MAX = 50;
int width, height, a[MAX][MAX], visited[MAX][MAX], cnt;
int testCase;

void DFS(int x, int y)
{
	if (a[x][y] == 0 || visited[x][y] == 1)
		return;

	visited[x][y] = 1;
	if(x+1< width)
		DFS(x + 1, y);
	if(x-1 > 0)
		DFS(x - 1, y);
	if (y + 1 < height)
		DFS(x, y+1);
	if (y - 1 > 0)
		DFS(x, y -1);
}
int main(void)
{
	int result = 0;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		//초기화
		result = 0;
		for (int j = 0; j < MAX * MAX; j++)
		{
			int x = j % MAX, y = j / MAX;

			a[x][y] = 0;
			visited[x][y] = 0;
		}

		//}
		//입력
		cin >> width >> height >> cnt;
		//if (width > 50 || height > 50||cnt>2500)
		//{
		//	return 0;
		//}

		//배추 입력
		for (int j = 0; j < cnt; j++)
		{
			int x, y;
			cin >> x >> y;
			a[x][y] = 1;
		}

		//계산
		for (int j = 0; j < width * height; j++)
		{
			
			int x = j % width, y = j / width;
			if (x < 0 || y < 0) continue;
			if (a[x][y] == 0 || visited[x][y] == 1) continue;

			result++;
			DFS(x, y);
		}
		cout << result << endl;

		for (int j = 0; j < width * height; j++)
		{
			int x = j % width, y = j / width;
			if (x == 0)
				cout << endl;
			cout << visited[x][y] << " ";
		}
		cout << endl;
		for (int j = 0; j < width * height; j++)
		{
			int x = j % width, y = j / width;
			if (x == 0)
				cout << endl;
			cout << a[x][y] << " ";
		}
		cout << endl;
	}
	return 0;
}