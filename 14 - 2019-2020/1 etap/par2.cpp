#include <iostream>
#include <string>

using namespace std;

bool isEvenDigit(string num) {
    int length = num.length();

    if (num == "0") {
        return false;
    }
    else {
        for (char digit : num) {
            if (digit != '0' and digit != '2' and digit != '4' and digit != '6' and digit != '8') {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    long long n;
    long long counter = 0;
    long long num = 2;

    cin >> n;

    while (counter < n) {
        if (isEvenDigit(to_string(num))) {
            counter++;
            num += 2;
        }
        else {
            num += 2;
        }
    }
    num -= 2;

    cout << num;
}