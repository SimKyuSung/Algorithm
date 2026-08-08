/// 4672. 수진이의 팰린드롬

#include <iostream>
#include <string>
#include <memory.h>

#define endl '\n'

using namespace std;

int n[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int ans = 0;;
		string p;
		memset(n, 0, sizeof(n));

		cin >> p;
		for (int i = 0; i < p.size(); i++)
			n[p[i] - 'a']++;
		for (int i = 0; i < 26; i++)
			ans += n[i] * (n[i] + 1) / 2;
		cout << '#' << t << ' ' << ans << endl;
	}
}


/*

	a b a b a b g
	1 0 1 0 1 0 0
	  1 0 1 0 1 0
	    1 0 1 0 0
		  1 0 0 0 
		    1 0 0
			  1 0
			    1

	a b c c b a
	1 0 0 0 0 1
	  1 0 0 1 0
	    1 1 0 0
		  1 0 0
		    1 0
			  1

b 추가 했을때 10
	a b c b c b a
	1 0 0 0 0 0 1
	  1 0 0 0 1 0
	    1 0 1 0 0
		  1 0 0 0
		    1 0 0
		      1 0
			    1

b 추가 했을때  12
	a c b b b c a
	1 0 0 0 0 0 1
	  1 0 0 0 1 0
		1 1 1 0 0
		  1 1 0 0
			1 0 0
			  1 0
				1

b 추가 했을때  12
	a a b b b c c
	1 1 0 0 0 0 0
	  1 0 0 0 0 0
		1 1 1 0 0
		  1 1 0 0
			1 0 0
			  1 1
				1

*/