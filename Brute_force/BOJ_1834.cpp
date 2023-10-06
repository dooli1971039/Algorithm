#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long ssum = 0;

    for (long long i = 1; i < n; i++) {
        ssum += (i * n + i);
    }
    cout << ssum;
}