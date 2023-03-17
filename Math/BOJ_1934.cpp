#include <algorithm>
#include <iostream>
using namespace std;

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

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a < b)
            swap(a, b);

        cout << a * b / calcGCD(a, b) << "\n";
    }
}