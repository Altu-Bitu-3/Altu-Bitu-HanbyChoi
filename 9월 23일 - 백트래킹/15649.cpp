// 백트래킹: 15649 N과 M
#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 8;

// 재귀함수 사용 시 함수를 호출할 때마다 매개변수가 생성되므로 전역변수로 선언
int n, m;
vector<int> num(SIZE);
vector<bool> check(SIZE);

void backTracking(int cnt){ // cnt: 수열의 인덱스
    if (cnt == m){ // m개의 수열 만든 경우 (기저 조건)
        for(int i=0; i<cnt; i++){ // 수열 출력 후 return
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i=1; i<=n; i++){
        if (!check[i]){ // 현재 수열에 해당 수가 없다면 사용 가능
            num[cnt] = i;
            check[i] = true;
            backTracking(cnt + 1); // 다음 인덱스 호출
            // 다시 돌아왔을 때 원래 상태로 돌려놓기
            check[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    backTracking(0); // 0번 인덱스부터 트래킹
    return 0;
}