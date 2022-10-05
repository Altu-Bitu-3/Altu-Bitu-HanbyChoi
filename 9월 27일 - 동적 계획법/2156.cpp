// 동적 계획법: 2156 포도주 시식
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int calc(vector<int> &amount, int n){
    vector<int> dp(n+1, 0); // n번째 잔이 마지막 잔일 때 최댓값 (n은 0부터 시작)
    dp[1] = amount[1];
    if (n > 1){
        dp[2] = amount[1] + amount[2];
        for (int i=3; i<=n; i++){ // i번째 잔을 마지막으로 선택하는 경우
            dp[i] = max({dp[i-1], dp[i-2] + amount[i], dp[i-3] + amount[i-1] + amount[i]}); // 직전 두 잔(이번 잔 x) / 전전 잔 + 지금 잔 / 전전전 잔 + 직전 잔 + 지금 잔
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    vector<int> amount(n+1, 0);
    for (int i=1; i<=n; i++){
        cin >> amount[i];
    }
    cout << calc(amount, n);
    return 0;
}