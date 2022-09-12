#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    
    while(true){
        string str;
        getline(cin,str);
        
        if(str=="") break;
        int arr[4]={0,};
    
        for(int i=0;i<str.size();i++){
            if(str[i]-'A'>=0 && str[i]-'A'<26) arr[1]++;
            else if(str[i]-'a'>=0 && str[i]-'a'<26) arr[0]++;
            else if(str[i]-'0'>=0 && str[i]-'0'<=9) arr[2]++;
            else arr[3]++;
        }
    
        for(auto i:arr) cout<<i<< ' ';
        cout<<"\n";
    }
}
