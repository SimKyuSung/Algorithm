/// 1242. [S/W 문제해결 응용] 1일차 - 암호코드 스캔

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
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
bitset<4> mask[16];
int chex[128];

bitset<2000> codeLine;
short decodeLine[2000][2000][2];

vector<int> decodeTest(int);
int x[4];
bool ven(vector<int>);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream cin("sample_input.txt");
	
	for (int i = 0; i < 16; i++)
		mask[i] = i;
	for (int i = '0'; i <= '9'; i++)
		chex[i] = i - '0';
	for (int i = 'A'; i <= 'F'; i++)
		chex[i] = i - 'A' + 10;
	
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		memset(decodeLine, 0, sizeof(decodeLine));

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string line;
			cin >> line;

			// 16진수 -> 2진수
			for (int j = 0; j < m; j++) {
				int num = chex[line[j]];
				for (int count4 = 0; count4 < 4; count4++)
					codeLine[j * 4 + count4] = mask[num][3 - count4];
			}

			// 이진 코드 출력
			//for (int j = 0; j < m * 4; j++)
			//	cout << codeLine[j];
			//cout << endl;

			for (int j = m * 4 - 1; j >= 0; j--) {
				vector <int> code;
				if (codeLine[j]) {
					// 디코딩
					code = decodeTest(j);
					if (code.size() == 9)
						j -= 56 * code[8] - 1;
				}
				if (ven(code)) {
					for (int c = 0; c < 8; c++)
						decodeLine[i][j][0] += code[c];
					decodeLine[i][j][1] = 1;
				}
			}
		}
		// cout << "input success\n";
		m *= 4;
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
				if (decodeLine[i][j][1] > 4) {
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

vector<int> decodeTest(int j) {
	vector <int> code(9, -1);
	code[8] = 1;
	memset(x, 0, sizeof(x));
	// 코드 길이 기준 만들기
	int d = 3;
	bool now = 1;
	do {
		if (j < 0)
			return vector <int>();
		if (now != codeLine[j]) {
			d--;
			now = codeLine[j];
		}
		x[d]++;
		j--;
	} while (d != -1);
	j++;
	code[8] = (x[0] + x[1] + x[2] + x[3]) / 7;

	//  cry 검색
	int num;
	for (num = 0; num < 10; num++) {
		int match = 0;
		for (int num4 = 0; num4 < 4; num4++) {
			match += (x[num4] == cry[num][num4] * code[8]);
		}
		if (match == 4)
			break;
	}
	if (num == 10)
		return vector <int> ();
	code[7] = num;

	// 기준 코드 출력
	//for (int i = 0; i < 4; i++)
	//	cout << x[i] << ' ';
	//cout << endl;

	// code 8 reading
	for (int cd = 6; cd >= 0; cd--) {
		memset(x, 0, sizeof(x));
		d = 3;
		now = 1;
		do {
			if (j < 0)
				return vector <int>();
			if (now != codeLine[j]) {
				d--;
				now = codeLine[j];
			}
			x[d]++;
			j--;
		} while (x[0] + x[1] + x[2] + x[3] != 7 * code[8]);

		// 코드 출력
		//for (int i = 0; i < 4; i++)
		//	cout << x[i] << ' ';
		//cout << endl;

		//  cry 검색
		for (num = 0; num < 10; num++) {
			int match = 0;
			for (int num4 = 0; num4 < 4; num4++) {
				match += (x[num4] == cry[num][num4] * code[8]);
			}
			if (match == 4)
				break;
		}
		if (num == 10)
			return vector <int>();
		code[cd] = num;
	}

	//for (int i = 0; i < 9; i++)
	//	cout << code[i] << ' ';
	//cout << endl;
	
	return code;
}

/*
코드 검증
*/
bool ven(vector<int> code) {
	if (code.size() != 9)
		return 0;
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0)
			code[i] *= 3;
		sum += code[i];
	}
	return (sum % 10) == 0;
}