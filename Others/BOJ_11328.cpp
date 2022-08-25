#include <iostream>
#include <algorithm>

using namespace std;

int n;
string f,b;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>f>>b;
        sort(f.begin(),f.end());
        sort(b.begin(),b.end());

        if(f==b) cout<<"Possible\n";
        else cout<<"Impossible\n";
    }

}