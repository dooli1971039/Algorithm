#include <iostream>

using namespace std;

int main()
{
    while(true){
        string n; cin>>n;
        if(n=="0") break;
        
        int result=2+n.size()-1;
        for(int i=0;i<n.size();i++){
            if(n[i]=='1') result+=2;
            else if(n[i]=='0') result+=4;
            else result+=3;
        }
        
        cout<<result<<'\n';
    }
}