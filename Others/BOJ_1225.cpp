#include <iostream>

using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    
    long long result=0;
    for(int i=0;i<str1.size();i++){
        for(int j=0;j<str2.size();j++){
            result+= (str1[i]-'0') * (str2[j]-'0');
        }
    }

    cout<<result;
}
