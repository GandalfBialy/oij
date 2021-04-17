#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;

	cin >> n;
	vector<long long> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end(), greater<int>());

	long long maxPossible = nums[0] / 4;

	if (n >= 2) {
		maxPossible = max(maxPossible, min(nums[0] / 3, nums[1]));
		maxPossible = max(maxPossible, nums[1] / 2);
	}

	if (n >= 3) {
		maxPossible = max(maxPossible, min(nums[0] / 2, nums[2]));
	}

	if (n >= 4) {
		maxPossible = max(maxPossible, nums[3]);
	}

	cout << maxPossible * maxPossible << endl;
}