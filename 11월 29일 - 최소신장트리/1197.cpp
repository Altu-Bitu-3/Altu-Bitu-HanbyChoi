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

int kruskal(int v, vector<tp> &vertex){
    int sum = 0, cnt = 0;
    for (auto [w, n1, n2]:vertex){
        if (!unionNodes(n1, n2)){
            continue;
        }
        sum += w;
        cnt++;

        if (cnt == v-1){ // 필요한 간선을 모두 찾은 경우
            return sum;
        }
    }
    return 0; // ST 못 만든 경우
}

int main(){
    int v, e, a, b, c;
    cin >> v >> e;
    vector<tp> vertex;
    parent.assign(v+1, -1);
    while (e--)
    {
        cin >> a >> b >> c;
        vertex.push_back({c, a, b});
    }
    sort(vertex.begin(), vertex.end());
    cout << kruskal(v, vertex);
    return 0;
}