/// 1240. [S/W 문제해결 응용] 1일차 - 단순 2진 암호코드

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory.h>

using namespace std;

int cry[10][4] = {
{ 3, 2, 1 ,1 },
{ 2, 2, 2 ,1 },
{ 2, 1, 2 ,2 },
{ 1, 4, 1 ,1 },
{ 1, 1, 3 ,2 },
{ 1, 2, 3 ,1 },
{ 1, 1, 1 ,4 },
{ 1, 3, 1 ,2 },
{ 1, 2, 1 ,3 },
{ 3, 1, 1 ,2 },
};

string codeLine[50];
int decodeLine[50][100][2];

vector<int> decode(int, int);
bool ven(vector<int>);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//ifstream cin("input.txt");
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(decodeLine, 0, sizeof(decodeLine));

		int n, m;	
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> codeLine[i];

		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) {
				vector <int> code;
				if (codeLine[i][j] != '0') {
					// 디코딩
					code = decode(i, j);
					j -= 55;
				}
				if (ven(code)) {
					for (int c = 0; c < 8; c++)
						decodeLine[i][j][0] += code[c];
					decodeLine[i][j][1] = 1;
				}
			}
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m - 55; j++) {
				if (decodeLine[i - 1][j][0] == decodeLine[i][j][0]) {
					decodeLine[i][j][1] += decodeLine[i - 1][j][1];
					decodeLine[i - 1][j][0] = decodeLine[i - 1][j][1] = 0;
				}
			}
		}

		int ans = 0;
		for (int i = 4; i < n; i++) {
			for (int j = 0; j < m - 55; j++) {
				if (decodeLine[i][j][1] > 4 ) {
					ans += decodeLine[i][j][0];
				}
			}
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
}

/*
code 를 반환, 실패시 Null 리턴
*/
vector<int> decode(int i, int j) {
	vector <int> code(8, -1);
	// code 8 reading
	for (int cd = 7; cd >= 0; cd--) {
		int x[4] = { 0, 0, 0, 0 };
		int d = 3;
		char now = '1';
		for (int c = 0; c < 7; c++, j--) {
			if (j < 0) return code;
			if (now != codeLine[i][j]) {
				d--;
				now = codeLine[i][j];
			}
			x[d]++;
		}
		int num;
		for (num = 0; num < 10; num++) {
			int match = 0;
			for (int num4 = 0; num4 < 4; num4++) {
				match += (x[num4] == cry[num][num4]);
			}
			if (match == 4)
				break;
		}
		if (num == 10)
			return vector <int>();
		code[cd] = num;//Todo
	}
	return code;
}

/*
코드 검증
*/
bool ven(vector<int> code) {
	if (code.size() != 8)
		return 0;
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0)
			code[i] *= 3;
		sum += code[i];
	}
	return (sum % 10) == 0;
}