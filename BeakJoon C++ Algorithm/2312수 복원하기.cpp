/// 2312수 복원하기

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
		// 이미 방문한 원소는 죽음
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
		// n을 1로 만들자!
		int p = 0;
		while (n != 1) {
			// 소수로 나누어 떨어지면?!
			int counter = 0;
			while (n % pNum[p] == 0) {
				counter++;
				n /= pNum[p];
			}
			// 나눈적이 있다면 
			if (counter)
				cout << pNum[p] << " " << counter << "\n";
			p++;
		}
	}
}