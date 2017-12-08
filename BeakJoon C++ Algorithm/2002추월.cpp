/// 2002추월

#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

list <string> car_in;

int main()
{
	int n;	cin >> n;

	string car;
	for (int i = 0; i < n; i++) {
		cin >> car;
		car_in.push_back(car);
	}

	int ans = 0;
	list<string>::iterator itor;

	for (int i = 0; i < n; i++) {
		cin >> car;
		// 맨 앞이 아니면... 추월한거임
		if (car_in.front() != car) {
			itor = find(car_in.begin(), car_in.end(), car);
			car_in.erase(itor);
			ans++;
		}
		else car_in.pop_front();
	}
	cout << ans << endl;
}