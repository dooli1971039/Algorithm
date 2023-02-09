#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 최대공약수 구하기
int calcGCD(int a, int b) { // a가 더 커야함
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// 재귀 이용하여 최대공약수(gcd) 구하기
int getGCD_recur(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGCD_recur(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if (a < b)
        swap(a, b);

    cout << a + b - calcGCD(a, b);
}