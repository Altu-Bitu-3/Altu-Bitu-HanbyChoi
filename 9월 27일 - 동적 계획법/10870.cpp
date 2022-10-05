// 동적 계획법: 10870 피보나치 수 5
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1, 0); // dp[0] = 0
    dp[1] = 1;
    for (int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
    return 0;
}