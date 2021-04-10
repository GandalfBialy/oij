#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long sum = 0;

	cin >> n;

	vector<int> exceededSpeed(n);
	vector<int> policemanCode(n);

	for (int i = 0; i < n; i++) {
		cin >> exceededSpeed[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> policemanCode[i];
	}

	sort(exceededSpeed.begin(), exceededSpeed.end());
	sort(policemanCode.begin(), policemanCode.end(), greater<int>());

	for (int i = 0; i < n; i++) {
		sum += stoll(to_string(exceededSpeed[i]) + to_string(policemanCode[i]));
	}

	cout << sum << endl;
}