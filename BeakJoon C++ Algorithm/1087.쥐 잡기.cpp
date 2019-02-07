/// 1087.¡„ ¿‚±‚

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

typedef long long LL;

struct Point {
	LL y, x, vy, vx;
};

const LL scaleFactor = 10e10;
int n;
vector <LL> ansTime;
vector <Point> p;

void solve1(int);
void solve2(int);
LL cal();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	p.resize(n);
	for (auto &p : p) {
		cin >> p.x >> p.y >> p.vx >> p.vy;
		p.x *= scaleFactor;
		p.y *= scaleFactor;
	}

	solve1(0);

	LL ans = cal();
	cout << ans / scaleFactor;
	if (ans % scaleFactor)
		cout << '.' << ans % scaleFactor;
	cout << endl;
}

void solve1(int counter) {
	ansTime.push_back(0);

	LL pre = cal();
	int underBound = 0;
	for (int t = 1; t <= 20000; t++) {
		ansTime[0] = t;
		LL now = cal();
		if (pre > now)
			underBound = t;
		pre = now;
	}
	ansTime[0] = underBound;
	solve2(1);
}
void solve2(int counter) {
	if (counter > 11)
		return;

	ansTime.push_back(0);
	LL pre = cal();
	int underBound = 0;
	for (int t = 1; t < 10; t++) {
		ansTime[counter] = t;
		LL now = cal();
		if (pre > now)
			underBound = t;
		pre = now;
	}
	ansTime[counter] = underBound;
	solve2(counter + 1);
}

LL cal() {
	LL t = 0, ten = scaleFactor;
	for (int i = 0; i < ansTime.size(); i++) {
		t += ansTime[i] * ten;
		ten /= 10;
	}
	LL yMax, yMin, xMax, xMin;
	yMax = yMin = p[0].y + p[0].vy * t;
	xMax = xMin = p[0].x + p[0].vx * t;
	for (int i = 1; i < n; i++) {
		yMax = max(yMax, p[i].y + p[i].vy * t);
		xMax = max(xMax, p[i].x + p[i].vx * t);
		yMin = min(yMin, p[i].y + p[i].vy * t);
		xMin = min(xMin, p[i].x + p[i].vx * t);
	}
	return max(yMax - yMin, xMax - xMin);
}