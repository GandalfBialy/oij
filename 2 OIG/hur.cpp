#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	map<char, long long> cargo;
	map<char, bool> didAppear;

	for (int i = 0; i < 26; i++) {
		char c = (char)(i + 65);

		cargo[c] = 0;
		didAppear[c] = false;
	}

	cin >> n;

	for (int i = 0; i < n; i++) {
		char c;
		int num;

		cin >> c >> num;

		cargo[c] += num;
		didAppear[c] = true;
	}

	for (int i = 0; i < 26; i++) {
		char c = (char)(i + 65);

		if (didAppear[c]) cout << c << " " << cargo[c] << "\n";
	}
}