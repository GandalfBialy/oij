#include <iostream>
#include <string>

using namespace std;

int main()
{
	unsigned long long num;
	unsigned long long powerValue = 1;
	int power = 0;
	string evenDigit = "";

	cin >> num;

	while (powerValue <= num) {
		powerValue *= 5;
		power++;
	}
	powerValue /= 5;

	cerr << powerValue << endl;

	for (int i = 0; i < power; i++) {
		int counter = 0;
		while (num >= powerValue) {
			num -= powerValue;
			counter++;
		}
		powerValue /= 5;
		evenDigit += to_string(counter * 2);
		cerr << counter << " " << num << endl;
	}

	cout << evenDigit << endl;
}