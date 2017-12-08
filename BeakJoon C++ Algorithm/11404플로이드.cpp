/// 11404�÷��̵�

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
	// ## �÷��̵� ���� �˰���
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// i -> j ���� k�� �����ؼ� ���� ���� �� �۴ٸ� �������� �ؼ� ���� ����ġ�� ��ȯ
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