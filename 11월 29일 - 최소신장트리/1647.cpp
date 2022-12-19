// 최소신장트리: 1647 도시 분할 계획
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> tp;
vector<int> parent;

int findParent(int x){
    if (parent[x] < 0){
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

bool unionNodes(int x, int y){
    int px = findParent(x);
    int py = findParent(y);
    if (px == py){
        return false;
    }
    if (parent[px] < parent[py]){
        parent[px] += parent[py];
        parent[py] = px;
    } else {
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

int kruskal(int n, vector<tp> &vertex){
    int sum = 0, cnt = 0, max_cost = 0;
    for (auto [w, n1, n2]:vertex){
        if (!unionNodes(n1, n2)){ // 부모가 같으면
            continue;
        }
        // 부모가 다르면
        sum += w; // 가중치 합산
        max_cost = max(max_cost, w);
        cnt++;

        if (cnt == n-1){ // 필요한 간선을 모두 찾은 경우
            return (sum - max_cost); // 가중치의 합 반환
        }
    }
    return 0; // ST 못 만든 경우
}

int main(){
    int n, m, a, b, c;
    cin >> n >> m;
    vector<tp> vertex;
    parent.assign(n+1, -1);
    while (m--)
    {
        cin >> a >> b >> c;
        vertex.push_back({c, a, b}); // 가중치, a집, b집
    }
    sort(vertex.begin(), vertex.end());
    cout << kruskal(n, vertex);
    return 0;
}