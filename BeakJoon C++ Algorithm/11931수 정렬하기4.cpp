/// 11931�� �����ϱ�4

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
//		// �ǹ� ���� ������ �������� ������
//		while (a[right] >= pivot && left < right)	right--;
//		if (left != right)		a[left] = a[right];
//
//		// �ǹ����� ũ�� ���������� ������
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