// 정렬: 1026 보물
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, min_sum = 1e6, sum = 0; // 가능한 최대 합 유사치: 10,000 * 50 = 500,000
    cin >> n;
    vector<int> a(n, 0), b(n, 0);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>()); // b의 배치에 따라 a의 배치를 변화시킨다고 보면 b를 재배열한 것은 아님 (https://yabmoons.tistory.com/338)
    for(int i=0; i<n; i++){
        sum += a[i]*b[i];
    }
    /*
    sort(a.begin(), a.end()); // permutation 함수 사용을 위한 오름차순 정렬
    do{
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += a[i]*b[i];
        }
        min_sum = min(min_sum, sum);
        // 배열의 변화
    }while(next_permutation(a.begin(), a.end()));
    */

    cout << sum; 
    return 0;
}