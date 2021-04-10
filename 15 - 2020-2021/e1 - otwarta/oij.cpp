#include <iostream>

using namespace std;

int main()
{
    int answer = 0;
    string s;
    cin >> s;

    bool oL = 0, iL = 0, jL = 0; // letters

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'o') oL = true;
        else if (oL && s[i] == 'i') iL = true;
        else if (oL && iL && s[i] == 'j') {
            jL = true;

            if (oL && iL && jL) {
                answer++;
                oL = false;
                iL = false;
                jL = false;
            }
        }
    }

    if (answer) cout << answer;
    else cout << "NIE";
}