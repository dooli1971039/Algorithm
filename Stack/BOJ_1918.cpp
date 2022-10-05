#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char ch) {
    switch (ch) {
    case '*':
    case '/': //연산자 우선순위가 높다
        return 3;
    case '+':
    case '-':
        return 2;
    default:
        return 1;
    }
}

string infixToPostfix(string &str) {
    stack<char> st;
    string answer = ""; //후위 표기식

    for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
        case '(':
            st.push('(');
            break;

        case ')':
            while (!st.empty() && st.top() != '(') {
                answer += st.top();
                st.pop();
            }
            st.pop(); //'(' 제거
            break;

        case '*': //연산자일 때
        case '/':
        case '+':
        case '-':
            // 스택의 top보다 연산자 우선순위가 높으면 그냥 스택에 추가
            // 그렇지 않으면, top이 자신보다 작거나 같을 때까지 pop
            while (!st.empty() && priority(st.top()) >= priority(str[i])) {
                answer += st.top();
                st.pop();
            }
            st.push(str[i]);
            break;

        default: // 피연산자는 그대로 추가
            answer += str[i];
            break;
        }
    }

    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    cout << infixToPostfix(str);
}
