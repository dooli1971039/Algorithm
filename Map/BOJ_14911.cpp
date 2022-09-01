#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, int> mp;
    vector<int> arr;

    int input;
    while (cin >> input)
        arr.push_back(input);

    for (int i = 0; i < arr.size() - 2; i++)
        for (int j = i + 1; j < arr.size() - 1; j++)
            if (arr[i] + arr[j] == arr[arr.size() - 1])
                mp.insert({arr[i], arr[j]});

    for (auto i : mp)
        cout << i.first << ' ' << i.second << '\n';

    cout << mp.size() << '\n';
}
