#include <iostream>
using namespace std;

/**
 * n-1개의 원판을 기둥 1에서 기둥 2로 옮긴다.
 * n번 원판을 기둥 3으로 옮긴다.
 * n-1개의 원판을 기둥 2에서 기둥 3으로 옮긴다.
 *
 * - 원판이 n-1개일 때 옮길 수 있으면 원판이 n개일 때에도 옮길 수 있다.
 * - 원판이 1개일 때에 옮길 수 있다.
 *
 * => 재귀로 풀 수 있다.
 */
void hanoi(int a, int b, int n) { // a번 막대에서 b번 막대로 n개를 옮길 때의 이동 횟수
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }

    hanoi(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    hanoi(6 - a - b, b, n - 1);
}

int main() {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << '\n'; // 2^n-1 개
    hanoi(1, 3, n);
}