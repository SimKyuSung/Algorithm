/// 3142. 영준이와 신비한 뿔의 숲

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, m, tw, uni;
		cin >> n >> m;

		tw = n - m;
		uni = m - tw;

		cout << '#' << t << ' ' << uni << ' ' << tw << '\n';
	}
}

/*

n = tw * 2 + uni
m = tw + uni

*/