#include <iostream>
#include <string>

using namespace std;

int main()
{
    string answer;
    int h, m, s;
    cin >> h >> m >> s;

    s++;
    if (s >= 60) {
        m++;
        s -= 60;

        if (m >= 60) {
            h++;
            m -= 60;

            if (h >= 24) {
                h = 0;
                m = 0;
                s = 0;
            }
        }
    }

    if (h < 10) answer += "0";
    answer += to_string(h) + ":";

    if (m < 10) answer += "0";
    answer += to_string(m) + ":";

    if (s < 10) answer += "0";
    answer += to_string(s);

    cout << answer;
}