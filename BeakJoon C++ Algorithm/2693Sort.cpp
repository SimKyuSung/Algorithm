#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int t, input;
	cin >> t;
	while (t--) {
		vector <int> arr(10);
		for (int i = 0; i < 10; i++)
			cin >> arr[i];
		sort(arr.begin(), arr.end());
		printf("%d\n", arr[7]);
	}
}