#include <iostream>

using namespace std;

int fb[21] = {0, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        fb[i] = fb[i - 1] + fb[i - 2];
    }
    cout << fb[n];
}