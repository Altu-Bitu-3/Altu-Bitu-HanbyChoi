// 스택, 큐, 덱: 11866 요세푸스 문제 0
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k, cnt = 1;
    queue<int> q;
    cin >> n >> k;
    cout << "<";
    for (int i=1; i<=n; i++){
        q.push(i);
    }
    while (q.size() > 1){
        if (cnt % k != 0){
            q.push(q.front()); // 맨 위에 있는 수를 맨 뒤로 옮기기
            q.pop(); // 맨 뒤로 옮겼으므로 맨 앞에 남아있는 수는 삭제
        } else if (cnt % k == 0){ // k번째 수에 대해
            cout << q.front() << ", ";
            q.pop(); // k번째 수를 제거
        }
        cnt++;
    }
    cout << q.front() << ">";
    return 0;
}