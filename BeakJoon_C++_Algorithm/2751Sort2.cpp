#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	int N, input;
	cin >> N;
	while (N--) {
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
		printf("%d\n", arr[i]);
}