#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int buttonsQuantity, actionsQuantity;
	int lastButton;
	int maxValue = 0;
	int	maxValueWhenLastButtonPushed = 0;

	cin >> buttonsQuantity >> actionsQuantity;
	vector<int> buttons(buttonsQuantity, 0);
	lastButton = buttonsQuantity + 1;

	for (int i = 0; i < actionsQuantity; i++) {
		int pushedButton;
		cin >> pushedButton;

		if (pushedButton == lastButton) {
			maxValueWhenLastButtonPushed = maxValue;
		}
		else {
			int buttonIndex = pushedButton - 1;
			buttons[buttonIndex] = max(buttons[buttonIndex], maxValueWhenLastButtonPushed);
			buttons[buttonIndex]++;

			maxValue = max(maxValue, buttons[buttonIndex]);
		}
	}

	for (auto it = buttons.begin(); it != buttons.end(); it++) {
		*it = max(*it, maxValueWhenLastButtonPushed);
	}

	for (auto value : buttons) {
		cout << value << " ";
	}
	cout << endl;
}