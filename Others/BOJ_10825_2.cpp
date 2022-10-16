//조건 변형
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Score
{
    string name;
    int kor,eng;
};


bool compare(const Score &a, const Score &b){
    // 모두(국어, 영어) 같을 때
    if (a.kor == b.kor && a.eng == b.eng)
		return a.name < b.name; //증가

    // 국어 점수만 같을 때
	else if (a.kor == b.kor)
		return a.eng > b.eng; //감소

    // 국어 점수가 다를 때
	else
		return a.kor < b.kor; //증가
}

vector<string> solution(int n, vector<string> name, vector<int> kor, vector<int> eng){
    vector<string>answer(n);
    vector<Score>v(n);
    for(int i=0;i<n;i++){
        v[i]={name[i],kor[i],eng[i]};
    }

    sort(v.begin(),v.end(),compare);
    for(int i=0;i<n;i++) answer[i]=v[i].name;
    
    return answer;
}

int main() {
	int n;
    cin>>n;

    vector<string> name(n);
    vector<int> kor(n);
    vector<int> eng(n);


    for(int i = 0; i < n; i++) cin>>name[i]>>kor[i]>>eng[i];

    auto answer = solution(n,name, kor, eng);

    for(auto i : answer) cout<<i<<'\n';
    return 0;
}