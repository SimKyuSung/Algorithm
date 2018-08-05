/// 15639.Rick

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

const int n = 6;
string rick[] = { "Give you up", "Let you down", "Run around and desert you", "Make you cry", "Say goodbye", "Tell a lie and hurt you" };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input;
	getline(cin, input);
	for (auto s : rick) {
		if (s == input) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}