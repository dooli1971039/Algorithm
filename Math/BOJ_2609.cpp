#include <iostream>
using namespace std;

// 최소공배수 구하기
int calcLCD(int a, int b, int gcd) { return a * b / gcd; }

// 최대공약수 구하기
int calcGCD(int a, int b) { // a가 더 커야함
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
    int lcm = calcLCD(a, b, gcd);
    cout << gcd << '\n' << lcm;
}