#include <iostream>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n; cin>>n;
    if(n==0){
        cout<<"NO";
        return 0;
    }
    while(n>0){
        if(n%3==0) n/=3;
        else if((n-1)%3==0) n=(n-1)/3;
        else {
            cout<<"NO";
            return 0;
        }
        
    }
    cout<<"YES";

}
