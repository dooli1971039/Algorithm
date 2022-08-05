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
        printStar(i);
        printVoid(2*(n-i));
        printStar(i);
        cout<<'\n';
    }
    for(int i=n-1;i>=1;i--){
        printStar(i);
        printVoid(2*(n-i));
        printStar(i);
        cout<<'\n';
    }

}