#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    set<string> ss;

    string str, log;
    for (int i = 0; i < n; i++) {
        cin >> str >> log;

        auto iter = ss.find(str);
        if (log == "enter" && iter == ss.end())
            ss.insert(str);
        else if (log == "leave" && iter != ss.end())
            ss.erase(iter);
    }

    for (auto i = ss.rbegin(); i != ss.rend(); i++)
        cout << *i << '\n';
}