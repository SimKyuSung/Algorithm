/// 1654 ���� �ڸ���

#include <iostream>
#include <vector>

using namespace std;

vector <int> lanCable;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, n, max = 0;
	cin >> k >> n;
	lanCable.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> lanCable[i];
	}

	unsigned int left = 1, right = (1 << 31) - 1;
	while (left <= right) {
		unsigned int mid = left + (right - left) / 2;
		
		// mid�� �߶����� ����
		int counter = 0;
		for (int i = 0; i < k; i++)
			counter += lanCable[i] / mid;

		// 1. ������ ���ڶ�� ũ�� �߶���
		if (counter < n)
			right = mid - 1;
		// 2. ���ų� ũ�� �۰� �߶���
		else
			left = mid + 1;
		//cout << left << " " << right << endl;
	}
	cout << right;
}

/*
1 1
2147483647
*/