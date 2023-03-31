#include <algorithm>
#include <iostream>
using namespace std;

void solution(int a, int b, int c) {
    int mmax = max(a, max(b, c));
    if (a + b + c - mmax <= mmax) {
        cout << "Invalid\n";
    } else if (a == b && b == c) {
        cout << "Equilateral\n";
    } else if (a == b || b == c || c == a) {
        cout << "Isosceles\n";
    } else {
        cout << "Scalene\n";
    }
}

int main() {
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        solution(a, b, c);
    }
}