/// 1371.가장 많은 글자

#include <iostream>
#include <string>

#define endl '\n'
#define MAX(a, b) (a)>(b)?(a):(b)

using namespace std;

int counter[128];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string line;
	while (getline(cin, line))
		for (auto s : line)
			counter[s]++;
	
	int ansCounter = 0;
	for (char a = 'a'; a <= 'z'; a++)
		ansCounter = MAX(ansCounter, counter[a]);
	for (char a = 'a'; a <= 'z'; a++)
		if (ansCounter == counter[a])
			cout << a;
	cout << endl;
}