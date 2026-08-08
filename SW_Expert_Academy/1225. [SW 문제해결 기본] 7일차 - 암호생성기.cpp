/// 1225. [S/W 문제해결 기본] 7일차 - 암호생성기

#include <iostream>

using namespace std;

int arr[8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase = 10;

	for (int t = 1; t <= testCase; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < 8; i++)
			cin >> arr[i];

		int x = arr[0] / 15;
		x--;
		for (int i = 0; i < 8; i++)
			arr[i] -= (x * 15);

		int i = 0;
		int c = 0;
		do {
			arr[i] -= (c + 1);
			i++;
			c++;
			i = i % 8;
			c = c % 5;
		} while (arr[i] - (c + 1) > 0);
		arr[i] -= (c + 1);

		if (arr[i] < 0)
			arr[i] = 0;
		i++;

		cout << '#' << t;
		for (int j = 0; j < 8; j++) {
			i = i % 8;
			cout << ' ' << arr[i++];
		}
		cout << '\n';

	}
}

/*

9950 9556 9550 9553 9558 9551 9551 9551
1	 2	  3	   4	5	 1	  2	   3
4	 5	  1	   2	3	 4	  5	   1
2	 3	  4	   5	1	 2	  3	   4
5	 1	  2	   3	4	 5	  1	   2
3	 4 	  5	   1	2	 3	  4	   5		X = 1

1	 2	  3	   4	5	 1	  2	   3
4	 5	  1	   2	3	 4	  5	   1
2	 3	  4	   5	1	 2	  3	   4
5	 1	  2	   3	4	 5	  1	   2
3	 4 	  5	   1	2	 3	  4	   5		X = 2

1	 2	  3	   4	5	 1	  2	   3
4	 5	  1	   2	3	 4	  5	   1
2	 3	  4	   5	1	 2	  3	   4
5	 1	  2	   3	4	 5	  1	   2
3	 4 	  5	   1	2	 3	  4	   5		x = 3


a[0] - 
15(x)	 15	  15   15	15	 15	  15   15

*/