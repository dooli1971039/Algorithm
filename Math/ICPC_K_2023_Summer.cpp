#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// 최대공약수 구하기
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

struct Lectangle {
    long long minX;
    long long maxX;
    long long minY;
    long long maxY;
};

void setLectangle(Lectangle &L) {
    long long x, y;
    for (int i = 0; i < 4; i++) {
        cin >> x >> y;
        L.minX = min(L.minX, x);
        L.maxX = max(L.maxX, x);
        L.minY = min(L.minY, y);
        L.maxY = max(L.maxY, y);
    }
}

int main() {
    Lectangle L1 = {1000005, -1000005, 1000005, -1000005};
    Lectangle L2 = {1000005, -1000005, 1000005, -1000005};

    setLectangle(L1);
    setLectangle(L2);

    // 각 케이크의 중심 계산(사실 중심 * 2임. long long 안쓰기 위함.)
    long long x1 = L1.maxX + L1.minX;
    long long y1 = L1.maxY + L1.minY;

    long long x2 = L2.maxX + L2.minX;
    long long y2 = L2.maxY + L2.minY;

    // 기울기 계산
    long long a1 = y1 - y2;
    long long b1 = x1 - x2;

    // y절편 계산
    long long a2 = b1 * y1 - a1 * x1;
    long long b2 = b1 * 2;

    // 기약분수
    long long gcd1 = gcd(a1, b1);
    a1 /= gcd1;
    b1 /= gcd1;

    long long gcd2 = gcd(a2, b2);
    a2 /= gcd2;
    b2 /= gcd2;

    if (b1 == 1)
        cout << a1 << " ";
    else if (b1 < 0) {
        cout << (-1) * a1 << "/" << (-1) * b1 << " ";
    } else
        cout << a1 << "/" << b1 << " ";

    if (b2 == 1)
        cout << a2 << " ";
    else if (b2 < 0) {
        cout << (-1) * a2 << "/" << (-1) * b2 << " ";
    } else
        cout << a2 << "/" << b2 << " ";

    return 0;
}