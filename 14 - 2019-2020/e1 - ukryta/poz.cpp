#include <iostream>

using namespace std;

int main()
{
	string heart[9] = {
	" @@@   @@@ ",
	"@   @ @   @",
	"@    @    @",
	"@         @",
	" @       @ ",
	"  @     @  ",
	"   @   @   ",
	"    @ @    ",
	"     @     ",
	};

	int n;

	cin >> n;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < n; j++) {
			cout << heart[i] << " ";
		}
		cout << "\n";
	}
}