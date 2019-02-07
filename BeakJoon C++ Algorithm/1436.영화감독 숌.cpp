/// 1436.¿µÈ­°¨µ¶ ¼ò

#include <iostream>

#define endl '\n'

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int six = 666, counter = 1, n;
	cin >> n;
	while (counter != n) {
		bool flag = 1;
		while (flag) {
			six++;
			int m = six, sc = 0;
			while (m) {
				if (m % 10 == 6)
					sc++;
				else
					sc = 0;
				m /= 10;
				if (sc == 3)
					flag = 0;
			}
		}
		counter++;
	}
	cout << six << endl;

}

/*


a666b


0~1000

*/