// 강의 보면서 다시 이해해보자
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 5e6;

//원소의 가장 작은 소인수를 저장하게 된다.
vector<int> isPrime() {
    // n 이하의 수를 소인수분해하는 경로를 리턴
    vector<int> prime(SIZE + 1, 0);

    for (int i = 2; i * i <= SIZE; i++) { // cmath 불러와서 sqrt 써도 됨
        // 소수가 아니면
        if (prime[i] != 0)
            continue;

        // i 가 소수라면
        for (int j = i * i; j <= SIZE; j += i) {
            if (prime[j] == 0) {
                prime[j] = i; //어느 소수의 배수로 지워졌는지 저장
            }
        }
    }

    return prime;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    cin >> n;

    vector<int> prime = isPrime();

    while (n--) {
        cin >> tmp;

        // prime[tmp] != 0 이면 소수가 아니다.
        while (prime[tmp] != 0) {
            cout << prime[tmp] << ' ';
            tmp /= prime[tmp];
        }

        // tmp 가 소수임
        cout << tmp << '\n';
    }
}