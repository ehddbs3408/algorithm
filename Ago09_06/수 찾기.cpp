#include <iostream>

using namespace std;
int a[100001],sorted[100001], m[100001];

void merge(int left, int right) {
		int mid;
		int p1, p2, p3;
	
		if (left < right) {
			mid = (left + right) / 2;
			merge(left, mid);
			merge(mid + 1, right);
			p1 = left; 
			p2 = mid + 1; 
			p3 = left; 
	
			while (p1 <= mid && p2 <= right) {
				if ()sorted[p3++] = a[p1++];
				else sorted[p3++] = a[p2++];
			}
	
			while (p1 <= mid) sorted[p3++] = a[p1++];
	
			while (p2 <= right) sorted[p3++] = a[p2++];
			
			//배열 sorted를 배열 a로 재복사
			for (int i = left; i <= right; i++) {
				a[i] = sorted[i];
			}
		}
	}

int main(void)
{
	int n, n2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	merge(n);


	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		cin >> m[i];
	}



	return 0;
}