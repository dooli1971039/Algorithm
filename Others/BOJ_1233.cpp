#include <iostream>
#include <map>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    map<int,int>mp;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                mp[i+j+k]+=1;
            }
        }
    }
    
    int count=0,result=0;
    for(auto m:mp){
        if(count<m.second){
            count=m.second;
            result=m.first;
        }
    }
    cout<<result;
    
    return 0;
}