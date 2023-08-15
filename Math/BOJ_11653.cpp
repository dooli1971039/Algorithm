#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e7 + 1;

// 에라토스테네스의 체
vector<bool> isPrime() {
    vector<bool> is_prime(MAX + 1, true);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = i * i; j <= MAX; j += i) {
            is_prime[j] = false; // 소수가 아님
        }
    }
    return is_prime;
}

int main() {
    int n;
    cin >> n;

    vector<bool> primeArr = isPrime();

    int cnt = 2;
    while (n != 1) {
        if (primeArr[cnt] == false) {
            cnt++;
            continue;
        }

        while (n % cnt == 0) {
            cout << cnt << '\n';
            n /= cnt;
        }
        cnt++;
    }
}