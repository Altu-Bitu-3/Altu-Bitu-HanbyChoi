// 정수론: 16563 어려운 소인수분해
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 5e6; // 5,000,000

vector<int> isPrime(){
    // n 이하의 수를 소인수분해하는 경로를 리턴
    vector<int> prime(MAX+1, 0);
    for (int i=2; i*i<=MAX; i++){
        if(prime[i] != 0){ // i가 소수가 아니면
            continue;
        }
        for (int j=i+1; j<=MAX; j+=i){ // i가 소수라면
            if(prime[j] == 0){ // j가 지워야 할 수라면
                prime[j] = i;
            }
        }
    }
    return prime;
}

int main(){
    int n;
    cin >> n;
    // 소수 경로 구하기
    auto prime = isPrime(); // vector<int>
    while (n--){
        int k;
        cin >> k;
        // prime[k] != 0이면 소수가 아님 - 소인수분해를 하면 됨
        while(prime[k] != 0){
            cout << prime[k] << ' ';
            k /= prime[k];
        }
        // k가 소수
        cout << k << '\n';
    }
    return 0;
}