#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int num=2;
    while(n>1){
        if(n%num==0){
            answer.push_back(num);
            while(n%num==0){
                n/=num;
            }
        }
        num++;
    }
    
    return answer;
}