#include <iostream>
#include <vector>
using namespace std;

struct Score
{
    string name;
    int kor,eng,math;
};


bool compare(Score a, Score b){
    // 국영수 모두 같을 때
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math)
		return a.name < b.name; //이름은 오름차순

    // 국어,영어 점수만 같을 때
	else if (a.kor == b.kor && a.eng == b.eng)
		return a.math > b.math; //수학은 내림차순

    // 국어 점수만 같을 때
	else if (a.kor == b.kor)
		return a.eng < b.eng; //영어는 오름차순

    // 국어 점수가 다를 때
	else
		return a.kor > b.kor; //국어는 내림차순
}

int main() {
	int num;
    cin>>num;

    vector<Score>v(num);

    for(int i=0;i<num;i++){
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
    }

    sort(v.begin(),v.end(),compare);

    for (int i = 0; i < num; i++) {
		cout << v[i].name << '\n';
	}

	return 0;
}