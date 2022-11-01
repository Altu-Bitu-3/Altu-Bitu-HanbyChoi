#include <string>
#include <vector>
using namespace std;

// 1. 각 학생의 체육복 수를 계산
// 2. 왼쪽 학생부터 양 옆의 학생에게 체육복을 빌릴 수 있는지 확인 - 둘 다 가능하면 왼쪽 학생을 선택
// 3. 체육복이 1개 이상인 학생 수를 카운트

int solution(int n, vector<int> lost, vector<int> reverse){
    int answer = 0;
    vector<int> clothes(n+2, 0); // 마지막 학생의 오른쪽까지 고려한 인덱스 - 인덱스 에러 막기 위한 예외 처리
    for (auto i: lost){
        clothes[i]--;
    }
    for (auto i: reverse){
        clothes[i]++;
    }
    for (int i=1; i<=n; i++){
        if (clothes[i]){
            continue;
        }
        if (clothes[i-1] == 2){ // 왼쪽 학생이 체육복이 있는 경우
            clothes[i-1]--;
            clothes[i]++;
        } else if (clothes[i+1] == 2){ // 왼쪽은 없는데 오른쪽은 있는 경우
            clothes[i+1]--;
            clothes[i]++;
        }
    }
    for (int i=1; i<=n; i++){
        if (clothes[i]){
            answer++;
        }
    }
    return answer;
}