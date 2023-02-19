#include <iostream>
using namespace std;

int alpha[26] = {
    0,
};
int main() {
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        alpha[toupper(str[i]) - 'A']++;
    }

    int max_num = alpha[0];
    char max_char = 'A';
    bool single = true;
    for (int i = 1; i < 26; i++) {
        if (max_num < alpha[i]) {
            max_char = (char)(i + 'A');
            max_num = alpha[i];
            single = true;
        } else if (max_num == alpha[i]) {
            single = false;
        }
    }

    if (single) {
        cout << max_char;
    } else {
        cout << '?';
    }
}