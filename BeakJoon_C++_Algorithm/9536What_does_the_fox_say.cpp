// 9536What_does_the_fox_say

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	string mix;
	cin >> t;
	getline(cin, mix);
	while (t--) {
		// get all
		vector<string> sound;
		vector<bool> fox;
		getline(cin, mix);
		mix = mix + ' ';
		int startIndex = 0, endIndex;
		for (int i = 0; i < mix.length(); i++) {
			if (mix[i] == ' ') {
				endIndex = i - startIndex;
				sound.push_back(mix.substr(startIndex, endIndex));
				fox.push_back(true);
				startIndex += endIndex + 1;
			}
		}

		// get animal
		vector<string> animal;
		while (true) {
			string line;
			string say;
			getline(cin, line);
			if (line == "what does the fox say?")
				break;
			line += ' ';
			startIndex = 0;
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ' ') {
					endIndex = i - startIndex;
					say = line.substr(startIndex, endIndex);
					startIndex += endIndex + 1;
				}
			}
			animal.push_back(say);
		}
		// remove
		for (int i = 0; i < sound.size(); i++) {
			for (int j = 0; j < animal.size(); j++) {
				if (sound[i] == animal[j]) {
					fox[i] = false;
					break;
				}
			}
		}

		// print
		for (int i = 0; i < sound.size(); i++)
			if (fox[i])
				cout << sound[i] << " ";
		cout << '\n';
	}

}