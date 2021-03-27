#include <iostream>

using namespace std;

int main()
{
	/*ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/

	int n;
	long long counter = 0;

	cin >> n;
	int* candies = new int[n];

	//int dpSize = n + 1;
	//bool* isOdd = new bool[n];
	//int* dp = new int[dpSize];

	for (int i = 0; i < n; i++) {
		//int num;
		//cin >> num;
		cin >> candies[i];

		//isOdd[i] = num % 2;
	}

	//dp[0] = 0;
	//cout << dp[0] << " ";
	//for (int i = 1; i < dpSize; i++) {
	//	dp[i] = dp[i - 1] + isOdd[i - 1];
	//	//dp[i] = dp[i - 1] + candies[i - 1];
	//	cout << dp[i] << " ";
	//}
	//cout << endl;

	int even = 1;
	int odd = 0;
	long long sum = 0;

	for (int i = 0; i < n; i++) {
		sum += candies[i];

		if (sum % 2 == 0) {
			counter += even;
			even++;
		}
		else {
			counter += odd;
			odd++;
		}

		//cout << even << " " << odd << " " << counter << endl;
	}

	/*for (int left = 1; left < dpSize; left++) {
		if (dp[left] % 2 == 0) {
			counter++;
		}
		for (int right = left + 1; right < dpSize; right++) {
			if ((dp[left] + dp[right]) % 2 == 0) {
				counter++;
			}
		}
	}*/

	cout << counter << endl;

	//delete[] isOdd;
	//delete[] dp;

	delete[] candies;
}