#include <algorithm>
#include <iostream>
using namespace std;

string s, t;

void changeString(string tmp) {
    if (tmp == s) {
        cout << 1;
        exit(0);
    }

    if (tmp.size() <= s.size())
        return;

    if (tmp[tmp.size() - 1] == 'A') {
        string newTmp = tmp;
        newTmp.erase(newTmp.end() - 1);
        changeString(newTmp);
    }
    if (tmp[0] == 'B') {
        string newTmp = tmp;
        newTmp.erase(newTmp.begin());
        reverse(newTmp.begin(), newTmp.end());
        changeString(newTmp);
    }
}

int main() {
    cin >> s >> t;
    changeString(t);
    cout << "0";
    return 0;
}

// 아래와 같이 재귀로 모든 경우를 체크하면 2^50이라 시간초과 발생
// #include <algorithm>
// #include <iostream>

// using namespace std;

// string before, after;

// void changeString(string tmp) {
//     if (tmp.size() == after.size()) {
//         if (tmp == after) {
//             cout << "1";
//             exit(0);
//         } else
//             return;
//     }

//     changeString(tmp + "A");

//     string reverseTmp = tmp + "B";
//     reverse(reverseTmp.begin(), reverseTmp.end());
//     changeString(reverseTmp);
// }

// int main() {
//     cin >> before >> after;
//     changeString(before);
//     cout << "0";
//     return 0;
// }
