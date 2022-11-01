// 우선순위 큐: 1927 최소 힙
#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--)
    {
        cin >> x;
        if (x == 0){
            if (!pq.empty()){
                cout << pq.top() << '\n'; // 배열에서 가장 작은 값 출력 후 제거
                pq.pop();
            } else {
                cout << 0 << '\n';
            }
        } else { // x는 자연수 - 배열에 x라는 값 추가
            pq.push(x);
        }
    }
    return 0;
}