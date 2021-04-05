#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string caesarsCode(string encoded, int shift) {
	int length = encoded.length();
	string decoded = "";

	for (char c : encoded) {
		decoded += (char)((((int)c - 65 + shift) % 26) + 65);
	}

	return decoded;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int length;
	char mostCommonSignInDecoded;
	string encoded;

	map<char, int> charsCounter = {};
	int maxCounter = 0;
	char maxCounterChar;

	int difference;

	cin >> length >> mostCommonSignInDecoded >> encoded;

	for (auto c : encoded) {
		charsCounter[c]++;

		if (charsCounter[c] > maxCounter) {
			maxCounter = charsCounter[c];
			maxCounterChar = c;
		}
	}

	//cout << maxCounterChar << " " << mostCommonSignInDecoded << endl;
	//cout << (int)maxCounterChar << " " << (int)mostCommonSignInDecoded << (int)maxCounterChar - (int)mostCommonSignInDecoded << endl;
	difference = (int)maxCounterChar - (int)mostCommonSignInDecoded;
	if (difference > 0) difference = 26 - difference;
	else difference = -difference;

	cout << caesarsCode(encoded, difference) << endl;
}