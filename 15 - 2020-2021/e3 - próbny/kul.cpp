#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long cost = 0;

    vector<bool> balls[2];

    for (int i = 0; i < 2; i++) {
        balls[i].reserve(n);

        string str;
        cin >> str;
        int strLength = str.length();

        for (int j = 0; j < strLength; j++) {
            if (str[j] == 'B') balls[i].push_back(1);
            else balls[i].push_back(0);
        }
    }

    int topRowWhiteCounter = 0;

    for (int i = 0; i < n; i++) {
        if (balls[0][i]) topRowWhiteCounter++;
    }

    int topBallsToMove = min(topRowWhiteCounter, n - topRowWhiteCounter);
    vector<int> ballsToMoveIndexes;

    if (topRowWhiteCounter >= n / 2) {
        for (int i = 0; i < n; i++) {
            if (balls[0][i]) {
                ballsToMoveIndexes.push_back(i);
            }
            if (balls[1][i]) {
                ballsToMoveIndexes.push_back(i);
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            bool temp = balls[0][i];
            balls[0][i] = balls[1][i];
            balls[1][i] = temp;

            if (balls[0][i]) {
                ballsToMoveIndexes.push_back(i);
            }
            if (balls[1][i]) {
                ballsToMoveIndexes.push_back(i);
            }
        }
    }

    int wantedIndex = 0;

    for (int i = 0; i < ballsToMoveIndexes.size(); i++) {
        cost += abs(wantedIndex - ballsToMoveIndexes[i]);
        wantedIndex++;
    }

    cost += topBallsToMove;

    cout << cost << endl;
}


/*

6
CCCBBB
CCCBBB

5
BBCBB
CCCBC

5
CCBCC
BBBCB

*/