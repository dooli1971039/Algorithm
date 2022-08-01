#include <iostream>
using namespace std;

void printVoid(int n){
    for(int i=1;i<=n;i++){
        cout<<" ";
    }
}

void printStar(int n){
    for(int i=1;i<=n;i++){
        cout<<"*";
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin>>n;
    for(int i=n;i>=1;i--){
        printVoid(n-i);
        printStar(i);
        cout<<'\n';
    }
}