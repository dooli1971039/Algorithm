#include <iostream>

using namespace std;
int arr[1001];
void calc(){
    int cnt=0;
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=i;j++){
            if(cnt==1000) break;
            cnt++;
            arr[cnt]=i;
        }
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    calc();

    int result=0;
    for(int i=a;i<=b;i++){
        result+=arr[i];
    }
    cout<<result;
}