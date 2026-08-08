/// 1399보물의 위치

#include <iostream>
#include <vector>

using namespace std;

// 북, 서, 남, 동
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int k, m, gold = 1, x1i, y1i, x2i, y2i;
		long long x = 0, y = 0;
		cin >> k >> m;
		
		// cycle 찾기
		vector <int> cycle, x1, y1, x2, y2;
		bool f = true;
		int s, tmp;
		while (f) {
			cycle.push_back(gold);
			gold *= m;
			while (gold > 9) {
				int tmp = gold;
				gold = 0;
				while (tmp) {
					gold += tmp % 10;
					tmp /= 10;
				}
			}
			for (int i = 0; i < cycle.size(); i++) {
				if (gold == cycle[i]) {
					s = i;
					f = false;
					break;
				}
			}
		}
		cout << "cout cycle\n";
		for (int i = 0; i < cycle.size(); i++)
			cout << cycle[i] << " ";
		cout << endl;
		// cycle 시작 전까지 루프
		int c = cycle.size();
		for (int i = 0; i < k && i < s; i++) {
			x += dx[i] * cycle[i];
			y += dy[i] * cycle[i];
		}
		cout << "cycle 이전 루프 결과\n";
		cout << x << " " << y << endl;

		// cycle + y
		cout << "error y1\n";
		tmp = s;
		while (tmp % 4 != 0) { tmp++; }
		while (tmp >= c)
			tmp = s + tmp - c;
		y1i = tmp;
		while (1) {
			y1.push_back(cycle[tmp]);
			tmp += 4;
			while (tmp >= c)
				tmp = s + tmp - c;
			if (y1.front() == cycle[tmp])
				break;
		}
		cout << "cout y1 cycle\n";
		for (int i = 0; i < y1.size(); i++)
			cout << y1[i] << " ";
		cout << endl;
		// 1. k 에서 반복 +y 시작 인덱스를 뺀다
		tmp = k - y1i;
		// 2. 그 값이 음수라면 그냥 넘어 가고 양수 라면 cycle+y.szie() 로 그값을 나눈묶과 나머지를 가져온다
		if (tmp > 0) {
			// 3. y + cyled의 원소의 합 * 묶 + 나머지 인덱스
			int sum = 0, cc = y1.size();
			for (int i = 0; i < cc; i++)
				sum += y1[i];
			y += (tmp / (cc * 4)) * sum;
			for (int i = 0; i < tmp % (cc * 4); i+=4)
				y += y1[i / 4];
		}

		// cycle + x 
		cout << "error x1\n";
		tmp = s;
		while (tmp % 4 != 1) { tmp++; }
		while (tmp >= c)
			tmp = s + tmp - c;
		x1i = tmp;
		while (1) {
			x1.push_back(cycle[tmp]);
			tmp += 4;
			while (tmp >= c)
				tmp = s + tmp - c;
			if (x1.front() == cycle[tmp])
				break;
		}
		cout << "cout x1 cycle\n";
		for (int i = 0; i < x1.size(); i++)
			cout << x1[i] << " ";
		cout << endl;
		// 1. k 에서 반복 +y 시작 인덱스를 뺀다
		tmp = k - x1i;
		// 2. 그 값이 음수라면 그냥 넘어 가고 양수 라면 cycle+y.szie() 로 그값을 나눈묶과 나머지를 가져온다
		if (tmp > 0) {
			// 3. y + cyled의 원소의 합 * 묶 + 나머지 인덱스
			int sum = 0, cc = x1.size();
			for (int i = 0; i < cc; i++)
				sum += x1[i];
			x += (tmp / (cc * 4)) * sum;
			for (int i = 0; i < tmp % (cc * 4); i += 4)
				x += x1[i / 4];
		}
		cout << "중간 점검!\n";
		cout << x << " " << y << endl;
		// cycle - y
		cout << "error y2\n";
		tmp = s;
		while (tmp % 4 != 2) { tmp++; }
		while (tmp >= c)
			tmp = s + tmp - c;
		y2i = tmp;
		while (1) {
			y2.push_back(cycle[tmp]);
			tmp += 4;
			while (tmp >= c)
				tmp = s + tmp - c;
			if (y2.front() == cycle[tmp])
				break;
		}
		// 1. k 에서 반복 +y 시작 인덱스를 뺀다
		tmp = k - y2i;
		// 2. 그 값이 음수라면 그냥 넘어 가고 양수 라면 cycle+y.szie() 로 그값을 나눈묶과 나머지를 가져온다
		if (tmp > 0) {
			// 3. y + cyled의 원소의 합 * 묶 + 나머지 인덱스
			int sum = 0, cc = y2.size();
			for (int i = 0; i < cc; i++)
				sum += y2[i];
			y -= (tmp / (cc * 4)) * sum;
			for (int i = 0; i < tmp % (cc * 4); i += 4)
				y -= y2[i / 4];
		}

		// cycle - x
		cout << "error x2\n";
		tmp = s;
		while (tmp % 4 != 3) { tmp++; }
		while (tmp >= c)
			tmp = s + tmp - c;
		x2i = tmp;
		while (1) {
			x2.push_back(cycle[tmp]);
			tmp += 4;
			while (tmp >= c)
				tmp = s + tmp - c;
			if (x2.front() == cycle[tmp])
				break;
		}
		// 1. k 에서 반복 +y 시작 인덱스를 뺀다
		tmp = k - x2i;
		// 2. 그 값이 음수라면 그냥 넘어 가고 양수 라면 cycle+y.szie() 로 그값을 나눈묶과 나머지를 가져온다
		if (tmp > 0) {
			// 3. y + cyled의 원소의 합 * 묶 + 나머지 인덱스
			int sum = 0, cc = x2.size();
			for (int i = 0; i < cc; i++)
				sum += x2[i];
			x -= (tmp / (cc * 4)) * sum;
			for (int i = 0; i < tmp % (cc * 4); i += 4)
				x -= x2[i / 4];
		}

		cout << x << " " << y << "\n";
	}
}

/*
input
k <= 1000000000
m <= 1000

k 가 10^9 임으로 싸이클을 찾아야 한다.
m = 1	1 1 1 1  1  1  1  1

m = 2	1 2 4 8  16 14 10 
				 7	5	1
		1 2 4 8  7  5

m = 3	1 3 9 27 27
			  9  9

m = 4	1 4 16 28	 
			 7  1
		1 4 7

m = 5	1 5 25 35 40 20 10
			7	8  4  2

ex)
		 -	   -      -
1 2 7 (8 3 5 6 9) 8 3 5 6 9)
	  (8 3 5 6 9)

k = 5
y1i = 0

12
1 x x x 7 x x x 4 x x x 1



*/