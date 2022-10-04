#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n,tmp; cin>>n;
    set<int> s;
    for(int i=0;i<n;i++){
        cin>>tmp;
        s.insert(tmp);
    }
    for(auto i: s) cout<<i<<' ';
}