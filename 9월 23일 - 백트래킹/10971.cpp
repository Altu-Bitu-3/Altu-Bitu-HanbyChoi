// 백트래킹: 10971 외판원 순회 2
#include <iostream>
#include <vector>
using namespace std;

int n;
int min_sum = 1e7+1;
vector<bool> visited;
vector<vector<int>> arr;

void TSP(int cnt, int next, int sum){ // 방문 횟수, 다음에 방문할 도시, 지금까지 든 비용
    if (cnt == n && arr[next][0] != 0){ // n개 도시를 모두 방문했고 출발지로 돌아가는 길이 있으면
        min_sum = min(min_sum, sum + arr[next][0]); // 기존의 최솟값과 이 경로의 값 중 더 작은 것을 저장
        return;
    }
    for (int i=0; i<n; i++){ // next에서 i 도시로 가는 길이 있고 그 도시를 아직 방문하지 않았으며 현재 최솟값보다 방문 비용이 작은 경우
        if (arr[next][i] != 0 && !visited[i] && sum < min_sum){
            visited[i] = true; // i 도시 방문
            TSP(cnt + 1, i, sum + arr[next][i]);
            visited[i] = false; // i 도시 목록에서 제거
        }
    }
    return;
}

int main(){
    cin >> n;
    visited.assign(n, false);
    arr.assign(n, vector<int>(n, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    visited[0] = true; // 0번 도시에서 출발
    TSP(1, 0, 0);
    cout << min_sum;
    return 0;
}