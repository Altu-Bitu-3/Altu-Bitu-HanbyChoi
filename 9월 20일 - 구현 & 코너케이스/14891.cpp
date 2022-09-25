// 구현 & 코너케이스: 14891 톱니 바퀴
#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

using namespace std;

const int R = 2; // 오른쪽 톱니 인덱스
const int L = 6; // 왼쪽 톱니 인덱스
deque<int> wheel[5]; // 톱니바퀴의 상태를 저장
vector<int> rotation(5, 0); // 방향 저장 - 1: 시계, -1: 반시계, 0: 회전 없음

void decideRotation(int num, int rot){
    // 탈출 조건
    if (rotation[num] != 0){
        return;
    }
    rotation[num] = rot; // num 톱니바퀴를 rot 방향으로 회전
    // 오른쪽 바퀴
    if (num < 4 && wheel[num][R] != wheel[num+1][L]){ // 맨 앞부터 검사하므로 순서 중요
        decideRotation(num+1, -rot);
    }
    // 왼쪽 바퀴
    if (num > 1 && wheel[num][L] != wheel[num-1][R]){
        decideRotation(num-1, -rot);
    }
}

void rotate(){
    for (int i=1; i<=4; i++){
        // 시계방향으로 회전하는 경우
        if (rotation[i] == 1){
            int temp = wheel[i].back();
            wheel[i].pop_back();
            wheel[i].push_front(temp);
        } else if (rotation[i] == -1){
            int temp = wheel[i].front();
            wheel[i].pop_front();
            wheel[i].push_back(temp);
        }
    }
    return;
}

int calcScore(){
    int answer = 0;
    for (int i=1; i<=4; i++){
        answer += pow(2, i-1) * wheel[i][0];
    }
    return answer;
}

int main(){
    string temp;
    for (int i=1; i<=4; i++){
        cin >> temp;
        for (int j=0; j<8; j++){
            wheel[i].push_back(temp[j] - '0'); // 정수로 변환
        }
    }

    int n, num, rot;
    cin >> n;

    while (n--){
        cin >> num >> rot;
        rotation.assign(5, 0);
        decideRotation(num, rot); // 회전 방향 결정
        rotate(); // 회전
    }
    
    // 점수 계산하기
    cout << calcScore();
    return 0;
}