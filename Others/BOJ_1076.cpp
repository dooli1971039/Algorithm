#include <iostream>
using namespace std;

string mul(string str){
    if(str=="black"){
        return "";
    }else if(str=="brown"){
        return "0";
    }else if(str=="red"){
        return "00";
    }else if(str=="orange"){
        return "000";
    }else if(str=="yellow"){
        return "0000";
    }else if(str=="green"){
        return "00000";
    }else if(str=="blue"){
        return "000000";
    }else if(str=="violet"){
        return "0000000";
    }else if(str=="grey"){
        return "00000000";
    }else if(str=="white"){
        return "000000000";
    }
    return "";
}

int value(string str){
    if(str=="black"){
        return 0;
    }else if(str=="brown"){
        return 1;
    }else if(str=="red"){
        return 2;
    }else if(str=="orange"){
        return 3;
    }else if(str=="yellow"){
        return 4;
    }else if(str=="green"){
        return 5;
    }else if(str=="blue"){
        return 6;
    }else if(str=="violet"){
        return 7;
    }else if(str=="grey"){
        return 8;
    }else if(str=="white"){
        return 9;
    }
    return -1;
}

int main() {
    string a,b,c;
    cin>>a>>b>>c;
    int result=value(a)*10+value(b);
    if(result==0){
        cout<<0;
    }else{
        cout<<result<<mul(c);
    }
}