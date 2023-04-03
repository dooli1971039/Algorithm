#include <iostream>

using namespace std;
char arr[5][15];
int main()
{   
    string str;
    for(int i=0;i<5;i++){
        cin>>str;
        for(int j=0;j<str.size();j++){
            arr[i][j]=str[j];
        }
    }
    
    string result="";
    for(int i=0;i<15;i++){
        for(int j=0;j<5;j++){
            if(arr[j][i]){
                result+=arr[j][i];
            }
        }
    }
    cout<<result;
}
