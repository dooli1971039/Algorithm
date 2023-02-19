#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    getline(cin, str);

    int num = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            num++;
        }
    }

    if (str[0] == ' ') {
        num--;
    }
    if (str[str.length() - 1] == ' ') {
        num--;
    }

    cout << num;
}