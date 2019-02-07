/// 16506.CPU

#include <iostream>
#include <map>
#include <string>

#define endl '\n'

using namespace std;

map <string, int> opcode;
string opcodeList[] = {
	"ADD", "SUB", "MOV", "AND", "OR", "NOT", "MULT", "LSFTL", "LSFTR", "ASFTR", "RL", "RR"
};

string int2binary(int x, int c) {
	string ret = "";
	while (c--) {
		ret = ((x % 2) ? "1" : "0") + ret;
		x >>= 1;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 12; i++) {
		opcode[opcodeList[i]] = i * 2;
		opcode[opcodeList[i] + "C"] = i * 2 + 1;
	}

	int n;
	cin >> n;
	while (n--) {
		string assembler;
		int rd, ra, rb, cs;
		cin >> assembler >> rd >> ra >> rb;
		if (opcode[assembler] % 2 == 0)
			rb <<= 1;
		cout << int2binary(opcode[assembler], 5);
		cout << 0;
		cout << int2binary(rd, 3);
		cout << int2binary(ra, 3);
		cout << int2binary(rb, 4);
		cout << endl;
	}	
}