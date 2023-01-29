//정수론: 2609 최대공약수와 최소공배수
#include <iostream>
using namespace std;

// O(n)으로 최대공약수 구하기
int gcd(int a, int b){
    for (int i=min(a, b); i>0; i--){
        // 공약수인지 확인
        if (a % i == 0 && b % 1 == 0){
            return i;
        }
    }
    return 1;
}

// 유클리드 호제법
int gcdRecursion(int a, int b){
    if (b == 0){
        return a;
    }
    return gcdRecursion(b, a % b);
}

int main(){
    int a, b;
    cin >> a >> b;
    int g = gcdRecursion(max(a, b), min(a, b)); // 최대공약수
    int l = a * b / g; // 최소공배수
    cout << g << '\n' << l << '\n';
    return 0;
}