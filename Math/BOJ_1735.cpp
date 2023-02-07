#include <iostream>
using namespace std;

/*
a/b, c/d 를 더하여 기약분수의 형태로 구하자
*/

// 재귀 이용하여 최대공약수(gcd) 구하기
int getGCD_recur(int a, int b) { // a가 더 커야함
    if (b == 0) {
        return a;
    }
    return getGCD_recur(b, a % b);
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int up = a * d + b * c; // 분자
    int down = b * d;       // 분모
    int gcd = calcGCD(max(up, down), min(up, down));

    cout << up / gcd << " " << down / gcd;
}