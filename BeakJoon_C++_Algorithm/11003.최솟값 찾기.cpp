/// 11003.최솟값 찾기

#include <iostream>
#include <deque>

#define endl '\n'

using namespace std;

int a[5000000];
deque <int> dq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		while (!dq.empty() && a[i] <= a[dq.back()])
			dq.pop_back();
		dq.push_back(i);
		if (i - l >= dq.front())
			dq.pop_front();
		cout << a[dq.front()] << ' ';
	}

	cout << endl;
}

/*
12 3
1 5 2 3 6 2 3 7 3 5 2 6
1		1
1 5		1
1 2		1
2 3		2


12 3

1 5 2 3 6 2 3 7 3 5 2 6
                  5 2 6
					  2
				3 5 2
				    2
			  7 3 5
			      3
			3 7 3
			    3


12 3
1 5 2 3 6 2 3 7 3 5 2 6
0							1
0 1							1
0 1 2						1
 [1 2]3						2
	2[3 4]					2
	 [3 4]5					2
	    4[5 6]				2
		 [5 6]7				2
		    6[7 8]			3


12 4
		1 5 2 3 6 2 3 7 3 5 2 6

x x x x 1 5 2 3								1
											1
											1
											1
		1 5 2 3 6 2 3 7						

				6 2 3 7 3 5 2 6

						3 5 2 6 x x x x



0							1
0 1							1
0 1 2 						1
0 1 2 3						1
 [1 2 3]4 					2
   [2 3,4 5]				2
      3[4 5 6] 				2
       [4 5 6]7				2
         [5 6,7 8] 			2
		    6 7 8 9

1 5 2 3 6 2 3 7 3 5 2 6
1		1
1 5		1
1 2		1
2 3		2

*/