#include <iostream>
#include <set>
using namespace std;

int main() {
    string str;
    cin>>str;

    set<string> arr;

    string tmp = "";
    for (int i = 0; i < str.size(); i++) {
        for (int j = i; j < str.size(); j++) {
            tmp += str[j];
            arr.insert(tmp);
        }
        tmp = "";
    }
 
    cout << arr.size();
}