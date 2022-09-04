#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n,m; 
    cin>>n>>m;
    map<string,int> name;
    map<int,string> number;

    string str;
    for(int i=1;i<=n;i++){
        cin>>str;
        name[str]=i;
        number[i]=str;
    }

    for(int i=0;i<m;i++){
        cin>>str;
        if(str[0]-'0'>=0 && str[0]-'0'<=9)
            cout<<number[stoi(str)]<<'\n';
        else
            cout<<name[str]<<'\n';
    }
}