#include <iostream>
using namespace std;
int alpha[26] = {
    0,
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        alpha[str[0] - 'a']++;
    }
    string result = "";
    for (int i = 0; i < 26; i++) {
        if (alpha[i] >= 5) {
            result += (char)(i + 'a');
        }
    }
    if (result == "") {
        cout << "PREDAJA";
    } else {
        cout << result;
    }
}