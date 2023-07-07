#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getResult(stack<string> &st) {
    int result = 0;
    while (!st.empty()) {
        if (st.top() == "(" || st.top() == "[")
            return 0;
        result += stoi(st.top());
        st.pop();
    }
    return result;
}

bool matchClose(stack<string> &st, char ch) {
    string openCh = (ch == ')' ? "(" : "[");
    int multiply = (ch == ')' ? 2 : 3);

    int result = 0;
    while (!st.empty() && st.top() != "(" && st.top() != "[") {
        result += stoi(st.top());
        st.pop();
    }
    if (st.empty() || st.top() != openCh) {
        cout << 0;
        return false;
    }

    st.pop();
    st.push(to_string(result * multiply));
    return true;
}

int main() {
    string str;
    cin >> str;
    stack<string> st;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' && i + 1 < str.size() && str[i + 1] == ')') {
            st.push("2");
            i++;
        } else if (str[i] == '[' && i + 1 < str.size() && str[i + 1] == ']') {
            st.push("3");
            i++;
        } else if (str[i] == '(') {
            st.push("(");
        } else if (str[i] == '[') {
            st.push("[");
        } else if (str[i] == ')' || str[i] == ']') { // 닫는 괄호가 들어온 경우 맞는 쌍이 나올 때까지 모두 더함
            if (!matchClose(st, str[i])) {
                return 0;
            }
        }
    }

    cout << getResult(st);
    return 0;
}