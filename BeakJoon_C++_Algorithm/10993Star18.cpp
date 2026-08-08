#include <iostream>
#include <string>

using namespace std;

int N;

// 2^n - 1
//char star[1024][1024];
string star[1024];

void starMaker(int);


int main()
{
	cin >> N;
	N = 1 << N;
	star[0] = "";
	starMaker(2);

	for (int i = 1; i < N; ++i)
		cout << star[i] << endl;
	return 0;
}

void starMaker(int n) {
	int bitMask = 0xAAAAAAAA;
	int n_1 = n >> 1;
	if (n & bitMask) {
		// 복사하기
		for (int i = n_1 - 1; i != 0; --i)
			star[i + n_1 - 1] = star[i];
		
		// 삼각형 그리기
		// 1번 줄
		star[1] = "";
		for (int i = 2; i < n; ++i)
			star[1] += " ";
		star[1] += "*";
		/*for (int i = 2; i < n; ++i)
			star[1] += " ";*/

		// 복사 구간 전줄
		for (int i = 2; i < n_1; ++i) {
			star[i] = "";
			for (int j = i; j < n - 1; ++j)
				star[i] += " ";
			star[i] += "*";
			for (int j = 1; j < (i - 1) * 2; ++j)
				star[i] += " ";
			star[i] += "*";
			//for (int j = i; j < n - 1; ++j)
			//	star[i] += " ";
		}
		// 복사 구간 줄
		for (int i = n_1; i < n - 1; ++i) {
			// 앞에다 이어 붙이기
			for (int j = n - i + n_1; j < n; ++j)
				star[i] = " " + star[i];
			star[i] = "*" + star[i];
			for (int j = i; j < n - 1; ++j)
				star[i] = " " + star[i];

			// 뒤에다 이어 붙이기
			for (int j = n - i + n_1; j < n; ++j)
				star[i] += " ";
			for (int j = n - i + n_1; j < n; ++j)
				star[i] += " ";
			star[i] += "*";
			//for (int j = i; j < n - 1; ++j)
			//	star[i] += " ";
		}
		// 마지막 줄
		star[n - 1] = "";
		for (int i = 0; i < (n - 1) * 2 - 1; ++i)
			star[n - 1] += "*";
	}
	else {
		// 복사하기
		for (int i = n_1 - 1; i != 0 ; --i)
			star[i + 1] = star[i];
		// 삼각형 그리기
		// 1번 줄
		star[1] = "";
		for (int i = 0; i < (n - 1) * 2 - 1; ++i)
			star[1] += "*";
		// 복사 구간 줄
		for (int i = 2; i <= n_1; ++i) {
			// 앞에다 이어 붙이기
			for (int j = i; j < n_1; ++j)
				star[i] = " " + star[i];
			star[i] = "*" + star[i];
			for (int j = n_1 - i; j < n_1 - 1; ++j)
				star[i] = " " + star[i];

			// 뒤에다 이어 붙이기
			for (int j = i; j < n_1; ++j)
				star[i] += " ";
			for (int j = i; j < n_1; ++j)
				star[i] += " ";
			star[i] += "*";
			//for (int j = n_1 - i; j < n_1 - 1; ++j)
			//	star[i] += " ";
		}

		// 복사 구간 후줄
		for (int i = n_1 + 1; i < n - 1; ++i) {
			star[i] = "";
			for (int j = n - i; j < n - 1; ++j)
				star[i] += " ";
			star[i] += "*";
			for (int j = 1; j < (n - i - 1) * 2; ++j)
				star[i] += " ";
			star[i] += "*";
			//for (int j = n - i; j < n - 1; ++j)
			//	star[i] += " ";
		}
		// 마지막 줄
		star[n - 1] = "";
		for (int i = 1; i < n - 1; ++i)
			star[n - 1] += " ";
		star[n - 1] += "*";
		//for (int i = 1; i < n - 1; ++i)
		//	star[n - 1] += " ";
	}
	// 일단은 재귀로 짜지만 반복문으로 짜보기
	if (n == N)
		return;
	else
		starMaker(n << 1);
}
/*
1
1

2
3

3
7

4
15

*****************************
 *            *            *
  *          * *          *
   *        *   *        *
    *      *******      *
     *    *  ***  *    *
      *  *    *    *  *
       ***************
        *           *
         *         *
          *       *
           *     *
            *   *
             * *
              *


*/