// 브루트포스: 2231 분해합
#include <iostream>

using namespace std;

int findConstructor(int n){
    int sum;
    for (int i=1; i<n; i++){
        int temp = i; // 반복문 내에서 i를 변경하지 않기 위해 임시 변수 사용
        sum = i;
        while (temp > 0){ // 각 자리 수 더하기
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == n){
            return i; // 가장 작은 생성자 리턴
        }
    }
    return 0; // 생성자가 없는 경우
}

int main(){
    int n;
    cin >> n;
    cout << findConstructor(n);/// 연산 결과
    return 0;
}