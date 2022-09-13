#include <iostream>
#include <string>
using namespace std;

int calcGCD(int a, int b) { //최대공약수 구하기 (a가 더 커야함)
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    int num1 = stoi(input.substr(0, input.find(":")));
    int num2 = stoi(input.substr(input.find(":") + 1));

    int gcd;
    if (num1 < num2) {
        gcd = calcGCD(num2, num1);
    } else {
        gcd = calcGCD(num1, num2);
    }
    cout << num1 / gcd << ":" << num2 / gcd;
}