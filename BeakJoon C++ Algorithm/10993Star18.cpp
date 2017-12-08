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
		// �����ϱ�
		for (int i = n_1 - 1; i != 0; --i)
			star[i + n_1 - 1] = star[i];
		
		// �ﰢ�� �׸���
		// 1�� ��
		star[1] = "";
		for (int i = 2; i < n; ++i)
			star[1] += " ";
		star[1] += "*";
		/*for (int i = 2; i < n; ++i)
			star[1] += " ";*/

		// ���� ���� ����
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
		// ���� ���� ��
		for (int i = n_1; i < n - 1; ++i) {
			// �տ��� �̾� ���̱�
			for (int j = n - i + n_1; j < n; ++j)
				star[i] = " " + star[i];
			star[i] = "*" + star[i];
			for (int j = i; j < n - 1; ++j)
				star[i] = " " + star[i];

			// �ڿ��� �̾� ���̱�
			for (int j = n - i + n_1; j < n; ++j)
				star[i] += " ";
			for (int j = n - i + n_1; j < n; ++j)
				star[i] += " ";
			star[i] += "*";
			//for (int j = i; j < n - 1; ++j)
			//	star[i] += " ";
		}
		// ������ ��
		star[n - 1] = "";
		for (int i = 0; i < (n - 1) * 2 - 1; ++i)
			star[n - 1] += "*";
	}
	else {
		// �����ϱ�
		for (int i = n_1 - 1; i != 0 ; --i)
			star[i + 1] = star[i];
		// �ﰢ�� �׸���
		// 1�� ��
		star[1] = "";
		for (int i = 0; i < (n - 1) * 2 - 1; ++i)
			star[1] += "*";
		// ���� ���� ��
		for (int i = 2; i <= n_1; ++i) {
			// �տ��� �̾� ���̱�
			for (int j = i; j < n_1; ++j)
				star[i] = " " + star[i];
			star[i] = "*" + star[i];
			for (int j = n_1 - i; j < n_1 - 1; ++j)
				star[i] = " " + star[i];

			// �ڿ��� �̾� ���̱�
			for (int j = i; j < n_1; ++j)
				star[i] += " ";
			for (int j = i; j < n_1; ++j)
				star[i] += " ";
			star[i] += "*";
			//for (int j = n_1 - i; j < n_1 - 1; ++j)
			//	star[i] += " ";
		}

		// ���� ���� ����
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
		// ������ ��
		star[n - 1] = "";
		for (int i = 1; i < n - 1; ++i)
			star[n - 1] += " ";
		star[n - 1] += "*";
		//for (int i = 1; i < n - 1; ++i)
		//	star[n - 1] += " ";
	}
	// �ϴ��� ��ͷ� ¥���� �ݺ������� ¥����
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