#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int result_x, result_y;

    if (x1 == x2) {
        result_x = x3;
    } else if (x1 == x3) {
        result_x = x2;
    } else {
        result_x = x1;
    }

    if (y1 == y2) {
        result_y = y3;
    } else if (y1 == y3) {
        result_y = y2;
    } else {
        result_y = y1;
    }

    cout << result_x << ' ' << result_y;
}