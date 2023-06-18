#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'c' && i + 1 < str.size()) {
            if (str[i + 1] == '=' || str[i + 1] == '-') {
                i++;
            }
        } else if (str[i] == 'd' && i + 1 < str.size()) {
            if (str[i + 1] == '-') {
                i++;
            } else if (str[i + 1] == 'z' && i + 2 < str.size() && str[i + 2] == '=') {
                i += 2;
            }
        } else if (str[i] == 'l' && i + 1 < str.size() && str[i + 1] == 'j') {
            i++;
        } else if (str[i] == 'n' && i + 1 < str.size() && str[i + 1] == 'j') {
            i++;
        } else if (str[i] == 's' && i + 1 < str.size() && str[i + 1] == '=') {
            i++;
        } else if (str[i] == 'z' && i + 1 < str.size() && str[i + 1] == '=') {
            i++;
        }
        cnt++;
    }

    cout << cnt;
}