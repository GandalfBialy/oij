#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;

    long double sum = 0;

    for (int i = 0; i < n; i++) {
        string line;

        cin >> line;

        if (line.find(',') != string::npos) {
            line.replace(line.find(","), 1, ".");
        }

        sum += stold(line);
    }

    //cout << endl << sum << " ";
    string answer = to_string(sum);
    //cout << answer << " ";
    answer.replace(answer.find("."), 1, ",");
    //cout << answer << " ";

    if (answer[0] != '0') {
        for (int i = answer.size() - 1; i >= 0; i--) {
            if (answer[i] == '0' || answer[i] == ',') {
                answer.erase(i, 1);
            }
            else {
                break;
            }
        }

        cout << answer;
    }
    else {
        cout << "0,0";
    }
}