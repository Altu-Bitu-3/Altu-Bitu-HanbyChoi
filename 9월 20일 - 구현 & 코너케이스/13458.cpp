// 구현 & 코너케이스: 13458 시험 감독
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, b, c;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> b >> c;

    // 시험장이 최대 1000000 * 응시자수 최대 1000000
    // b, c가 1이면 long long
    long long answer = n;
    for (int i=0; i<n; i++){
        int count = arr[i] - b;
        if (count <= 0){ // 부감독 필요 없는 경우
            continue;
        }
        answer += count / c; // 남은 인원수에 맞춰 부감독관 배치
        if (count % c > 0){
            answer++; 
        }
    }
    cout << answer;
    return 0;
}