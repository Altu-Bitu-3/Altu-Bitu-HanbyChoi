// 동적 계획법: 9084 동전
#include <iostream>
#include <vector>
using namespace std;
int calc(vector<int> &arr, int m, int n){
    vector<int> dp(m+1, 0);
    dp[0] = 1;
    for (int i=0; i<n; i++){ // i번째 동전으로 끝나는 경우
        for (int j=arr[i]; j<=m; j++){ // arr[i] ~ m까지 dp
            dp[j] += dp[j - arr[i]];
        }
    }
    return dp[m];
}

int main(){
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n, 0);
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }
        cin >> m;
        cout << calc(arr, m, n) << '\n';
    }
    return 0;
}