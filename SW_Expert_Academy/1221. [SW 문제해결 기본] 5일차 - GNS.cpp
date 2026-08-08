/// 1221. [S/W 문제해결 기본] 5일차 - GNS

#include <iostream>
#include <map>
#include <string>

using namespace std;

map <string, int> usaTry;
string num[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };
int counter[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 10; i++)
		usaTry[num[i]] = i;

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		string tcNum, input;
		cin >> tcNum >> n;
		while (n--) {
			cin >> input;
			counter[usaTry[input]]++;
		}

		cout << '#' << t << '\n';
		for (int i = 0; i < 10; i++) {
			while (counter[i]--)
				cout << num[i] << ' ';
			counter[i] = 0;
		}
		cout << '\n';
	}
}