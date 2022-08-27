#include <iostream>
#include <algorithm>

using namespace std;

int n,x;
int arr[100005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>x;

    sort(arr,arr+n);
    
    int front=0,back=n-1,result=0;
    while(front<back){
        int ssum=arr[front]+arr[back];
        if(ssum==x){
            result++;
            front++;
            back--;
        }else if(ssum>x){
            back--;
        }else{
            front++;
        }
    }
    cout<<result;
}