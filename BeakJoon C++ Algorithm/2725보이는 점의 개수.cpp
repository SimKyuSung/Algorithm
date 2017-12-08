/// 2725보이는 점의 개수

#include <iostream>
#include <vector>

using namespace std;

vector <int> arr(1001);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 1; i < 1001; i++) {
		arr[i] += i * 2 + 1;
		for (int j = i + i; j < 1001; j += i)
			arr[j] -= arr[i];
	}

	for (int i = 1; i < 1001; i++)
		arr[i] += arr[i - 1];

	int c, n;
	cin >> c;
	while (c--) {
		cin >> n;
		cout << arr[n] << endl;
	}
}

/*

*/