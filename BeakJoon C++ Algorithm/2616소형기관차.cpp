/// 2616소형기관차

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c, tmp, ans = 0;
vector <int> a;
vector <int> train1;
vector <int> train2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> c;
	
	train1.resize(n - c + 1);
	for (int i = 0; i < c; i++)
		train1[0] += a[i];
	for (int i = 1; i < n - c + 1; i++)
		train1[i] = train1[i - 1] - a[i - 1] + a[c + i - 1];

	train2.resize(n - c * 3 + 1);
	tmp = train1[0];
	for (int i = 0; i < n - c * 3 + 1; i++) {
		train2[i] = tmp + train1[i + c];
		tmp = max(tmp, train1[i + 1]);
	}
	train2.push_back(0);

	//for (int i = 0; i < train1.size(); i++)
	//	cout << train1[i] << " ";
	//cout << endl;
	//for (int i = 0; i < train2.size(); i++)
	//	cout << train2[i] << " ";
	//cout << endl;
	tmp = train2[0];
	for (int i = 0; i < n - c * 3 + 1; i++) {
		ans = max(ans, tmp + train1[i + c * 2]);
		tmp = max(tmp, train2[i + 1]);
		//cout << ans << " ";
	}
	cout << ans << endl;
}
/*



7
35	40	50	10	30	45	60
1
	75	90	60	80	95	110
		125	100	120	135	155

7
35	40	50	10	30	45	60
2

	75	90	60	40	75	105
			135	130
					210	240

*/