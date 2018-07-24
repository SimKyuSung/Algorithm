/// 3363. 영준이의 정수 저장

#include <iostream>
#include <vector>

using namespace std;

struct A
{
	int x, y, z;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		cin >> n;
		vector<A> odd;
		A a;
		while (n--) {
			cin >> a.x >> a.y >> a.z;
			int yy = (a.y - a.x) / a.z;
			a.y = yy * a.z + a.x;

			if (odd.empty())
				odd.push_back(a);
			else {
				for (int i = 0; i < odd.size(); i++) {

				}
			}
		}
		cout << '#' << t << ' ';
		if (!odd.empty())	cout << odd.front().x << '\n';
		else				cout << "no corruption\n";
	}
}

/*

n <= 20000;
홀수인 영역을 체크해보자!

 2 5 8 11
 y 11
 y 10 -> 8   2 10 3     2 8 3
				2
 y 9  -> 8   2  9 3
				2
 y 8  -> 8   2  8 3
				2
   3x * 2 < 10
   3x < 10 - 2
   3x < 8
   x = 2



*/