#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> child;
vector<int> parent;
vector<int> subSize;

void makeTree(int currentNode, int parentNode){
    for (int node: graph[currentNode]){
        if (node != parentNode){
            child[currentNode].push_back(node);
            parent[node] = currentNode;
            makeTree(node, currentNode);
        }
    }
}

void countSubtreeNodes(int currentNode){
    subSize[currentNode] = 1;
    for (int node: child[currentNode]){
        countSubtreeNodes(node);
        subSize[currentNode] += subSize[node];
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, r, q, u, v;
    cin >> n >> r >> q;
    graph.assign(n+1, vector<int>(0));
    child.assign(n+1, vector<int>(0));
    parent.assign(n+1, 0);
    subSize.assign(n+1, 0);
    for (int i=0; i<n-1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    makeTree(r, -1);
    countSubtreeNodes(r);
    while (q--)
    {
        cin >> u;
        cout << subSize[u] << '\n';
    }
    return 0;
}