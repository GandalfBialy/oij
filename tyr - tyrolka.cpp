#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	double minRatio = 200'001;
	int minRatioCoord1 = -1;
	int minRatioCoord2 = -1;

	cin >> n;

	vector<pair<int, int>> coords(n);

	for (int i = 0; i < n; i++) {
		cin >> coords[i].second >> coords[i].first;
	}

	sort(coords.begin(), coords.end());

	cout << endl;
	for (auto coord : coords) {
		cout << coord.second << " " << coord.first << endl;
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				double ratio = (double)(abs(coords[i].second - coords[j].second)) / (double)(abs(coords[i].first - coords[j].first));
				if (ratio != 0 and ratio < minRatio) {
					minRatio = ratio;
					minRatioCoord1 = i + 1;
					minRatioCoord2 = j + 1;
				}
			}
		}
	}

	cerr << minRatio << endl;
	cout << minRatioCoord1 << " " << minRatioCoord2 << endl;*/
}