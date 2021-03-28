#include <iostream>
#include <algorithm>

using namespace std;

int const N = 3;

int main()
{
    int t[N];
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    sort(t, t + N);

    int zeros = 0;

    int i = 0;
    while (t[i] == 0) {
        zeros++;
        i++;
    }
    cout << t[i];
    i++;

    for (int i = 0; i < zeros; i++) {
        cout << 0;
    }

    for (i; i < N; i++) {
        cout << t[i];
    }
}