#include <iostream>

using namespace std;

int main()
{
	int n;
	int counter = 1;
	int lastDistance, currentDistance;
	bool nonDrecreasing = true;

	cin >> n;

	cin >> lastDistance;
	for (int i = 1; i < n; i++) {
		cin >> currentDistance;

		if (nonDrecreasing and currentDistance < lastDistance) {
			nonDrecreasing = false;
			counter++;
		}
		else if (!nonDrecreasing and currentDistance > lastDistance) {
			nonDrecreasing = true;
			counter++;
		}

		lastDistance = currentDistance;
	}

	cout << counter << endl;
}