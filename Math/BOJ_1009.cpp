#include <iostream>
using namespace std;

int main() {
    int t, a, b;
    cin >> t;

    while (t--) {
        cin >> a >> b;
        int num = 1;
        for (int i = 0; i < b; i++) {
            num = num * a % 10;
            if (num == 0) {
                num = 10;
            }
        }
        cout << num << '\n';
    }
}