// 트리: 1991 트리 순회
#include <iostream>
#include <map>
using namespace std;
map<char, pair<char, char>> tree;

// 전위 순회는 V - L - R
void preorder(char v){
    if (v == '.'){
        return;
    }
    cout << v;
    preorder(tree[v].first);
    preorder(tree[v].second);
}

// 중위 순회 L - V - R
void inorder(char v){
    if (v == '.'){
        return;
    }

    inorder(tree[v].first);
    cout << v;
    inorder(tree[v].second);
}

// 후위 순회 L - R - V
void postorder(char v){
    if (v == '.'){
        return;
    }
    postorder(tree[v].first);
    postorder(tree[v].second);
    cout << v;
}

int main(){
    int n;
    char root, left, right;
    cin >> n;
    while (n--)
    {
        cin >> root >> left >> right;
        tree[root] = {left, right};
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    return 0;
}