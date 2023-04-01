#include <algorithm>
#include <iostream>
using namespace std;

void solution(int a, int b, int c) {

    if (a + b + c != 180) {
        cout << "Error\n";
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
    cin >> a >> b >> c;
    solution(a, b, c);
}