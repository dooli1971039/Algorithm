#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> site_name;
    string site, name;
    while (n--) {
        cin >> site >> name;

        site_name[site] = name;
    }

    while (m--) {
        cin >> site;
        cout << site_name[site] << '\n';
    }
}