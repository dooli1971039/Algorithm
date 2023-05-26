#include <iostream>
using namespace std;

int main() {
    string n;cin>>n;
    bool check=false;

    int tmpL=1;
    for(int i=0;i<n.size()-1;i++){
        int tmpR=1;
        tmpL*=(n[i]-'0');

        for(int j=i+1;j<n.size();j++){
            tmpR*=(n[j]-'0');
        }

        if(tmpL==tmpR){
            check=true;
            break;
        }
    }

    if(check)
        cout<<"YES";
    else
        cout<<"NO";
}