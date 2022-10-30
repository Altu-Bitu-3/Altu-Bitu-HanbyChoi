// DFS & BFS: 11725 트리의 부모 찾기
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;
bool visited[MAX]; // 방문 여부
int parent[MAX]; // 부모 노드
vector<int> tree[MAX]; // 트리

void DFS(int num){ // 재귀로 구현
    int next;
    visited[num] = true; // 방문 표시
    for (int i=0; i<tree[num].size(); i++){ // 해당 노드에 연결된 노드만큼
        next = tree[num][i]; // 이번에 방문할 노드
        if(!visited[next]){ // 아직 방문 안 했으면
            parent[next] = num; // 부모 노드 정보 저장
            DFS(next);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    DFS(1); // 루트 노드부터 탐색
    for (int i=2; i<=n; i++){ // 2~n번 노드의 부모 출력
        cout << parent[i] << '\n';
    }
    return 0;
}