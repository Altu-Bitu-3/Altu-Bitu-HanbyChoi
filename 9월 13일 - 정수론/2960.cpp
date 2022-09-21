// 정수론: 2960 에라토스테네스의 체
#include <iostream>
#include <vector>
using namespace std;

int findPrime(int n, int k){
    vector<bool> is_prime(n+1, true);
    //0과 1은 소수가 아니므로 false
    is_prime[0] = is_prime[1] = false;
    int cnt = 0; // 현재까지 지워진 수의 개수를 기록
    // 소수도 지워야 하므로 i <= n까지 돌림 - i가 소수인지 판단
    for (int i=2; i<=n; i++){
        if (!is_prime[i]){ // 이미 지워진 수라면
            continue;
        }
        // 이 문제에서는 i부터 지워야 하므로 j = i로 초기화
        for (int j=i; j<=n; j+=i){ // i가 소수라면 i의 배수를 순서대로 방문
            if (!is_prime[j]){
                continue;
            }
            is_prime[j] = false;
            if (++cnt == k){
                return j; // k번째 지워진 수를 return
            }
        }    
    }
    return -1;
}
int main(){
    int n, k;
    cin >> n >> k;
    cout << findPrime(n, k);
    return 0;
}