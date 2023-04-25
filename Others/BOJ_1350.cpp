#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,size;
    long long tmp;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>size;
    
    long long cnt=0; //자료형 주의!
    for(int i=0;i<n;i++){
        cnt+=arr[i]/size;
        if(arr[i]%size!=0){
            cnt++;
        }
    }
    cout<<cnt*size;
    return 0;
}