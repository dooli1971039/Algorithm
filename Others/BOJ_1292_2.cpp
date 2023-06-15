#include <iostream>

using namespace std;

// 처음부터 n개까지의 합
int rangeSum(int n) {
    int result = 0;
    int idx = 1, cnt = 1;
    while (true) {
        for (int i = 0; i < idx; i++) {
            if (cnt > n) {
                return result;
            }
            result += idx;
            cnt++;
        }
        idx++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    cout << rangeSum(b) - rangeSum(a-1);
}