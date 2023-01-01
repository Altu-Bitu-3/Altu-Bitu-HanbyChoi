#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<double, int> ci;
const int INF = 1e5;

double prim(int n, int start, vector<vector<ci>> &graph){
    double sum = 0; // 간선 비용의 합
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<double> dist(n, INF);
    vector<bool> visited(n, false);

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()){
        auto[curr_w, curr] = pq.top();
        pq.pop();

        if(visited[curr]){ // 이미 확인했던 정점
            continue;
        }
        visited[curr] = true;
        sum += curr_w;

        for(auto[next_w, next]:graph[curr]){
            if (!visited[next] && next_w < dist[next]){ // 미방문 정점이면서 현재 기록된 간선보다 작은 가중치가 나온 경우
                pq.push({next_w, next});
                dist[next] = next_w;
            }
        }
    }
    return sum;
}

int main(){
    int n;
    double x, y;
    cin >> n;

    vector<pair<double, double>> star;
    vector<vector<ci>> graph(n, vector<ci>(0));

    for (int i=0; i<n; i++){
        cin >> x >> y;
        for (int j=0; j<i; j++){
            // 두 점 사이의 거리 구하기
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            double dist = sqrt(dx*dx + dy*dy);

            graph[i].push_back({dist, j});
            graph[j].push_back({dist, i});
        }
        star.push_back({x, y});
    }

    cout << fixed; // 고정 소수점 출력 방식 선택
    cout.precision(2);
    cout << prim(n, 0, graph);
    return 0;
}