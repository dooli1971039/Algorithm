#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> st;
    vector<char> result;

    int tmp;
    int usedMaxNumber = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (st.empty() || st.top() < tmp) {
            for (int j = usedMaxNumber + 1; j <= tmp; j++) {
                st.push(j);
                result.push_back('+');
                usedMaxNumber = tmp;
            }
        } else if (st.top() > tmp) {
            cout << "NO";
            return 0;
        }

        if (st.top() == tmp) {
            st.pop();
            result.push_back('-');
        }
    }

    for (auto num : result)
        cout << num << '\n';
}