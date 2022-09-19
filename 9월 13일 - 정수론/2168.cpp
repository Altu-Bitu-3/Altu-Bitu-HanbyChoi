// 정수론: 2168 타일 위의 대각선
#include<iostream> // c++ 표준 입출력 헤더
using namespace std; // 표준 네임스페이스 선언

// 최대공약수를 구하는 함수(유클리드 호제법)
int gcd(int a, int b) { // 인자로 두 정수 a, b를 가짐
	if (b == 0) { // b가 0이 되면 더 연산할 수 없으므로
		return a; // a를 반환 (최대공약수)
	}
	return gcd(b, a % b); // 최대공약수 구하는 함수를 재귀 호출
}

int main() { // main 함수에서 실행
	int n, m; // 타일의 양변 길이 n, m
	cin >> n >> m; // n, m 값 입력 받기
	cout << n + m - gcd(n, m); 
    // 최대공약수가 1인 경우 꼭짓점을 지나지 않음 / 최대공약수가 1보다 큰 경우는 gcd가 1인 경우 여러 개가 반복되는 형태로 환원할 수 있음 
    // -> 대각선이 지나는 타일 수는 x + y - gcd(x, y)  
}