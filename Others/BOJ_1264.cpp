#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        string str;
        getline(cin, str);
        if (str == "#") {
            break;
        }

        int alpha[26] = {
            0,
        };

        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                alpha[str[i] - 'A']++;
            }
            if (str[i] >= 'a' && str[i] <= 'z') {
                alpha[str[i] - 'a']++;
            }
        }
        cout << alpha[0] + alpha[4] + alpha[8] + alpha[14] + alpha[20] << '\n';
    }
}