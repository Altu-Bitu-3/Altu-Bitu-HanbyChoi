#include <iostream>
#include <vector>
using namespace std;

bool isEmpty(vector<int> &heap){
    return heap.size() == 1;
}

void push(vector<int> &heap, int x){
    int idx = heap.size();
    heap.push_back(x);
    while (idx > 1 && heap[idx] > heap[idx/2]) // 순서에 주의, 부모 노드 인덱스와 비교
    {
        swap(heap[idx], heap[idx/2]);
        idx /= 2;
    }
    return;
}

int pop(vector<int> &heap){
    int item = heap[1];
    heap[1] = heap[heap.size() - 1];
    heap.pop_back();
    int size = heap.size();
    int parent = 1, child = 2; // child는 왼쪽 자식 노드

    // 자식노드가 존재하는 동안 비교 진행
    while (child < size)
    {
        if(child + 1 < size && heap[child + 1] > heap[child]){
            child += 1;
        }
        if (heap[parent] < heap[child]){
            swap(heap[parent], heap[child]);
            parent = child;
            child = parent * 2;
        } else {
            break;
        }
    }
    return item;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;
    vector<int> heap_vec;
    heap_vec.push_back(0); //1번 인덱스부터 쓰기 위해 삽입

    while(n--){
        cin >> x;
        if (x==0){
            if (isEmpty(heap_vec)){
                cout << "0\n";
            } else {
                cout << pop(heap_vec) << '\n';
            }
        }
        else {
            push(heap_vec, x);
        }
    }
    return 0;
}