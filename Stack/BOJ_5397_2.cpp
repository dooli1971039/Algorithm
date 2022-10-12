//키로거 스택으로 풀기
#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n;

    for(int i=0;i<n;i++){
        string str; cin>>str;

        //스택 1, 커서, 스택2 이 순서대로 있다고 생각하기
        stack<char>front;
        stack<char>back;

        for(int j=0;j<str.length();j++){
            char ch=str[j];

            if(ch=='<'){
                if(!front.empty()){
                    back.push(front.top());
                    front.pop();
                }

            }else if(ch=='>'){
                if(!back.empty()){
                    front.push(back.top());
                    back.pop();
                }

            }else if(ch=='-'){
                if(!front.empty())
                    front.pop();
                
            }else{
                front.push(ch);
            }
        }
    
        while(!front.empty()){
            back.push(front.top());
            front.pop();
        }

        while(!back.empty()){
            cout<<back.top();
            back.pop();
        }
        cout<<'\n';

    }
}