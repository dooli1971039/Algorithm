#include <iostream>

using namespace std;

int main()
{
    string arr[8]={"000","001","010","011","100","101","110","111"};
    
    string num;
    cin>>num;
    
    if(num=="0"){
        cout<<0;
        return 0;
    }
    
    string result="";
    for(int i=0;i<num.size();i++){
        result+=arr[num[i]-'0'];
    }
    
    for(int i=0;i<result.size();i++){
        if(i==0 && result[0]=='0') continue;
        if(i==1 && result[0]=='0' && result[1]=='0') continue;
        cout<<result[i];
    }
}
