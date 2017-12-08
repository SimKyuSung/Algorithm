/// 2312�� �����ϱ�

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector <bool> arr(100000, true);
vector <int> pNum;

int main()
{
	ios::sync_with_stdio(false);
	// make prime num
	for (int i = 2; i < 1000; i++) {
		// �̹� �湮�� ���Ҵ� ����
		if (!arr[i])	continue;
		for (int j = i + i; j < 100000; j+=i) {
			arr[j] = false;
		}
	}
	for (int i = 2; i < 100000; i++)
		if (arr[i])
			pNum.push_back(i);


	// input
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		// n�� 1�� ������!
		int p = 0;
		while (n != 1) {
			// �Ҽ��� ������ ��������?!
			int counter = 0;
			while (n % pNum[p] == 0) {
				counter++;
				n /= pNum[p];
			}
			// �������� �ִٸ� 
			if (counter)
				cout << pNum[p] << " " << counter << "\n";
			p++;
		}
	}
}