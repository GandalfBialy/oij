#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isEvendigitNumber(string num) {
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

long long calculateEvendigitNumber(long long n) {
    long long counter = 0;
    long long num = 2;

    while (counter < n) {
        if (isEvendigitNumber(to_string(num))) {
            counter++;
            num += 2;
        }
        else {
            num += 2;
        }
    }

    //cout << num - 2 << endl;
    return num - 2;
}

int main()
{
    string n;
    //string answer = "";
    int power = 0;
    long long sum = 0;

    cin >> n;
    int length = n.length();

    for (int i = length - 1; i >= 0; i--) {
        long long num = (n[i] - '0') * pow(2, power);
        //cerr << n[i] << " * 2^" << power << " = " << num << " " << "\t";

        sum += calculateEvendigitNumber(num) * pow(10, power);
        //cerr << calculateEvendigitNumber(num) * pow(10, power) << endl;

        power++;
    }

    cout << sum;

    //cerr << endl << endl << calculateEvendigitNumber(4096);
}