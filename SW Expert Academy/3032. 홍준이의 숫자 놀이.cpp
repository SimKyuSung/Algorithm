/// 3032. 홍준이의 숫자 놀이

#include <iostream>
#include <memory.h>
#include <queue>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int a, b;
		cin >> a >> b;
		queue<int> q;
		q.push(1);
		q.front();

		cout << '#' << t << ' ' << a % b << endl;
	}
}

/*

ax + by = 1
by = 1 - ax
y = (1 - ax) / b

y = (1 - 3x) / 5
-2
-5
-8
-11
-14
-17
-20

(1 - 1a) % b를 해서 나머지가 있으면 
(1 - 2a)

1 - 3a

1 - 4a


*/