#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    int letters[2][26]{}; // letters[0] -> small; letters[1] -> big
    string line;

    cin >> n;
    getline(cin, line);

    for (int i = 0; i < n; i++) {
        getline(cin, line);

        for (int j = 0; j < line.length(); j++) {
            if (line[j] >= 'a' and line[j] <= 'z') {
                letters[0][(int)line[j] - 97]++;
            }
            else if (line[j] >= 'A' and line[j] <= 'Z') {
                letters[1][(int)line[j] - 65]++;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (letters[0][i] != 0) {
            cout << (char)(i + 97) << " " << letters[0][i] << endl;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (letters[1][i] != 0) {
            cout << (char)(i + 65) << " " << letters[1][i] << endl;
        }
    }
}