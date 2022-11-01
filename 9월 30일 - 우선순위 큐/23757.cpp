// 우선순위 큐: 23757 아이들과 선물 상자
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n, m, temp = 0, temp_top;
    cin >> n >> m;
    priority_queue<int> present;
    vector<int> child(m, 0);
    // 선물 상자의 수 및 아이들의 수 입력
    for (int i=0; i<n; i++){
        cin >> temp;
        present.push(temp);
    }
    for (int i=0; i<m; i++){
        cin >> child[i];
    }

    for (int i=0; i<m; i++){ // 입력 중간에 함수가 종료되지 않도록 위의 for문과 구분하여 작성함
        temp_top = present.top(); // 현재 선물이 가장 많이 담겨있는 상자
        if (temp_top - child[i] >= 0){ // 자신이 원하는 만큼 선물을 가져갈 수 있다면
            present.pop();
            present.push(temp_top - child[i]); // 선물을 가져가고 남은 만큼 다시 최대 힙에 추가
        } else { // 자신이 원하는 만큼 선물을 가져갈 수 없다면 실망한다
            cout << '0';
            return 0;
        }
    }
    cout << '1';
    return 0;
}