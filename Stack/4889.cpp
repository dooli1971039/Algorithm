#include <iostream>
#include <stack>
using namespace std;

/*
    1. stack에 문자를 1개씩 넣는다. {} 쌍을 이루게 되면 pop한다.
    2. 스택에 문자들이 남아있을 경우, 가장 위의 2개 원소를 뽑는다. (항상 짝수임)
    3. 두 문자가 같은 괄호일 경우, 하나만 방향을 바꾸면 되므로 +1
    4. 두 문자가 다른 경우 }{ , 둘 다 방향을 바꿔야 하므로 +2
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test = 1;
    while (true) {
        string str;
        cin >> str;
        if (str[0] == '-') {
            break;
        }

        stack<char> st;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '{') {
                st.push('{');
            } else if (!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                st.push('}');
            }
        }

        int count = 0;
        while (!st.empty()) {
            char first = st.top();
            st.pop();
            char second = st.top();
            st.pop();

            if (first == second) {
                count += 1;
            } else {
                count += 2;
            }
        }

        cout << test << ". " << count << '\n';
        test++;
    }
}