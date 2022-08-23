#include <iostream>
#include <algorithm>
using namespace std;

int a[26];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    string str; cin>>str;
    int llen=str.size();

    for(int i=0;i<llen;i++){
        a[str[i]-'a']++;
    }

    for(int i=0;i<26;i++) cout<<a[i]<<' ';
}