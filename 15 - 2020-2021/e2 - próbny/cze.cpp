#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	long long A, B;
	long long C, D;
	long long wantedSurface;
	long long maxSurface;

	/*
	x * y == C * D
	A <= B
	x >= y

	1 <= x <= B
	1 <= y <= A

	y = (C * D) / x
	*/

	cin >> A >> B >> C >> D;

	if (A > B) {
		long long temp = A;
		A = B;
		B = temp;
	}

	wantedSurface = C * D;
	maxSurface = A * B;

	vector<long long> cDivs;
	vector<long long> dDivs;
	vector<long long> everyDivs;

	for (int i = 1; i <= sqrt(C) and i <= A; i++) {
		if (C % i == 0) {
			cDivs.push_back(i);
			cDivs.push_back(C / i);
		}
	}

	for (int i = 1; i <= sqrt(D) and i <= A; i++) {
		if (D % i == 0) {
			dDivs.push_back(i);
			dDivs.push_back(D / i);
		}
	}

	for (auto cDiv : cDivs) {
		for (auto dDiv : dDivs) {
			everyDivs.push_back(cDiv * dDiv);
		}
	}

	for (auto div : everyDivs) {
		if (div <= A) {
			long long y = wantedSurface / div;

			if (y <= B and div * y <= maxSurface) {
				cout << "TAK\n";
				return 0;
			}
		}
	}

	cout << "NIE\n";
}