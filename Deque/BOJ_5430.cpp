#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++) {
        string command, arr;
        int n;
        cin >> command >> n >> arr;

        string tmp = "";
        deque<string> dq;
        bool reverse = false;

        for (int j = 1; j < arr.size(); j++) {
            if (arr[j] == ',' || arr[j] == ']') {
                if (tmp != "")
                    dq.push_back(tmp);
                tmp = "";
            } else
                tmp += arr[j];
        }

        string ans = "[";
        for (int j = 0; j < command.size(); j++) {
            if (command[j] == 'R') {
                reverse = !reverse;
            } else {
                if (dq.empty()) {
                    ans = "error\n";
                    break;
                }
                if (reverse)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if (ans != "error\n") {
            if (reverse) {
                while (!dq.empty()) {
                    if (dq.size() != 1)
                        ans += (dq.back() + ",");
                    else
                        ans += dq.back();
                    dq.pop_back();
                }
            } else {
                while (!dq.empty()) {
                    if (dq.size() != 1)
                        ans += (dq.front() + ",");
                    else
                        ans += dq.front();
                    dq.pop_front();
                }
            }
            ans += "]\n";
        }

        cout << ans;
    }
}