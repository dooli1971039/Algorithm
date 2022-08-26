#include <iostream>
#include <algorithm>

using namespace std;

int n,k,result;
int arr[2][7]; // 0,1  1~6
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int s,y;
        cin>>s>>y;
        arr[s][y]++;
    }

    for(int i=0;i<2;i++){
        for(int j=1;j<7;j++){
            if(arr[i][j]%k==0) result+=arr[i][j]/k;
            else result+=arr[i][j]/k+1;
        }
    }

    cout<<result;
}