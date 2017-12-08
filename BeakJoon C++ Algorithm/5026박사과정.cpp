/// 5026박사과정

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	while (n--) {
		string line;
		cin >> line;
		if (line[0] == 'P') cout << "skipped\n";
		else {
			int num1 = 0, num2 = 0;
			int i = 0;
			for (i = 0; line[i] != '+'; i++) {
				num1 *= 10;
				num1 += line[i] - '0';
			}
			for (i += 1; i < line.length(); i++) {
				num2 *= 10;
				num2 += line[i] - '0';
			}
			cout << num1 + num2 << "\n";
		}
	}
	
}