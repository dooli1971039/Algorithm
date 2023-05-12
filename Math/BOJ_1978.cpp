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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime = isPrime(); //미리 구해두기
    int n;
    cin>>n;

    int result=0,tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        result+=is_prime[tmp];
    }
    cout<<result;
}