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
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
    for(int i=1;i<=n;i++){
        printVoid(n-i);
        printStar(i);
        cout<<'\n';
    }
}