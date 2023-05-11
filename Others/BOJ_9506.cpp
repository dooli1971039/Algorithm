#include <iostream>
#include <vector>
using namespace std;

void solution(int n){
    int ssum=0;
    vector<int> arr;
    for(int i=1;i<=n/2;i++){
        if(n%i==0){
            ssum+=i;
            arr.push_back(i);
        }
    }

    if(ssum==n){
        cout<<n<<" = "<<arr[0];
        for(int i=1;i<arr.size();i++){
            cout<<" + ";
            cout<<arr[i];
        }
        cout<<"\n";
    }else{
        cout<<n<<" is NOT perfect.\n";
    }
}

int main()
{
    while(true){
        int n;
        cin>>n;
        if(n==-1){
            break;
        }else{
            solution(n);  
        }

    }
}