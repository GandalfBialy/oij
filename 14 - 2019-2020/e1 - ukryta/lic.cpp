#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long MAX_NUM = 5000000000;

int digitsSum(string num) {
	int length = num.length();
	int sum = 0;

	for (int i = 0; i < length; i++) {
		sum += num[i] - '0';
	}

	return sum;
}

long long functionG(string num) {
	int digitsSumValue = digitsSum(num);

	long long result = stoll(num) + digitsSumValue * digitsSumValue;

	return result;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<long long, int>> nums(n);
	vector<bool> isValid(n, 0);

	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;

		nums[i] = make_pair(num, i);
	}

	sort(nums.begin(), nums.end());

	long long functionResult = 1;
	int numsIndex = 0;
	while (functionResult <= MAX_NUM) {
		while (numsIndex < n and nums[numsIndex].first < functionResult) {
			numsIndex++;
		}
		while (numsIndex < n and nums[numsIndex].first == functionResult) {
			isValid[nums[numsIndex].second] = true;
			numsIndex++;
		}
		functionResult = functionG(to_string(functionResult));

	}

	for (bool answer : isValid) {
		if (answer) {
			cout << "TAK\n";
		}
		else {
			cout << "NIE\n";
		}
	}
}