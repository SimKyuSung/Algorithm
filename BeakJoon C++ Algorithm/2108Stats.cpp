// 2108Stats

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int arithmetci = 0;
int median;
int mode;
int range;

vector <int> arr;
vector <int> counter(8001, 0);

int main()
{
	// �Է�
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int input = 4000;
	//n = 499999;
	while (n--) {
		cin >> input;
		//input = -4000;

		// ��� ���
		arithmetci += input;
		// �߾Ӱ�, ����
		arr.push_back(input);
		// �ֺ�
		counter[input + 4000]++;
	}
	n = arr.size();


	// �˰���
	// 0. ����
	sort(arr.begin(), arr.end());

	// 1. ��� ���
	arithmetci = round((double)arithmetci / (double)n);

	// 2. �� �� ��
	median = arr[n / 2];

	// 3. �ֺ�
	int modeCounter = 0;
	bool mulitplex = false;
	for (int i = 0; i < 8001; i++) {
		// ���� ���� ���� ����
		if (modeCounter <= counter[i]) {
			// ���� ���� ���� ������ �� ��� �ֺ󰪵��� �ι�°�� ���� �� ���
			if ((modeCounter == counter[i]) && !mulitplex) {
				mode = i - 4000;
				mulitplex = true;
			}
			if ((modeCounter < counter[i])) {
				mode = i - 4000;
				mulitplex = false;
			}
			modeCounter = counter[i];
		}
	}

	// 4. ����
	range = arr.back() - arr.front();


	// ���
	cout << arithmetci << '\n';
	cout << median << '\n';
	cout << mode << '\n';
	cout << range << '\n';
}