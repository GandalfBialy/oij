#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	string str;
	int maxCounter = 0;

	cin >> str;
	int length = str.length();

	int i = 0;

	int previousConvertedPluses = 0;
	while (i < length) {
		int currentMinuses = 0;
		int currentPluses = 0;

		while (i < length and str[i] == '+') {
			currentPluses++;
			i++;
		}

		while (i < length and str[i] == '-') {
			currentMinuses++;
			i++;
		}

		maxCounter = max(maxCounter, currentPluses + (currentMinuses / 2) + previousConvertedPluses);

		if (currentMinuses % 2 == 1) {
			previousConvertedPluses = currentMinuses / 2;
		}
		else {
			previousConvertedPluses += (currentMinuses / 2) + currentPluses;
		}

		//cerr << "[" << i << "]" << "\t" << currentCounter << " " << maxCounter << endl;
	}

	cout << maxCounter << endl;
}