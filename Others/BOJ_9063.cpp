#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, min_x, min_y, max_x, max_y;
    cin >> n;
    cin >> min_x >> min_y;
    max_x = min_x;
    max_y = min_y;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        min_x = min(a, min_x);
        max_x = max(a, max_x);
        min_y = min(b, min_y);
        max_y = max(b, max_y);
    }

    cout << (max_y - min_y) * (max_x - min_x);
}