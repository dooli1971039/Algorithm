#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int calcGCD(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;

    for (int i = 0; i < test; i++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j++)
            cin >> arr[j];

        sort(arr.begin(), arr.end(), greater<>());

        long long answer = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                answer += calcGCD(arr[j], arr[k]);
            }
        }

        cout << answer << '\n';
    }
}