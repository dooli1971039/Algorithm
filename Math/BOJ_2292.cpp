#include <iostream>
using namespace std;

/**
 * n= 1 -> 1
 * n= 2~7 -> 2  (6개)
 * n= 8~19 -> 3 (12개)
 * n= 20~28 -> 4(18개)
 */

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    int layer = 0;
    for (int sum = 2; sum <= n; layer++) {
        sum += (6 * layer);
    }
    cout << layer;
}