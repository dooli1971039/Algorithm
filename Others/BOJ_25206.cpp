#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map<string, double> mp;

void setting() {
    mp.insert({"A+", 4.5});
    mp.insert({"A0", 4.0});
    mp.insert({"B+", 3.5});
    mp.insert({"B0", 3.0});
    mp.insert({"C+", 2.5});
    mp.insert({"C0", 2.0});
    mp.insert({"D+", 1.5});
    mp.insert({"D0", 1.0});
    mp.insert({"F", 0.0});
    mp.insert({"P", -1.0});
}

int main() {
    int num = 0;
    double sum = 0, total_time = 0;

    setting();

    string subject, score;
    double time;
    for (int i = 0; i < 20; i++) {
        cin >> subject >> time >> score;

        if (score == "P")
            continue;

        sum += (mp[score] * time);
        total_time += time;
    }

    cout << sum / total_time;
}