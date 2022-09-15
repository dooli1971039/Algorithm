#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e6;

//에라토스테네스의 체
vector<bool> isPrime() {
    vector<bool> is_prime(MAX + 1, true);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = i * i; j <= MAX; j += i) {
            is_prime[j] = false; //소수가 아님
        }
    }
    return is_prime;
}

int goldbach(int n, vector<bool> &is_prime) {
    for (int i = 3; i <= n / 2; i += 2) {
        if (is_prime[i] && is_prime[n - i]) {
            return i;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime = isPrime(); //미리 구해두기
    int input;

    while (true) {
        cin >> input;
        if (input == 0) {
            break;
        }

        int prime = goldbach(input, is_prime);
        if (prime == 0) {
            cout << "Goldbach's conjecture is wrong.\n";
        } else {
            cout << input << " = " << prime << " + " << input - prime << '\n';
        }
    }
}