#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

bool sortWords(string a, string b) {
	int aLength = a.length();
	int bLength = b.length();

	if (aLength < bLength) {
		return true;
	}
	else if (a.length() == b.length()) {
		if (a == b) return false;
		else return strcmp(a.c_str(), b.c_str()) < 0;
	}

	return false;
}

int main()
{
	int wordsQuantity;
	vector<string> words;

	cin >> wordsQuantity;

	for (int i = 0; i < wordsQuantity; i++) {
		string word;
		cin >> word;
		
		words.push_back(word);
	}

	sort(words.begin(), words.end(), sortWords);

	for (auto it = words.begin(); it != words.end(); it++) {
		cout << *it << endl;
	}
}