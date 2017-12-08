/// 1016���� ������

#include <iostream>
#include <vector>

using namespace std;

const int maximum = 1000000;
vector <size_t> prime;
bool check[maximum + 1];

int main()
{
	// �Ҽ� ����
	check[0] = true;
	check[1] = true;
	for (size_t i = 2; i <= maximum; i++) {
		if (!check[i]) {
			prime.push_back(i * i);
			for (int j = i; j <= maximum; j += i)
				check[j] = true;
		}
	}
	size_t left, right;
	cin >> left >> right;

	
	for (size_t p : prime) {
		if (p > right)	break;
		// left - right ���� p�� ����� ó������ ��� �ϴ°�
		// p * x >= left �϶� p * x�� �ּڰ� (x�� ���� ����)
		// left + p - left % p
		size_t num = left + p - left % p;
		if (left % p == 0) num = left;
		while (num <= right) {
			check[num - left] = false;
			num += p;
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= right - left; i++) {
		if (check[i]) {
			cout << i + left << endl;
			ans++;
		}
	}
	cout << ans << endl;
}

/*

������					(0	~	1,000,000)
4 9 16 25 36 49 64 ...		1,000,000,000,000

�Ҽ� ������				(2	~	
4 9 25 49 121

�־��� ����� ��
1,000,000,000,000	~	1,000,001,000,000

1. 
 4  8  12 16 20
		9	  18
         13
 13 % 4 = 1
 13 + 4 - 1 = 16
 13 % 9 = 4
 13 + 9 - 4

*/