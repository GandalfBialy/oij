#include <iostream>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

bool isPrime(long long num) {
	if (num < 2) return false;
	else if (num == 2) return true;
	else {
		for (int i = 2; i < (int)(sqrt(num)) + 1; i++) {
			if (num % i == 0) {
				return false;
			}
		}
	}

	return true;
}

int main()
{
	queue<int> shortablePrimesQueue;
	shortablePrimesQueue.push(2);
	shortablePrimesQueue.push(3);
	shortablePrimesQueue.push(5);
	shortablePrimesQueue.push(7);

	set<int> shortablePrimes = { 2, 3, 5, 7 };

	string minValue, maxValue;
	int counter = 0;
	int const MAX_INT = 1000000000;
	int maxIter, minIter;

	cin >> minValue >> maxValue;

	while (not shortablePrimesQueue.empty()) {
		int num = shortablePrimesQueue.front();
		shortablePrimesQueue.pop();

		long long modifiedNum = num * 10 + 1;
		if (isPrime(modifiedNum)) {
			shortablePrimes.insert(modifiedNum);
			shortablePrimesQueue.push(modifiedNum);
		}

		modifiedNum = num * 10 + 3;
		if (isPrime(modifiedNum)) {
			shortablePrimes.insert(modifiedNum);
			shortablePrimesQueue.push(modifiedNum);
		}

		modifiedNum = num * 10 + 7;
		if (isPrime(modifiedNum)) {
			shortablePrimes.insert(modifiedNum);
			shortablePrimesQueue.push(modifiedNum);
		}

		modifiedNum = num * 10 + 9;
		if (isPrime(modifiedNum)) {
			shortablePrimes.insert(modifiedNum);
			shortablePrimesQueue.push(modifiedNum);
		}
	}

	/*for (auto num : shortablePrimes) {
		cout << num << endl;
	}*/

	if (minValue.length() >= 10) {
		cout << 0 << endl;
		return 0;
	}
	else if (minValue.length() < 10 and maxValue.length() >= 10) {
		minIter = stoi(minValue);
		maxIter = MAX_INT;
	}
	else {
		minIter = stoi(minValue);
		maxIter = stoi(maxValue);
	}

	for (auto num : shortablePrimes) {
		if (num >= minIter and num <= maxIter) counter++;
	}

	cout << counter << endl;
}