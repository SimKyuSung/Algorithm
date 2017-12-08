/// 1398��������

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> counter;
vector <int> coin;

int main()
{
	// init
	counter.resize(100, 99);
	coin.resize(3);
	coin[0] = 1;
	coin[1] = 10;
	coin[2] = 25;
	
	counter[0] = 0;
	for (int i = 0; i < 3; i++)
		counter[coin[i]] = 1;
	for (int i = 2; i < 100; i++)
		for (int c = 0; c < 3; c++)
			if (i - coin[c] > 0)
				counter[i] = min(counter[i], counter[i - coin[c]] + 1);

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		size_t car;
		cin >> car;
		int ans = 0;
		while (car) {
			int tmp = car % 100;
			ans += counter[tmp];
			car /= 100;
		}
		cout << ans << "\n";
	}
}

/*
1,000,000,000,000,000
					0		0
					1		1
				   10		2
				   25		3
				  100		4
				1,000		5
				2,500		6
			   10,000
			  100,000
			  250,000
			1,000,000
		   10,000,000
		   25,000,000
		  100,000,000
		1,000,000,000
		2,500,000,000
	   10,000,000,000
	  100,000,000,000
	  250,000,000,000
	1,000,000,000,000
   10,000,000,000,000
   25,000,000,000,000
  100,000,000,000,000
1,000,000,000,000,000

ex) ���� ó��
100�̻��̸鼭 100�� ���� �ʴ� ����� ���� ���� �ϴ°�?
-> ����� �̷���� ����� ���� ���ڸ� ���°��� ������ �����ϴ�.

100�� 25�� ��������� 100�� ���� �ִٸ� 100�� ����.


*/