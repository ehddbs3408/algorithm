//#include<iostream>
//using namespace std;
//int a[100];
//void quickSort(int start, int end) {
//	if (start >= end) {	//원소가 1개인 경우 
//		return;
//	}
//	int key = start;	//키는 첫번째 원소
//	int left = start + 1;	//왼쪽 출발 지점 
//	int right = end;		//오른쪽 출발 지점 
//	int temp;
//
//	while (left < right) {	//엇갈릴 때까지 반복 
//		while (//) {	//키 값보다 큰 값을 만날 때까지 
//			left++;
//	}
//	while (//) {	//키 값보다 작은 값을 만날 때까지 
//		right--;
//}
//if (left >= right) {	//현재 엇갈린 상태면 키 값과 교체
//	temp = a[right];
//	a[right] = a[key];
//	a[key] = temp;
//}
//else {		//엇갈리지 않았다면 i와 j를 교체
//	temp = a[left];
//	a[left] = a[right];
//	a[right] = temp;
//}
//	}
//	quickSort(start, right - 1);
//	quickSort(right + 1, end);
//}
//
//int main() {
//	int n, i;
//	cin >> n;
//	for (i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	quickSort(0, n - 1);
//	for (i = 0; i < n; i++) {
//		cout << a[i] << " ";
//	}
//	return 0;
//}