//조건 변형
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct // 구조체를 정의합니다
{
    char name[11];
    int kor, eng;
} Student;

int compare(const void *ptr1, const void *ptr2){ //비교 함수를 정의합니다
    const Student *a = ptr1, *b = ptr2;
    if(a->kor == b->kor){
    	if(a->eng == b->eng) {
    		return strcmp((char *)a->name,(char *)b->name);
    	}
    	return (b->eng - a->eng);
    }
    return (a->kor - b->kor); 
}
char ** solution(int n, char name[][11], int kor[], int eng[]){
  char **answer = malloc(sizeof(char*)*n); //동적 할당합니다
  for(int i = 0; i < n; i++) answer[i] = malloc(11 * sizeof(char));

  Student arr[n]; // Student 배열을 만듭니다
  for(int i = 0; i < n; i++){ 
     strcpy(arr[i].name,name[i]);
     arr[i].kor = kor[i];
     arr[i].eng = eng[i];
  }
  qsort(arr, n, sizeof(Student), compare); //정렬합니다
  for(int i = 0; i < n; i++) strcpy(answer[i],arr[i].name);
  return answer;
}
int main()
{
    int n;
    char **answer;
    char name[100010][11] = {""};
    int kor[100010];
    int eng[100010];

    //입력 
    scanf("%d", &n);   
    for (int i = 0; i < n; i++)
    scanf("%s %d %d", name[i], &kor[i], &eng[i]);  
    answer = solution(n, name, kor, eng);
    //출력
     for (int i = 0; i < n; i++) printf("%s\n",answer[i]);   
}