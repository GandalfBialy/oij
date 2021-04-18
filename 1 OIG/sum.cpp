#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int n;

int const maxDigitsNumber = 100;
int leftDigitsPositive[maxDigitsNumber]{};
int rightDigitsPositive[maxDigitsNumber]{};
int leftDigitsNegative[maxDigitsNumber]{};
int rightDigitsNegative[maxDigitsNumber]{};

int transitionPositive = 0;
int transitionNegative = 0;

string positiveSum = "";
string negativeSum = "";

string answer = "";
bool isSumNegative = false;
int answerDigitsLeft[maxDigitsNumber]{};
int answerDigitsRight[maxDigitsNumber]{};


void addIntegral(string num, int arr[]) {
    int sumDigitsIndex = maxDigitsNumber - 1;
    for (int i = num.length() - 1; i >= 0; i--) {
        int digitInteger = num[i] - '0';
        arr[sumDigitsIndex] += digitInteger;

        int tempDigitIndex = sumDigitsIndex;
        while (arr[tempDigitIndex] >= 10) {
            arr[tempDigitIndex] -= 10;
            arr[--tempDigitIndex]++;
        }
        sumDigitsIndex--;
    }
}

void addFloatingPoint(string num, int arr[], int &transition) {
    for (int i = 0; i < num.length(); i++) {
        int digitInteger = num[i] - '0';
        arr[i] += digitInteger;

        int tempDigitIndex = i;
        if (i > 0) {
            while (arr[tempDigitIndex] >= 10) {
                arr[tempDigitIndex] -= 10;
                arr[--tempDigitIndex]++;

                if (tempDigitIndex == 0 and arr[tempDigitIndex] >= 10) {
                    arr[tempDigitIndex] -= 10;
                    transition++;
                    break;
                }
            }
        }
        else if (arr[0] >= 10) {
            arr[0] -= 10;
            transition++;
        }
    }
}

void substractSmallerFromLarger(int largerLeft[], int smallerLeft[], int largerRight[], int smallerRight[]) {
    for (int i = 0; i < maxDigitsNumber; i++) {
        answerDigitsLeft[i] = largerLeft[i] - smallerLeft[i];
        answerDigitsRight[i] = largerRight[i] - smallerRight[i];
    }

    for (int i = maxDigitsNumber - 1; i > 0; i--) {
        if (answerDigitsRight[i] < 0) {
            answerDigitsRight[i] += 10;
            answerDigitsRight[i - 1]--;
        }
    }
    if (answerDigitsRight[0] < 0) {
        answerDigitsRight[0] += 10;
        answerDigitsLeft[maxDigitsNumber - 1]--;
    }

    for (int i = maxDigitsNumber - 1; i > 0; i--) {
        if (answerDigitsLeft[i] < 0) {
            answerDigitsLeft[i] += 10;
            answerDigitsLeft[i - 1]--;
        }
    }
}


int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        string num, left, right;
        bool isNegative = false;
        cin >> num;

        if (num[0] == '-') {
            isNegative = true;
            num.erase(0, 1);
        }
        else if (num[0] == '+') {
            num.erase(0, 1);
        }

        size_t pos = num.find(',');
        if (pos != string::npos) {
            left = num.substr(0, pos);
            right = num.substr(pos + 1, 100);
            //cerr << num << " " << left << " " << right << endl;

            if (not isNegative) {
                addIntegral(left, leftDigitsPositive);
                addFloatingPoint(right, rightDigitsPositive, transitionPositive);
            }
            else {
                addIntegral(left, leftDigitsNegative);
                addFloatingPoint(right, rightDigitsNegative, transitionNegative);
            }
        }
        else {
            //cerr << "! " << num << endl;

            if (not isNegative) {
                addIntegral(num, leftDigitsPositive);
            }
            else {
                addIntegral(num, leftDigitsNegative);
            }
        }
    }

    addIntegral(to_string(transitionPositive), leftDigitsPositive);
    addIntegral(to_string(transitionNegative), leftDigitsNegative);

    for (auto digit : leftDigitsPositive) {
        positiveSum += to_string(digit);
    }
    positiveSum += ",";
    for (auto digit : rightDigitsPositive) {
        positiveSum += to_string(digit);
    }
    //cerr << transitionPositive << endl;

    for (auto digit : leftDigitsNegative) {
        negativeSum += to_string(digit);
    }
    negativeSum += ",";
    for (auto digit : rightDigitsNegative) {
        negativeSum += to_string(digit);
    }
    //cerr << transitionNegative << endl << endl;

    //cerr << positiveSum << endl << negativeSum << endl << endl;

    auto compareResult = positiveSum.compare(negativeSum);
   // cerr << positiveSum.compare(negativeSum) << endl;
    //cerr << negativeSum.compare(positiveSum) << endl << endl;

    if (compareResult == 0) {
        answer = "0";
    }
    else if (compareResult > 0) {
        // (I) - (II) > 0
        substractSmallerFromLarger(leftDigitsPositive, leftDigitsNegative, rightDigitsPositive, rightDigitsNegative);
    }
    else {
        // (I) - (II) < 0 --> (II) - (I) > 0
        // return (minus)((II) - (I))
        isSumNegative = true;
        substractSmallerFromLarger(leftDigitsNegative, leftDigitsPositive, rightDigitsNegative, rightDigitsPositive);
    }

    bool prefixZeros = true;
    for (int i = 0; i < maxDigitsNumber; i++) {
        if (not prefixZeros) {
            answer += to_string(answerDigitsLeft[i]);
        }
        else if (prefixZeros and answerDigitsLeft[i] != 0) {
            prefixZeros = false;
            answer += to_string(answerDigitsLeft[i]);
        }
    }

    answer += ",";

    string rightReversed = "";
    prefixZeros = true;
    for (int i = maxDigitsNumber - 1; i >= 0; i--) {
        if (not prefixZeros) {
            rightReversed += to_string(answerDigitsRight[i]);
        }
        else if (prefixZeros and answerDigitsRight[i] != 0) {
            prefixZeros = false;
            rightReversed += to_string(answerDigitsRight[i]);
        }
    }
    reverse(rightReversed.begin(), rightReversed.end());
    answer += rightReversed;

    if (answer[0] == ',') {
        answer = "0" + answer;
    }
    if (answer[answer.length() - 1] == ',') {
        answer.erase(answer.length() - 1, 1);
    }

    if (isSumNegative) {
        cout << "-" << answer;
    }
    else {
        cout << answer;
    }
    cout << endl;
}