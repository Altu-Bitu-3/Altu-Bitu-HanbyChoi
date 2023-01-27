// 정렬: 1758 - 알바생 강호
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, cnt = 0;
    long long max_tip = 0;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<>());
    for (int i=0; i<n; i++){
        if ((arr[i] - (++cnt - 1)) >= 0){
            max_tip += (arr[i] - (cnt - 1));
        }
    }
    cout << max_tip << "\n";
    return 0;
}