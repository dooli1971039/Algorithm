#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;

    if (b + c >= 60) {
        if (a + (b + c) / 60 >= 24) {
            cout << a + (b + c) / 60 - 24 << ' ' << (b + c) % 60;
        } else {
            cout << a + (b + c) / 60 << ' ' << (b + c) % 60;
        }
    } else {
        cout << a << ' ' << b + c;
    }
}