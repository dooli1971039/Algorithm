#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MAX = 1e6;

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

// 각 자리수 곱해서 더함
int doubleSum(int n) {
    int sum = 0;
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

// 상근수인지 체크
bool check(int n) {
    set<int> ss;
    ss.insert(n);

    while (true) {
        n = doubleSum(n);
        if (n == 1) {
            return true;
        }
        if (ss.find(n) != ss.end()) { // 중복
            return false;
        }
        ss.insert(n);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime = isPrime(); // 미리 구해두기
    int n;
    cin >> n;

    for (int i = 3; i <= n; i++) {
        if (is_prime[i] && check(i)) {
            cout << i << '\n';
        }
    }
}