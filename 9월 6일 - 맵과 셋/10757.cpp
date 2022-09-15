// 맵과 셋: 10757 큰 수 A+B
//벡터 사용
#include <iostream> // 입출력 라이브러리 사용
#include <vector> // 벡터 라이브러리 사용
using namespace std; // 표준 입출력을 위한 namespace 선언

/*
    매개변수에 &를 붙이면 원본을 참조하게 됩니다.
    **이 문제에서는 굳이 참조자를 사용할 필요는 없지만, C++에서는 주로 &를 붙입니다**
*/
vector<int> calcPlus(string &a, string &b) { // 큰 수 A와 B를 더하기 위한 함수 - 벡터를 반환, 인자로 string 변수 a와 b의 원본을 참조
    int idx_a = a.size() - 1; // a의 일의 자리 인덱스
    int idx_b = b.size() - 1; // b의 일의 자리 인덱스
    bool carry = false; // 올림수의 존재 여부
    vector<int> ans; // 두 수를 더한 결과를 저장하기 위한 벡터 ans

    while (idx_a >= 0 && idx_b >= 0) { // a와 b 둘 중 하나의 숫자(자릿수)가 모두 소진될 때까지 연산을 반복
        int num = (a[idx_a--] - '0') + (b[idx_b--] - '0'); // 문자를 숫자로 바꾸어 더하기, 그리고 인덱스 변경

        num += carry;            // num에 carry 더해주기. (carry는 어차피 1 아니면 0)
        carry = num / 10;        // num의 값이 10이상이면 carry가 1, 아니면 0
        ans.push_back(num % 10); // 올림을 제외한 값만 스택에 push
    }

    // a에서 남은 숫자 반영
    while (idx_a >= 0) { // a에 남은 수가 없을 때까지
        int num = a[idx_a--] - '0'; // 문자를 숫자로 바꾸어 더하고 인덱스 변경

        num += carry; // num에 carry를 더해줌 - 올림수가 있다면 +1, 아니면 +0
        carry = num / 10; // carry를 구함 - num의 값이 10이상이면 carry가 1, 아니면 0
        ans.push_back(num % 10); // 벡터의 맨 끝에 num 삽입 - 여기서는 올림수를 무시하고 % 10 한 결과만 삽입
    }

    // 남은 올림 확인
    if (carry) // 남은 올림이 있다면
        ans.push_back(1); // 벡터의 맨 끝에 올림 1 삽입

    return ans; // 두 수를 더한 결과가 담긴 ans 벡터 반환
}

int main() { // main 함수에서 calcPlus 함수 호출을 통해 연산
    ios::sync_with_stdio(0); // c와 c++의 표준 stream 동기화 비활성화 - 입출력 속도 향상 but c++의 입출력만 사용 가능
    cin.tie(0); // cin과 cout을 묶어주지 않음 - 입출력 시간 절약

    string a, b; // 두 큰 수를 입력 받을 string형 변수 a와 b 선언
    vector<int> ans; // 두 수를 더한 결과를 저장할 벡터 ans 선언

    //입력
    cin >> a >> b; // 입력된 결과를 순서대로 a와 b로 저장, 입력은 공백 혹은 줄바꿈으로 구분

    //연산
    if (a.length() < b.length()) // b의 길이가 더 길다면
        swap(a, b); // a와 b를 swap - a에 더 길이가 긴 숫자가 저장되도록 함

    ans = calcPlus(a, b); // calcPlus 함수를 호출하여 ans에 a와 b를 더한 결과를 저장

    //출력
    while (!ans.empty()) { // 벡터에 남은 숫자가 없을 때까지 반복
        cout << ans.back(); // 벡터의 맨 뒤에서부터 하나씩 출력
        ans.pop_back(); // 벡터 맨 뒤에 있는 숫자를 제거
    }
}