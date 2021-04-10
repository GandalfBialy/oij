#include <iostream>

using namespace std;

int main()
{
    string word;
    int length, counter = 0;

    cin >> word;
    length = word.length();

    for (int i = 1; i < length; i++)
        if (word[i - 1] == word[i])
            counter++;

    cout << counter << endl;
}