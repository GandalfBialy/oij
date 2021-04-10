#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int maxLength;

	cin >> n;

	if (n < 4) {
		cout << 0 << endl;
	}
	else {
		vector<int> lengths(n);

		for (int i = 0; i < n; i++) {
			cin >> lengths[i];
		}

		sort(lengths.begin(), lengths.end(), greater<int>());
		cout << ((long long)(lengths[3]) * (long long)(lengths[3])) << endl;
	}
}