#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, string>a, pair<int,string>b){
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    vector<pair<int, string>> arr(n);
    
    int tmp; string str;
    for(int i=0;i<n;i++){
        cin>>tmp>>str;
        arr[i]=make_pair(tmp,str);
    }
    
    stable_sort(arr.begin(),arr.end(),compare);
    
    for(int i=0;i<n;i++){
        cout<<arr[i].first<<" "<<arr[i].second<<'\n';
    }
    

    return 0;
}