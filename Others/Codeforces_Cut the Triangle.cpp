#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int checkOrder(int a, int b, int c) {
    if (a == b || b == c || c == a)
        return -1;
    else if (a < b && b < c)
        return b;
    else if (b < a && a < c)
        return a;
    else
        return c;
}

void solution() {
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int row = checkOrder(x1, x2, x3);
    int column = checkOrder(y1, y2, y3);
    if (row == -1 && column == -1)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        solution();
    }
}