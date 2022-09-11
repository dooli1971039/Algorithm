#include <iostream>
using namespace std;

int calcGCD(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if (a < b) {
        swap(a, b);
    }

    int gcd = calcGCD(a, b);
    int lcm = a * b / gcd;

    cout << gcd << '\n' << lcm;
}