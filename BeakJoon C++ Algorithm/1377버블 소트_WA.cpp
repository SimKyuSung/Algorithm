/// 1377버블 소트

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> a, b;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b.begin(), b.end());
	int res = 1;
	for (int i = 0; i < n - res; i++) {
		// 1. 중복수 거르기
		int dc, next_i = i + 1, j = 0;
		while (next_i < n && b[i] == b[next_i]) next_i++;
		dc = next_i - i;
		// 2. 오리지날 배열에서 얼마나 뒤에 있는지 찾기 (뒤에서 발견될 수록 소팅시간이 길어짐)
		while(dc) {
			if (b[i] == a[j])
				dc--;
			j++;
		}
		i = next_i - 1;
		res = j - next_i + 1;
		// 3. res가 나왔다.
		// 4. res가 크다면 뒤에 있는 숫자는 검사 안할꺼야 시발
		// 왜? 이미 큰숫자 들은 소팅시간을 늘릴 능력을 잃음 ㅋㅋㅋ
	}
	cout << res << '\n';
}

/*
5
10	1	5	2	3
3

1	2	3	5	10

5
10	5	3	2	1
5

5
10	2	5	3	1
5

5
2	3	5	10	1
5

5
1	2	3	5	10
1

5
1	1	1	1	1
1


5
1	2	1	2	1	문1
1	1	2	1	2	문2
1	1	1	2	2	문3

이미 소트된 상태일때 시간복잡도 = O(n^2)
5
1	2	3	4	5
1

5
5	4	3	2	1
5



*/