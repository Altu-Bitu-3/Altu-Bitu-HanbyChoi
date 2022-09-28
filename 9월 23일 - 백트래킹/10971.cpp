// 백트래킹: 10971 외판원 순회 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int min_sum = 10000001;

void TSP(int start, int next, int sum, vector<int> &visited, vector<vector<int>> &arr){
    if (visited.size() == n && arr[next][start] != 0){ // n개 도시를 모두 방문했고 출발지로 돌아가는 길이 있으면
        min_sum = min(min_sum, sum + arr[next][start]); // 기존의 최솟값과 이 경로의 값 중 더 작은 것을 저장
        return;
    }
    for (int i=0; i<n; i++){ // next에서 i 도시로 가는 길이 있고 그 도시를 아직 방문하지 않았으며 현재 최솟값보다 방문 비용이 작은 경우
        if (arr[next][i] != 0 && find(visited.begin(), visited.end(), i) == visited.end() && sum < min_sum){
            visited.push_back(i); // i 도시 방문
            TSP(start, i, sum + arr[next][i], visited, arr);
            visited.pop_back(); // i 도시 목록에서 제거
        }
    }
    return;
}

int main(){
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=0; i<n; i++){
        vector<int> visited = {i};
        TSP(i, i, 0, visited, arr); // 0번 도시에서 출발하는 경우부터 n-1번 도시에서 출발하는 경우까지 탐색
    }
    cout << min_sum;
    return 0;
}