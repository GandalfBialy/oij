#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    string sequence[] = { "2", "4", "8", "16", "14", "10" };

    long long n;
    string number;
    cin >> n >> number;

    int sum = 10;

    while (sum > 9 && n > 1 && sum != 18) {
        sum = 0;
        int length = number.length();

        for (int j = 0; j < length; j++) {
            sum += (number[j] - '0');
        }

        sum *= 2;
        number = to_string(sum);

        n--;
        //cout << sum << " " << number << endl;
    }

    long long leftN = n - 1;

    //cout << "num: " << number << endl;
    //cout << leftN << " " << leftN % 6 << " " << sequence[leftN % 6]<< endl << endl;

    if (leftN) {
        if (number == "1") {
            cout << sequence[(leftN - 1) % 6];
        }
        else if (number == "2") {
            cout << sequence[leftN % 6];
        }
        else if (number == "4") {
            cout << sequence[(leftN + 1) % 6];
        }
        else if (number == "5") {
            cout << sequence[(leftN + 4) % 6];
        }
        else if (number == "7") {
            cout << sequence[(leftN + 3) % 6];
        }
        else if (number == "8") {
            cout << sequence[(leftN + 2) % 6];
        }

        else if (number == "3" || number == "6") {
            if (leftN % 2 == 0) cout << "6";
            else cout << "12";
        }

        else if (number == "9" || number == "18") {
            cout << "18";
        }
    }
    else {
        cout << number;
    }
}