#include <iostream>
#include <algorithm>
using namespace std;

int n,tmp;
int y,m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>tmp;

        y+=((tmp/30)+1)*10;
        m+=((tmp/60)+1)*15;
    }

    if(y<m) cout<<"Y "<<y;
    else if(y==m) cout<<"Y M "<<y;
    else cout<<"M "<<m;
}