#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int maximum = 0;
	int passenger = 0;
	int inTrain, outTrain;
	for (int i = 0; i < 10; i++) {
		cin >> outTrain >> inTrain;
		passenger += inTrain - outTrain;
		maximum = max(maximum, passenger);
	}
	cout << maximum << endl;
}