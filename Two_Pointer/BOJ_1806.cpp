#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mmin = 100005;
    int total = arr[0];
    int st = 0, en = 0;
    while (true) {
        if (total < s) { // en 증가
            en++;
            if (en == n)
                break;
            total += arr[en];
        } else {
            mmin = min(mmin, en - st + 1); // 길이 업데이트
            total -= arr[st];
            st++; // st 증가
        }
    }

    cout << ((mmin == 100005) ? 0 : mmin);
}