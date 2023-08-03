#include <iostream>
#include <stack>
#include <string>
using namespace std;

int solution(string s) {
    if (s.size() % 2 == 1) // 길이가 홀수이면 바로 0 리턴
        return 0;

    stack<char> st;
    int idx = 0;

    while (idx != s.size()) {
        if (!st.empty() && st.top() == s[idx]) {
            st.pop();
        } else {
            st.push(s[idx]);
        }
        idx++;
    }

    if (st.empty())
        return 1;
    else
        return 0;
}

// 이 방법은 정확성은 통과하지만 효율성 체크는 통과하지 못한다.
// #include <iostream>
// #include <string>
// using namespace std;

// string removeDuplicateChar(string s) {
//     string newStr = "";
//     for (int i = 0; i < s.size() - 1; i++) {
//         if (s[i] == s[i + 1]) {
//             i++;
//             continue;
//         }
//         newStr += s[i];
//     }

//     if (s[s.size() - 2] != s[s.size() - 1]) { // 마지막 글자 처리
//         newStr += s[s.size() - 1];
//     }

//     if (s.size() == newStr.size()) { // 길이가 같으면 중복 제거가 안 됐다는 뜻
//         return "-1";
//     } else
//         return newStr;
// }

// int solution(string s) {
//     if (s.size() % 2 == 1) // 길이가 홀수이면 바로 0 리턴
//         return 0;

//     while (true) {
//         if (s.size() == 0)
//             return 1; // 모두 제거

//         string newStr = removeDuplicateChar(s);
//         if (newStr == "-1") {
//             return 0;
//         } else {
//             s = newStr;
//         }
//     }
// }