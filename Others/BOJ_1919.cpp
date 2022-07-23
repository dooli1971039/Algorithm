#include <iostream>
#include <algorithm>

using namespace std;


string f,b;
int a1[26],a2[26];
int num;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin>>f>>b;
    for(int i=0;i<f.size();i++){
        a1[f[i]-'a']++;
    }
    for(int i=0;i<b.size();i++){
        a2[b[i]-'a']++;
    }

    for(int i=0;i<26;i++){
        num+=abs(a1[i]-a2[i]);
    }
    cout<<num;
}