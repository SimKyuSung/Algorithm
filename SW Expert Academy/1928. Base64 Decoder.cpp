/// 1928. Base64 Decoder

#include <iostream>
#include <string>

using namespace std;

int base64[128];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 26; i++)
		base64['A' + i] = i;
	for (int i = 0; i < 26; i++)
		base64['a' + i] = i + 26;
	for (int i = 0; i < 10; i++)
		base64['0' + i] = i + 52;	
	base64['+'] = 62;
	base64['/'] = 63;

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		string encode, decode = "";
		cin >> encode;

		for (int i = 0; i < encode.size() / 4; i++) {
			// 4개 단위로 읽음
			int bitMask = 0;
			for (int j = 0; j < 4; j++) {
				bitMask <<= 6;
				bitMask |= base64[encode[i * 4 + j]];
			}
			// 3개 단위로 쓰기
			for (int j = 0; j < 3; j++)
				decode += (char)(bitMask >> (8 * (2 - j)));
		}

		cout << '#' << t << ' ' << decode << '\n';
	}
}

/*

T		G		l		m		Z		SBpdHNlbGYgaXMgYSBxdW90YXRpb24u
19		6		37		38		
010011	000110	100101	100110	

Lif

*/