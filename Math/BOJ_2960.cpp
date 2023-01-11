#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int findPrime(int n, int k) {
    vector<bool> is_prime(n + 1, true); // n까지의 정수를 모두 적음
    is_prime[0] = is_prime[1] = false;  // 0,1은 소수가 아님

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) { // 이 경우 소수라는 뜻
            for (int j = i; j <= n; j += i) {
                if (is_prime[j]) {
                    is_prime[j] = false;
                    if (++cnt == k) {
                        return j;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    cout << findPrime(n, m);
}