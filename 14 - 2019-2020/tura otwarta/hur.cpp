#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 7 == 0) {
			if (i % 11 == 0) {
				cout << "Wiwat!\n";
			}
			else {
				cout << "Hurra!\n";
			}
		}
		else if (i % 11 == 0) {
			cout << "Super!\n";
		}
		else {
			cout << i << "\n";
		}
	}
}