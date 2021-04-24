#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int length;
    cin >> length;
    int* heights = new int[length];

    for (int i = 0; i < length; i++) {
        cin >> heights[i];
    }

    int maxLeft = heights[0];
    int maxRight = *max_element(heights, heights + length);

    for (int i = 0; i < length; i++) {
        if (maxLeft < heights[i]) {
            maxLeft = heights[i];
        }
        if (maxRight == heights[i] || maxRight == heights[i - 1]) {
            maxRight = *max_element(heights + i, heights + length);
        }

        cout << maxLeft << " " << maxRight << endl;
    }
}