// 동적 계획법: 20055 컨베이어 벨트 위의 로봇
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calc(vector<int> &belt, int n, int k){
    vector<int> robot(2*n, 0); // 로봇이 없으면 0, 있으면 들어온 순서 (1, 2, ...)
    int idx, cnt = 0, robot_num = 0, robot_down = 1;
    while (count(belt.begin(), belt.end(), 0) < k)
    {
        rotate(belt.begin(), belt.end() - 1, belt.end()); // 벨트 회전
        rotate(robot.begin(), robot.end() - 1, robot.end()); // 벨트에 따라 로봇도 회전
        if (robot[n-1] != 0){
            robot_down = robot[n-1];
            robot[n-1] = 0;
        }
        for (int i=robot_down; i<=robot_num; i++){ // 가장 먼저 벨트에 올라간 로봇부터
            if (find(robot.begin(), robot.end(), i) != robot.end()){
                idx = find(robot.begin(), robot.end(), i) - robot.begin(); // i번째로 올라온 로봇의 인덱스
            } else {
                continue;
            }
            if (robot[idx] != 0 && robot[idx+1] == 0 && belt[idx+1] >= 1){ // i번째 칸에 로봇이 있고 그 다음 칸에는 로봇이 없으며 내구도가 1 이상 남아있는 경우
                robot[idx+1] = robot[idx];
                robot[idx] = 0;
                belt[idx+1]--;
                if (idx+1 == n-1){ // 내리는 칸이면
                    robot_down = robot[n-1];
                    robot[idx+1] = 0; // 내려줌
                }
            }
        }
        if (belt[0] > 0){ // 올리는 칸의 내구도가 0이 아니면
            robot[0] = ++robot_num; // 로봇을 올리고
            belt[0]--; // 내구도 감소
        }
        cnt++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> belt(2*n, 0);
    for (int i=0; i<2*n; i++){
        cin >> belt[i];
    }
    cout << calc(belt, n, k);
    return 0;
}