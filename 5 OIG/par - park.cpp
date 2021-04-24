#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int maxRight = 0;
	int maxLeft = 0;

	cin >> n;
	vector<int> nums(n);
	vector<int> maxLeftNums(n);
	vector<int> maxRightNums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < n; i++) {
		if (maxLeft < nums[i]) {
			maxLeft = nums[i];
		}

		maxLeftNums[i] = maxLeft;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (maxRight < nums[i]) {
			maxRight = nums[i];
		}

		maxRightNums[i] = maxRight;
	}

	for (int i = 0; i < n; i++) {
		cout << maxLeftNums[i] << " " << maxRightNums[i] << "\n";
	}
}