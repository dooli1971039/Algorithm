#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    int ssum = 0, tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        ssum += tmp;
    }

    cout << ssum - n + 1;
}