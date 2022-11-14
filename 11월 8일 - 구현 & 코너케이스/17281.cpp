// 구현 & 코너케이스: 17281 야구
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calcScore(int n, vector<vector<int>> &Inning, vector<int> &order){
    int score = 0, num = 0;
    for (int i=1; i<=n; i++){ // i 이닝에 대해
        int out = 0;
        vector<pair<bool, int>> status(10, {false, 0}); // 주자 여부와 몇 루에 있는지 상태 저장
        while (true){ // 이닝이 끝날 때까지 (3 아웃이 발생할 때까지)
            if (Inning[i][order[num]] > 0){ // 타석에 선 선수의 결과가 안타, 2루타, 3루타, 홈런
                status[order[num]].first = true; // 타자가 주자로 진출
                for (int k=1; k<=9; k++){
                    if (status[k].first == true){ // 주자면
                        status[k].second += Inning[i][order[num]]; // 결과만큼 진출
                        if (status[k].second >= 4){ // 홈에 돌아오면
                            score++; // 점수 증가
                            status[k].first = false; // 더 이상 주자가 아님
                            status[k].second = 0; // 홈에 돌아왔으므로 상태 초기화
                        }
                    }
                }
            }
            else if (Inning[i][order[num]] == 0){ // 결과가 아웃
                out++;
                if (out >= 3){ // 아웃 세 번 이상이면
                    num++; // 다음 이닝에 시작할 타자 저장
                    if (num > 8){ // 9번 타자까지 쳤으면
                        num = 0; // 1번 타자부터 다시 반복
                    }
                    break; // 이닝 종료
                }
            }

            num++; // 한 타자의 점수 계산이 끝났으면 다음 타자로 이동
            if (num > 8 && out < 3){ // 9번 타자까지 공을 쳤는데 3 아웃이 발생하지 않은 상황이면
                num = 0; // 1번 타자부터 다시 반복
            }
        }
    }
    return score;
}

int checkMax(int n, vector<vector<int>> &Inning){
    vector<int> order = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // 타순을 저장할 배열
    int maxScore = 0; // 최고 점수 저장할 변수
    do {
        if (order[3] == 1){ // 4번째 타자가 1번 선수인 경우만 계산
            maxScore = max(maxScore, calcScore(n, Inning, order));
        }
    }
    while (next_permutation(order.begin(), order.end()));
    return maxScore;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> Inning (n+1, vector<int>(10)); // 9명의 타자에 대한 n 이닝 결과 저장
    for (int i=1; i<=n; i++){
        for (int j=1; j<=9; j++){
            cin >> Inning[i][j];
        }
    }
    cout << checkMax(n, Inning);
    return 0;
}