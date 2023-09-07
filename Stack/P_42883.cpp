#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    stack<char> st;

    for (int i = 0; i < number.size(); i++) {
        if (k == 0 || st.empty() || st.top() >= number[i]) {
            st.push(number[i]);
        } else {
            while (!st.empty() && st.top() < number[i]) {
                st.pop();
                k--;
                if (k == 0)
                    break;
            }
            st.push(number[i]);
        }
    }

    string answer = "";
    while (!st.empty()) {
        if (k > 0) {
            st.pop();
            k--;
            continue;
        }
        answer += st.top();
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}