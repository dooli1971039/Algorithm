#include <iostream>
#include <set>

using namespace std;

void solution() {
    int k;
    cin >> k;

    string ch, n;
    multiset<int> ss;
    while (k--) {
        cin >> ch >> n;

        if (ch == "I") // 삽입 연산
            ss.insert(stoi(n));

        else { // D 삭제 연산
            if (ss.empty())
                continue;

            if (n == "1") {
                ss.erase(--ss.end());
            } else {
                ss.erase(ss.begin());
            }
        }
    }

    if (ss.empty())
        cout << "EMPTY\n";
    else
        cout << *(--ss.end()) << ' ' << *ss.begin() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testCase;
    cin >> testCase;
    while (testCase--) {
        solution();
    }
}