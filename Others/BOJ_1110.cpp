#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int makeNewNumber(int n) {
    string str = to_string(n);
    if (n < 10) {
        str = '0' + str;
    }

    int plus = (str[0] - '0') + (str[1] - '0');
    return (n % 10) * 10 + plus % 10;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, count = 1;
    cin >> n;

    int num = makeNewNumber(n);
    while (num != n) {
        num = makeNewNumber(num);
        count++;
    }

    cout << count;
}