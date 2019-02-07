/// 2477. [���� SW �����׽�Ʈ] ���� �����

#include <iostream>
#include <queue>
#include <memory.h>

#define endl '\n'

using namespace std;

int n, m, k, a, b;

queue <int> tk[1001];
int cn[1001];
int cm[1001];

int ai[20], bj[20];
int aTime[20], bTime[20];
int ac[20], bc[20];

// ����â�� �ټ��� ���
priority_queue <int> receiveLine;
// ����â�� �ټ��� ���
queue <int> repairLine;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int ans = 0;
		cin >> n >> m >> k >> a >> b;
		for (int i = 0; i < n; i++)
			cin >> ai[i];
		for (int j = 0; j < m; j++)
			cin >> bj[j];
		for (int id = 0; id < k; id++) {
			int tmp;
			cin >> tmp;
			tk[tmp].push(id);
		}

		memset(bTime, 0, sizeof(bTime));

		int timer = 0, counter = 0;
		while (counter < k) {
			// 1. ������ �����
			if (timer <= 1000) {
				while (!tk[timer].empty()) {
					int id = -tk[timer].front();
					tk[timer].pop();
					receiveLine.push(id);
				}
			}
			// 2. ���� â��(a)
			for (int i = 0; i < n; i++) {
				if (aTime[i] != 0) {
					aTime[i]--;
					if (aTime[i] == 0)
						repairLine.push(ac[i]);
				}
			}
			// (b)
			for (int j = 0; j < m; j++) {
				if (bTime[j] != 0) {
					bTime[j]--;	
				}
			}

			// �� ���� (a)
			for (int i = 0; i < n; i++) {
				if (aTime[i] == 0 && !receiveLine.empty()) {
					int id = -receiveLine.top();
					aTime[i] = ai[i];
					cn[id] = i;
					ac[i] = id;
					receiveLine.pop();
				}
			}

			// (b)
			for (int j = 0; j < m; j++) {
				if (bTime[j] == 0 && !repairLine.empty()) {
					bTime[j] = bj[j];
					cm[repairLine.front()] = j;
					repairLine.pop();
					counter++;
				}
			}

			timer++;
		}
		for (int id = 0; id < k; id++)
			if (cn[id] == a - 1 && cm[id] == b - 1)
				ans += (id + 1);

		cout << '#' << t << ' ' << (ans == 0 ? -1 : ans) << endl;
	}
}