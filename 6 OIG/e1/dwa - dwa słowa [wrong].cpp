#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int len, n;
	string str1, str2;
	int diffIndex = -1;
	bool isFirstSmaller;
	bool areEqual = false;
	char currentCode;

	cin >> len >> str1 >> str2 >> n;

	if (str1 == str2) {
		areEqual = true;
	}
	else {
		for (int i = 0; i < len; i++) {
			if (str1[i] != str2[i]) {
				isFirstSmaller = (bool)(str1[i] < str2[i]);
				diffIndex = i;
				break;
			}
		}
	}
	
	if (areEqual) currentCode = '0';
	else if (isFirstSmaller) currentCode = '1';
	else currentCode = '2';

	for (int i = 0; i < n; i++) {
		int index1, index2, smallerIndex;
		cin >> index1 >> index2;

		smallerIndex = index1 < index2 ? index1 : index2;

		char temp = str1[index1];
		str1[index1] = str2[index2];
		str2[index2] = temp;
		//cerr << str1 << " " << str2 << "\t" << "diffIndex: " << diffIndex << endl;

		if (str1[smallerIndex] == str2[smallerIndex]) {
			bool isDiffFound = false;
			for (int i = smallerIndex; i < len; i++) {
				if (str1[i] != str2[i]) {
					isFirstSmaller = (bool)(str1[i] < str2[i]);
					diffIndex = i;
					isDiffFound = true;
					break;
				}
			}

			if (!isDiffFound and str1 == str2) {
				currentCode = '0';
			}
		}
		else if (smallerIndex <= diffIndex) {
			if (str1[smallerIndex] < str2[smallerIndex]) {
				currentCode = '1';
			}
			else if (str1[smallerIndex] > str2[smallerIndex]) {
				currentCode = '2';
			}

			diffIndex = smallerIndex;
		}
		
		cout << currentCode << endl;
	}
}

/*

4
aaab
aaba
2
2 2
3 2

5
aaabb
aabab
5
0 0
1 1
2 2
3 3
4 4

*/