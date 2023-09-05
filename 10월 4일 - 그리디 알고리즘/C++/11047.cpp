// 그리디 알고리즘: 11047 동전 0
#include <iostream>
#include <vector>
using namespace std;

// 필요한 동전의 최솟값을 구하는 함수
int countCoin(int n, int k, vector<int> &coin){
    // 이미 오름차순으로 정렬되어 있으므로 정렬할 필요 없음
    int count = 0;
    int idx = n-1;
    while (k)
    {
        count += k / coin[idx];
        k %= coin[idx];
        idx--;
    }
    return count;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> coin(n, 0);
    for (int i=0; i<n; i++){
        cin >> coin[i];
    }
    // 연산 + 출력
    cout << countCoin(n, k, coin);
    return 0;
} 