#include <iostream>
#include <list>
#include <string>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string str;
    int m;
    cin>>str>>m; //문자열과 명령어 개수를 입력받음

    list<char>ls;
    for(int i=0;i<str.length();i++)
        ls.push_back(str[i]);
    
    list<char>::iterator cursor=ls.end(); //맨 마지막의 다음을 가리킴

    for(int i=0; i<m;i++){
        char command;
        cin>>command;

        if(command=='L'){ //커서를 왼쪽으로 한칸
            if(cursor==ls.begin()) continue;
            else cursor--;

        }else if(command=='D'){ //커서를 오른쪽으로 한칸
            if(cursor==ls.end()) continue;
            else cursor++;

        }else if(command=='B'){ //커서 왼쪽의 한 글자를 삭제
            if(cursor==ls.begin()) continue;
            else {
                cursor--;
                cursor=ls.erase(cursor); //지운 것의 다음 iter를 반환
            }
        }else{// P일때 커서 왼쪽에 추가
            char character; 
            cin>>character;
            ls.insert(cursor,character); //insert는 삽입한 원소를 가리킴
            //(커서는 원래 가리키던 것을 가리켜야 하니까 변동 없음)
        }
        
    }

    for(auto i:ls) cout<<i;    
}