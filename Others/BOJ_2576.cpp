#include <iostream>
#include <algorithm>
using namespace std;

int ssum,tmp;
int mmin=1e9;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<7;i++){
       cin>>tmp;
       if(tmp%2==0) continue;
       
       ssum+=tmp;
       mmin=min(tmp,mmin);
    }
    if(ssum==0) cout<<-1;
    else cout<<ssum<<'\n'<<mmin;
}