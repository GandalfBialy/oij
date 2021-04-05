#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string word;
    string output = "";
    cin >> word;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] == 'a') output += "4";
        else if (word[i] == 'e') output += "3";
        else if (word[i] == 'i') output += "1";
        else if (word[i] == 'o') output += "0";
        else if (word[i] == 's') output += "5";
        else output += word[i];
    }

    cout << output;
}