#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MAX = 1e6;

// 최대공약수 계산
int calc_GCD(int a, int b) { // a가 더 커야함
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

void solution(int n, vector<int> &arr) {

    int num = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        num = calc_GCD(num, arr[i] - arr[i - 1]);
    }

    for (int i = 2; i * 2 <= num; i++) {
        if (num % i == 0) {
            cout << i << ' ';
        }
    }
    cout << num;
}

/*
 * A, B, C를 M으로 나눴을 때의 나머지가 모두 같을 때, 이 나머지 값을 K라 하면
 * A = M * a + K, B = M * b + K, C = M * c + K 이므로
 * B - A = (M * b + K) - (M * a + K) = M(b - a)
 * C - B = (M * c + K) - (M * b + K) = M(c - b)
 * M은 각 검문소 사이 간격 간의 모든 공약수
 */

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    solution(n, arr);
}