#include <iostream>
#include <map>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int tmp;
    map<int,bool> arr;

    for(int i=0;i<n+m;i++){
        cin>>tmp;
        if(arr[tmp]==true){
            arr.erase(tmp);
        }else{
            arr[tmp]=true;
        }
    }
    cout<<arr.size();
}