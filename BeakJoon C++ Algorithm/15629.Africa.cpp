/// 15629.Africa

#include <iostream>
#include <vector>
#include <string>

#define endl '\n'

using namespace std;

vector <string> country;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, ans = 0;
	country.push_back("");
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if		(s == "ethiopia")	ans += 50;
		else if (s == "kenya")		ans += 50;
		else if (s == "tanzania")	ans += 50;
		else if (s == "namibia") {
			ans += 140;
			for (int i = 0; i < country.size(); i++)
				if (country[i] == "south-africa")
					ans -= 100;
		}
		else if (s == "zambia") {
			ans += 50;
			if (country.back() == "zimbabwe")
					ans -= 30;
		}
		else if (s == "zimbabwe") {
			ans += 30;
			if (country.back() == "zambia")
					ans -= 30;
		}
		country.push_back(s);
	}
	cout << ans << endl;
}