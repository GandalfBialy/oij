#include <iostream>

using namespace std;

void drawHeart() {
    cout << " @@@   @@@\n";
    cout << "@   @ @   @\n";
    cout << "@    @    @\n";
    cout << "@         @\n";
    cout << " @       @\n";
    cout << "  @     @\n";
    cout << "   @   @\n";
    cout << "    @ @\n";
    cout << "     @\n";
}

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        drawHeart();
    }
}