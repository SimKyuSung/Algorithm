/// 1377���� ��Ʈ

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
		// 1. �ߺ��� �Ÿ���
		int dc, next_i = i + 1, j = 0;
		while (next_i < n && b[i] == b[next_i]) next_i++;
		dc = next_i - i;
		// 2. �������� �迭���� �󸶳� �ڿ� �ִ��� ã�� (�ڿ��� �߰ߵ� ���� ���ýð��� �����)
		while(dc) {
			if (b[i] == a[j])
				dc--;
			j++;
		}
		i = next_i - 1;
		res = j - next_i + 1;
		// 3. res�� ���Դ�.
		// 4. res�� ũ�ٸ� �ڿ� �ִ� ���ڴ� �˻� ���Ҳ��� �ù�
		// ��? �̹� ū���� ���� ���ýð��� �ø� �ɷ��� ���� ������
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
1	2	1	2	1	��1
1	1	2	1	2	��2
1	1	1	2	2	��3

�̹� ��Ʈ�� �����϶� �ð����⵵ = O(n^2)
5
1	2	3	4	5
1

5
5	4	3	2	1
5



*/