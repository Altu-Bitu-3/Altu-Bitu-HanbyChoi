// 백트래킹: 15650 N과 M (2)
#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 8;

// 재귀함수 사용 시 함수를 호출할 때마다 매개변수가 생성되므로 전역변수로 선언
int n, m;
vector<int> num(SIZE);

void backTracking(int cnt, int start){ // cnt: 수열의 인덱스, start: 현재 탐색 시작하는 원소 값
    if (cnt == m){ // m개의 수열 만든 경우 (기저 조건)
        for(int i=0; i<cnt; i++){ // 수열 출력 후 return
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i=start; i<=n; i++){
        num[cnt] = i;
        backTracking(cnt + 1, i + 1); // 다음 인덱스 호출
    }
}

int main(){
    cin >> n >> m;
    backTracking(0, 1); // 0번 인덱스부터 트래킹
    return 0;
}