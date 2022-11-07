// 최단 경로: 10282 해킹
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair <int, int> ci;
const int INF = 2e9;

ci dijkstra(int start, int n, vector<vector<ci>> &com){
    ci ans = {0, 0};
    vector<int> time(n+1, INF);
    priority_queue<ci, vector<ci>, greater<ci>> pq; // 감염 시간, 컴퓨터
    time[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int currentTime = pq.top().first; // 현재까지 누적된 감염 시간
        int currentCom = pq.top().second; // 방문할 컴퓨터
        pq.pop();

        if (time[currentCom] < currentTime){
            continue;
        }

        for (int i=0; i<com[currentCom].size(); i++){
            int nextCom = com[currentCom][i].first;
            int nextTime = currentTime + com[currentCom][i].second;
            if (nextTime < time[nextCom]){
                time[nextCom] = nextTime;
                pq.push({nextTime, nextCom});
            }
        }
    }
    for (int i=1; i<=n; i++){
        if (time[i] != INF){ // time이 INF가 아니면 감염된 컴퓨터
            ans.first++; // 감염된 컴퓨터 수 증가
            ans.second = max(ans.second, time[i]); // 저장된 최댓값과 해당 컴퓨터의 감염 시간 비교 후 더 큰 값 저장
        }
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, d, c, a, b, s;
    cin >> t;
    while (t--)
    {
        cin >> n >> d >> c;
        vector<vector<ci>> com(n+1, vector<ci>(0)); // 인접 리스트
        while (d--) {
            cin >> a >> b >> s;
            com[b].push_back({a, s}); // 방향 그래프
        }
        ci ans = dijkstra(c, n, com); 
        cout << ans.first << ' ' << ans.second << '\n';
    }
}