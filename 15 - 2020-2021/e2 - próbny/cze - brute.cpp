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

	for (int i = 1; i <= sqrt(wantedSurface) and i <= A; i++) {
	//for (int i = 1; i <= sqrt(wantedSurface); i++) {
		if (wantedSurface % i == 0) {
			long long possibleY = wantedSurface / i;

			cerr << i << " " << possibleY << endl;

			if (possibleY <= B and i * possibleY <= maxSurface) {
				cout << "TAK\n";
				return 0;
			}
		}
	}

	cout << "NIE\n";
}