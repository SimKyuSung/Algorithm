/// 10867�ߺ� ���� �����ϱ�

#include <iostream>
#include <vector>

using namespace std;

vector <bool> arr(2001, false);

int main()
{
	int n;	cin >> n;
	while (n--) {
		int tmp;	cin >> tmp;
		arr[tmp + 1000] = true;
	}
	for (int i = 0; i < 2001; i++)
		if (arr[i])
			cout << i - 1000 << " ";
	cout << endl;
	
}