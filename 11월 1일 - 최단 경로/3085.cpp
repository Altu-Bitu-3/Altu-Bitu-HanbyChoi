// 최단 경로: 3085 사탕 게임
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<vector<char>> candy (50, vector<char>(50, ' '));

void findNum(){
    int cnt = 1;
    for (int i=0; i<n; i++){ // i행에 대한 탐색
        for (int j=0; j<n-1; j++){
            if (candy[i][j] == candy[i][j+1]){
                cnt++;
            } else {
                cnt = 1;
            }
            if (ans < cnt){
                ans = cnt;
            }
        }
        cnt = 1;
    }
    for (int i=0; i<n; i++){ // i열에 대한 탐색
        for (int j=0; j<n-1; j++){
            if (candy[j][i] == candy[j+1][i]){
                cnt++;
            } else {
                cnt = 1;
            }
            if (ans < cnt){
                ans = cnt;
            }
        }
        cnt = 1;
    }
}

void calCandy(){
    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (candy[i][j] != candy[i][j+1]){
                swap(candy[i][j], candy[i][j+1]); // 행에 대해 색이 다른 인접한 두 칸 교환
                findNum(); // 같은 색으로 이루어진 가장 긴 연속 부분 행/열을 고르고 사탕 먹기
                swap(candy[i][j], candy[i][j+1]); // 다시 원상복구
            }
            if (candy[j][i] != candy[j+1][i]){
                swap(candy[j][i], candy[j+1][i]); // 열에 대해 색이 다른 인접한 두 칸 교환
                findNum(); // 같은 색으로 이루어진 가장 긴 연속 부분 행/열을 고르고 사탕 먹기
                swap(candy[j][i], candy[j+1][i]); // 다시 원상복구
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> candy[i][j];
        }
    }
    calCandy();
    cout << ans;
    return 0;
}