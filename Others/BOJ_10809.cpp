#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    vector<int> alpha(26, -1);
    for (int i = str.length() - 1; i >= 0; i--) {
        alpha[str[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << alpha[i] << ' ';
    }
}