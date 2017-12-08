// 1089엘리베이터

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string numData[5] = {
"###...#.###.###.#.#.###.###.###.###.###",
"#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
"#.#...#.###.###.###.###.###...#.###.###",
"#.#...#.#.....#...#...#.#.#...#.#.#...#",
"###...#.###.###...#.###.###...#.###.###"
};

int num[10];

int n;
vector <int> info;
vector < vector<int> > pos;
size_t counter = 1;

void init1();
void init2(int, string[]);
size_t makeCom();

int main() {
	string input[5];

	cin >> n;
	for (int i = 0; i < 5; i++)
		cin >> input[i];
	info.resize(n, 0);
	pos.resize(n);

	init1();
	init2(n, input);
	/*
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 3; j++)
				cout << ((bool(num[k] & (1 << (j + i * 3))))?'#':'.');
			cout << endl;
		}
		cout << endl;
	}
	*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++)
			if (num[j] == (info[i] | num[j]))
				pos[i].push_back(j);
		counter *= pos[i].size();
	}
	if (counter == 0) {
		cout << -1;
		return 0;
	}
	cout << fixed;
	cout.precision(10);
	cout << (double)makeCom() / counter;
}

void init1() {
	for (int n = 0; n < 10; n++)
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 3; j++)
				num[n] |= (bool)(numData[i][j + n * 4] == '#') << (j + i * 3);
}

void init2(int n, string input[]) {
	for (int x = 0; x < n; x++)
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 3; j++)
				info[x] |= (bool)(input[i][j + x * 4] == '#') << (j + i * 3);
}

size_t makeCom() {
	// 0은 맨 앞자리, n - 1은 맨뒷자리
	size_t ans = 0;
	for (int i = 0; i < n; i++) {
		size_t tmp = 0;
		ans *= 10;
		for (int j = 0; j < pos[i].size(); j++)
			tmp += pos[i][j];
		tmp *= (counter / pos[i].size());
		ans += tmp;
	}
	return ans;
}