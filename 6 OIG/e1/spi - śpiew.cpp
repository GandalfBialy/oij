#include <iostream>

using namespace std;

int main()
{
    int length;
    string seatsStr;
    int neededSeatsCounter = 0;

    cin >> length >> seatsStr;

    int currentCounter = seatsStr[0] == 'W' ? 0 : 1;

    for (int i = 1; i < length; i++) {
        if (seatsStr[i] == 'Z') {
            currentCounter++;
        }
        else {
            while (currentCounter > 0) {
                neededSeatsCounter++;
                currentCounter -= 3;
            }
            currentCounter = 0;
        }
    }
    while (currentCounter > 0) {
        neededSeatsCounter++;
        currentCounter -= 3;
    }

    cout << neededSeatsCounter << endl;
}