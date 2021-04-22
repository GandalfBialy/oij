#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, q;

	cin >> n;
	vector<long long> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end(), greater<int>());
	vector<long long> prefixSums(n);

	prefixSums[0] = nums[0];
	for (int i = 1; i < n; i++) {
		prefixSums[i] = prefixSums[i - 1] + nums[i];
	}

	cin >> q;
	vector<pair<long long, int>> queries(q);
	vector<int> answers(q);

	for (int i = 0; i < q; i++) {
		long long num;
		cin >> num;
		
		queries[i] = make_pair(num, i);
	}

	sort(queries.begin(), queries.end());

	int sumsIndex = 0;
	for (int i = 0; i < q; i++) {
		while (sumsIndex < n and prefixSums[sumsIndex] < queries[i].first) {
			sumsIndex++;
		}
		answers[queries[i].second] = sumsIndex + 1;
	}

	for (int answer : answers) {
		cout << answer << "\n";
	}
}