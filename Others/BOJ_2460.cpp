#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int in, out;
    int people = 0;
    int max_people = 0;
    for (int i = 0; i < 10; i++) {
        cin >> out >> in;
        people = people - out + in;
        if (max_people < people) {
            max_people = people;
        }
    }
    cout << max_people;
}