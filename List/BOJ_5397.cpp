//이건 list로 하는 방법. stack으로 할 수도 있다.
#include <iostream>
#include <list>
#include <string>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n;

    for(int i=0;i<n;i++){
        string str; cin>>str;

        list<char>ls;
        list<char>::iterator cursor=ls.begin();

        for(int j=0;j<str.length();j++){
            char ch=str[j];

            if(ch=='<'){
                if(cursor!=ls.begin()) cursor--;

            }else if(ch=='>'){
                if(cursor!=ls.end()) cursor++;
            
            }else if(ch=='-'){
                if(cursor!=ls.begin()) {
                    cursor--;
                    cursor=ls.erase(cursor);
                }
            
            }else{
                ls.insert(cursor,ch);
            }
        }
    
        for(auto k:ls) cout<<k;
        cout<<'\n';

    }
}