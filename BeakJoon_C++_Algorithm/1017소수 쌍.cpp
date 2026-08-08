/// 1017소수 쌍

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

const int LIM = 2000;

int n;
vector <bool> prime(LIM, true);
int arr[LIM];
vector <vector <int> > edge;
bool check[LIM];

bool matching(int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// prime get
	for (int i = 2; i < LIM; i++) {
		if (prime[i]) {
			for (int j = i + i; j < LIM; j += i)
				prime[j] = false;
		}
	}

	cin >> n;
	edge.resize(n, vector<int>());
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (prime[arr[i] + arr[j]]){
				edge[i].push_back(j);
				edge[j].push_back(i);
			}
		}
		if (edge[i].size() == 0) {
			cout << -1;
			return 0;
		}
	}

	bool ans = 0, tmp;
	for (int i = 0; i < edge[0].size(); i++) {
		memset(check, 0, sizeof(check));
		check[0] = 1;
		check[edge[0][i]] = 1;

		tmp = 0;
		for (int j = 1; j < n; j++) {
			if (!check[j]) {
				check[j] = 1;
				tmp = matching(j, n / 2);
				check[j] = 0;
				break;
			}
		}
		tmp |= (n == 2);
		if (tmp) {
			cout << arr[edge[0][i]] << '\n';
		}
		ans |= tmp;
	}
	if (!ans) {
		cout << -1;
	}
}

bool matching(int x, int counter) {
	cout << arr[x] << ' ' << counter << endl;
	// 0. 전부 매칭 됨
	if (counter == 1)
		return 1;

	// 1. x랑 매칭되는 친구를 하나 찾고
	for (int i = 0; edge[x].size(); i++) {
		if (!check[edge[x][i]]) {
			check[edge[x][i]] = 1;
			// 2. 다음 매칭이 안된 친구를 찾기
			for (int j = 1; j < n; j++) {
				if (!check[j]) {
					check[j] = 1;
					if (matching(j, counter - 1))
						return 1;
					check[j] = 0;
					break;
				}
			}
			check[edge[x][i]] = 0;
			if (counter == 2)
				return 1;
		}
	}
	return 0;
}

/*
이분매칭
1. 매칭을하고
2. 다음 단계 매칭노드를 빠르게 찾는 방법이 있을까?

*/