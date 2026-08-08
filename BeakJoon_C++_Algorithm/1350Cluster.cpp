// 1350Cluster

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<int> sizeFile(1004);
	unsigned long long cluster;
	unsigned long long diskSize = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> sizeFile[i];
	cin >> cluster;

	for (int i = 0; i < n; i++) {
		if (sizeFile[i] <= cluster)
			diskSize++;
		else {
			diskSize += (sizeFile[i] / cluster);
			if (sizeFile[i] % cluster)
				diskSize++;
		}
		if (sizeFile[i] == 0)
			diskSize--;
	}
	cout << diskSize * cluster << endl;
}