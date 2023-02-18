#include <iostream>
using namespace std;

void solution() {
    int n;
    string str;
    cin >> n >> str;

    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < n; j++) {
            cout << str[i];
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << "\n";
    }
}