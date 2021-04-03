#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void invalidData() {
    cout << "NIE" << endl;
    exit(0);
}

int main()
{
    int const BRACKETS_QUANTITY = 3;

    int length;
    string code;

    int bracketsCounter[BRACKETS_QUANTITY][2];
    char bracketsTypes[BRACKETS_QUANTITY][2] = {
        { '(', ')' },
        { '[', ']' },
        { '{', '}' },
    };

    stack<char> wantedBrackets;
    int maxDepth = 0;

    cin >> length >> code;

    if (length % 2 == 1) {
        invalidData();
    }

    for (int i = 0; i < BRACKETS_QUANTITY; i++) {
        for (int j = 0; j < 2; j++) {
            bracketsCounter[i][j] = count(code.begin(), code.end(), bracketsTypes[i][j]);
        }

        if (bracketsCounter[i][0] != bracketsCounter[i][1]) {
            invalidData();
        }
    }

    for (char c : code) {
        if (c == '(' or c == '[' or c == '{') {
            wantedBrackets.push(c);
            if (wantedBrackets.size() > maxDepth) {
                maxDepth = wantedBrackets.size();
            }
        }
        else {
            if (wantedBrackets.size() > 0) {
                char wanted = wantedBrackets.top();
                if ((c == ')' and wanted == '(') or (c == ']' and wanted == '[') or (c == '}' and wanted == '{')) {
                    wantedBrackets.pop();
                }
                else {
                    invalidData();
                }
            }
            else {
                invalidData();
            }
        }
    }

    if (wantedBrackets.size() != 0) {
        invalidData();
    }
    else {
        cout << maxDepth << endl;
    }
}