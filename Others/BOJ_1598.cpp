#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int x1 = (a % 4) ? a / 4 + 1 : a / 4;
    int x2 = (b % 4) ? b / 4 + 1 : b / 4;
    int y1 = (a % 4) ? a % 4 : 4;
    int y2 = (b % 4) ? b % 4 : 4;

    int xx = ((x1 - x2) > 0) ? x1 - x2 : x2 - x1;
    int yy = ((y1 - y2) > 0) ? y1 - y2 : y2 - y1;

    cout << xx + yy;
}