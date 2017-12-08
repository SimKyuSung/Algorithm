/// 11404플로이드

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int nagative = 10000001;
int n;
vector <vector <int> > w;

int main()
{
	ios::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	w.resize(n, vector<int>(n, nagative));
	while (m--) {
		int	a, b, c;
		cin >> a >> b >> c;
		w[a - 1][b - 1] = min(w[a - 1][b - 1], c);
	}

	for (int i = 0; i < n; i++)
		w[i][i] = 0;
	// ## 플로이드 워셜 알고리즘
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// i -> j 보다 k를 경유해서 가는 값이 더 작다면 경유지를 해서 가는 가중치로 교환
				if (w[i][j] > w[i][k] + w[k][j])
					w[i][j] = w[i][k] + w[k][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (w[i][j] >= nagative) cout << 0 << " ";
			else			   cout << w[i][j] << " ";
		}
		cout << "\n";
	}
}