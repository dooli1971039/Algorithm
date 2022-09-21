#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    vector<int> alpha(26, 0);

    for (int i = 0; i < str.size(); i++) {
        alpha[str[i] - 'A']++;
    }

    // 홀수인거 개수 세기
    int one_odd = -1;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] % 2 == 0)
            continue;
        else if (one_odd == -1) {
            one_odd = i;
        } else {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }

    vector<char> answer;

    for (int i = 0; i < 26; i++) {
        int num = alpha[i] / 2;
        for (int j = 0; j < num; j++) {
            answer.push_back('A' + i);
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }

    if (one_odd != -1)
        cout << char('A' + one_odd);

    for (int i = answer.size() - 1; i >= 0; i--) {
        cout << answer[i];
    }
}