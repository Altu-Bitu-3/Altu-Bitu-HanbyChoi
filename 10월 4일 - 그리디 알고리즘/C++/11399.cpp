// 그리디 알고리즘: 11399 ATM
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, ans = 0;
    cin >> n;
    vector<int> time(n, 0);
    for (int i=0; i<n; i++){
        cin >> time[i];
    }
    sort(time.begin(), time.end());
    for (int i=0; i<n; i++){
        ans += time[i] * (n - i);
    }
    cout << ans;
    return 0;
}