// 백트래킹: 15663 N과 M (9)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int SIZE = 8;

int n, m = 0;
vector<int> arr(SIZE); // 만들어진 수열 저장
vector<int> before_num(SIZE, 0); // 직전에 선택한 수 저장
vector<bool> check(SIZE); // 주어진 숫자 중 사용한 수를 저장

void backTracking(int cnt, vector<int> &num){
     if (cnt == m){ // m개의 수열 만든 경우 (기저 조건)
        for(int i=0; i<cnt; i++){ // 수열 출력 후 return
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    before_num[cnt] = 0;
    for (int i=0; i<n; i++){
        if (!check[i] && num[i] != before_num[cnt]){ // 현재 수열에 해당 수가 없다면 사용 가능
            before_num[cnt] = arr[cnt] = num[i];
            check[i] = true;
            backTracking(cnt + 1, num); // 다음 인덱스 호출
            // 다시 돌아왔을 때 원래 상태로 돌려놓기
            check[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    vector<int> num(n, 0); // 입력 받은 숫자 저장
    for (int i=0; i<n; i++){
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    backTracking(0, num); // 0번 인덱스부터 트래킹
    return 0;
}