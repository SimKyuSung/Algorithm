/// 11780플로이드2

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int nagative = 10000001;
int n;
vector <vector <int> > w;
vector <vector <int> > v;


void floyd();
void path(int, int);

int main()
{
	ios::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	w.resize(n, vector<int>(n, nagative));
	v.resize(n, vector<int>(n, -1));
	while (m--) {
		int	a, b, c;
		cin >> a >> b >> c;
		w[a - 1][b - 1] = min(w[a - 1][b - 1], c);
	}

	for (int i = 0; i < n; i++)
		w[i][i] = 0;

	// ## 플로이드 워셜 알고리즘
	floyd();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (w[i][j] >= nagative) cout << 0 << " ";
			else			   cout << w[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)	cout << 0 << "\n";
			else		path(i, j);
		}
	}
}

void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// i -> j 보다 k를 경유해서 가는 값이 더 작다면 경유해서 가는 가중치로 교환
				if (w[i][j] > w[i][k] + w[k][j]) {
					w[i][j] = w[i][k] + w[k][j];
					// k -> j 가는 경로가 기록이 없다면 신규 경로 이고, 있다면 경유지의 경유지이다.
					if (v[k][j] == -1) v[i][j] = k;
					else				v[i][j] = v[k][j];
				}
			}
		}
	}
}

void path(int i, int j) {
	stack <int> s;
	s.push(j);
	while (v[i][s.top()] != -1) {
		s.push(v[i][s.top()]);
	}
	s.push(i);
	cout << s.size() << " ";
	while (!s.empty()) {
		cout << s.top() + 1 << " ";
		s.pop();
	}
	cout << "\n";
}

/*

0 2 3 1 10
0 0 0 2 0
8 0 0 1 1
0 0 0 0 3
7 4 0 0 0

0 0 0 0 3
5 0 5 0 4
0 5 0 0 0
5 5 5 0 0
0 0 1 2 0

output: 4 2 4 5 3
output: 5 2 4 5 1 3
[2][3] = 5
[2][5] = 4
[2][4] = 0

[2][3] = 1
[2][1] = 5
[2][5] = 4




4 4 5 3

*/