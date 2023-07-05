#include <iostream>
#include <stack>
using namespace std;

bool solution() {
    string str;
    cin >> str;
    stack<char> st;

    for (int i = 0; i < str.size(); i++) {
        if (st.empty()) {
            st.push(str[i]);
        } else {
            if (st.top() == str[i]) {
                st.pop();
            } else {
                st.push(str[i]);
            }
        }
    }

    return st.empty();
}

int main() {
    int n;
    cin >> n;

    int count = 0;
    while (n--) {
        if (solution())
            count++;
    }
    cout << count;
}