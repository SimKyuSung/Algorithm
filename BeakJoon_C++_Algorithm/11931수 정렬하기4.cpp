/// 11931수 정렬하기4

//#include <stdio.h>
//
//int arr[1000004];
//
//void q_sort(int bottom, int top, int *a);
//
//int main()
//{
//	int n;						scanf("%d", &n);
//	for (int i = 0; i < n; i++)	scanf("%d", &arr[i]);
//	q_sort(0, n - 1, arr);
//	for (int i = n - 1; i > -1; i--)	printf("%d\n", arr[i]);
//}
//
//void q_sort(int left, int right, int *a) {
//	int pivot = a[left];
//	int l_hold = left;
//	int r_hold = right;
//	while (left < right) {
//		// 피벗 보다 작으면 왼쪽으로 가져옴
//		while (a[right] >= pivot && left < right)	right--;
//		if (left != right)		a[left] = a[right];
//
//		// 피벗보다 크면 오른쪽으로 가져옴
//		while (a[left] <= pivot  && left < right)	left++;
//		if (left != right) {
//			a[right] = a[left];
//			right--;
//		}
//	}
//	a[left] = pivot;
//	if (l_hold < left) 
//		q_sort(l_hold, left - 1, a);
//	if (r_hold > left)
//		q_sort(left + 1, r_hold, a);
//}


#include <cstdio>
#include <algorithm>

int arr[1000004];

int main()
{
	int n;						scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	for (int i = n - 1; i > -1; i--)	printf("%d\n", arr[i]);
}