#include <iostream>
using namespace std;

int visit(int N, int r, int c) {
    if (N == 0) { // N이 0인경우 배열 자체가 없음
        return 0;
    }

    int length = (1 << (N - 1));
    if (r < length && c < length) { // 1사분면
        return visit(N - 1, r, c);
    } else if (r < length && c >= length) { // 2사분면
        return visit(N - 1, r, c - length) + length * length;
    } else if (r >= length && c < length) { // 3사분면
        return visit(N - 1, r - length, c) + 2 * length * length;
    } else { // 4사분면
        return visit(N - 1, r - length, c - length) + 3 * length * length;
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;

    cout << visit(N, r, c);
}