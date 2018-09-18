/// 1188.���� ��а�

#include <iostream>

#define endl '\n'

using namespace std;

int counter(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	cout << counter(n, m) << endl;
}

int counter(int n, int m) {
	if (n % m == 0)
		return 0;
	else if (n == 1)
		return m - 1;
	if (n > m) {
		n %= m;
		return counter(n, m);
	}
	else {
		return n + counter(n, m - n);
	}
}
/*

2 6
�޾ƾ� �ϴ¾� 1 / 3
2���� 2���� �ֱ�
2���ڸ�
2���� 2���� �ֱ�
2���ڸ�
2���� 2���� �ֱ�
��

3 4 
�޾ƾ� �ϴ� �� 3 / 4
3���� 3���ֱ�
3�� �ڸ�
3���� 1���ֱ�
��

7 6
�޾ƾ� �ϴ¾� 7 / 6
6���� 6���� �ֱ�
1���� 6���� �ֱ� (5���!)
��

#####
5 8
�޾ƾ� �ϴ� �� 5 / 8
5���� 5���� ��������

5 3 + 5
3���� 1���� �ֱ�
2 3
2���� 2���� �ֱ�
2 1 + 2
2���� 1���� �ֱ�
=> 7


2 7
2���� 2���� �ֱ�
2 5 + 2
2 3 + 2
2 1 + 2
��

*/