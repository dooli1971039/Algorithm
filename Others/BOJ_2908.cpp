#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int num1 = 0, num2 = 0;
    num1 = a % 10 * 100 + (a % 100) / 10 * 10 + a / 100;
    num2 = b % 10 * 100 + (b % 100) / 10 * 10 + b / 100;
    cout << max(num1, num2);
}