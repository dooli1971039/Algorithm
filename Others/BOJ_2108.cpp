#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    int sum = 0;               // 산술평균을 구하기 위한 전체 합
    vector<int> freq(8001, 0); //최빈값을 구하기 위한 배열(-4000~4000)

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        freq[arr[i] + 4000]++;
    }

    // 1. 산술평균
    // cout << round((double)sum / n) << '\n'; // round 쓰려면 조건문 써야함
    cout << floor((double)sum / n + 0.5) << '\n';

    // 2. 중앙값
    sort(arr.begin(), arr.end());
    cout << arr[n / 2] << '\n';

    // // 3. 최빈값
    int flag;
    int mmax = 0;
    for (int i = 0; i < 8001; i++) {
        if (freq[i] > mmax) {
            mmax = freq[i];
            flag = i;
        }
    }

    for (int i = flag + 1; i < 8001; i++) {
        if (freq[i] == mmax) {
            flag = i;
            break;
        }
    }
    cout << flag - 4000 << '\n';

    // 4. 범위
    cout << arr[n - 1] - arr[0] << '\n';
}