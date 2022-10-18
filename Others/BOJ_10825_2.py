#조건 변형
import sys
input = sys.stdin.readline  

def solution(n, name, kor, eng):
    arr = [(name[i], kor[i], eng[i]) for i in range(n)]
    # sort()가 2차원 혹은 그 이상의 리스트를 정렬할 때, 기본적으로 리스트의 첫번째 요소부터 오름차순으로 비교를 합니다.
    # 따라서 정렬의 우선순위를 변경하기 위해서는 key값에 람다 함수를 작성합니다.
    # 람다 함수는 비교 순서대로 작성하되, 내림차순이 필요한 경우 음수를 붙여줍니다.
    arr.sort(key=lambda x:(x[1], -x[2], x[0]))


    # 정렬된 리스트에서 이름 가져오기
    answer = [arr[i][0] for i in range(n)]
    return answer

# 입출력을 포함한 메인 코드
if __name__ == "__main__":
    # 입력
    n = int(input())
    kor = [0] * n
    eng = [0] * n
    name = [''] * n
    for i in range(n):
        name[i], scores = input().split(' ', 1)
        kor[i], eng[i] = map(int, scores.split())
    
    # 연산
    answer = solution(n, name, kor, eng)
    
    # 출력
    print(*answer, sep='\n')