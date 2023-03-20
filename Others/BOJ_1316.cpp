#include <iostream>
using namespace std;

int solution(string str) {
    bool arr[26] = {
        false,
    };

    arr[str[0] - 'a'] = true;
    for (int i = 1; i < str.size(); i++) {
        if (str[i - 1] == str[i]) {
            continue;
        } else if (arr[str[i] - 'a']) {
            return 0;
        }
        arr[str[i] - 'a'] = true;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;

    int sum = 0;
    for (int i = 0; i < test; i++) {
        string str;
        cin >> str;

        sum += solution(str);
    }
    cout << sum;
}