// 맵과 셋: 9375 패션왕 신해빈
#include <iostream> // 표준 입출력 라이브러리 사용
#include <map> // map 라이브러리 사용

using namespace std; // 표준 입출력을 위한 namespace 선언

/**
 * 의상의 종류만 알면 된다.
 */

int main() { // main 함수에서 연산 수행
    int t, n; // 테스트 케이스 수를 저장할 변수 t와 각 테스트 케이스에서 해빈이가 가진 의상 수를 저장할 변수 n 선언
    string clothes, kind; // 의상의 이름과 의상의 종류를 저장할 두 string형 변수 선언

    cin >> t; // 테스트 케이스 수 입력 받음
    while (t--) { // 테스트 케이스 수만큼 연산을 반복
        map<string, int> m; // string형 key와 int형 value를 갖는 map m 선언

        //입력
        cin >> n; // 해빈이가 가진 의상 수 n 입력 받음
        while (n--) { // 의상 수 n 만큼 연산을 반복
            cin >> clothes >> kind; // 순서대로 의상의 이름과 종류를 입력 받음
            m[kind]++; // 해당 의상의 종류를 key로 하고 value값을 하나 증가시켜 의상의 수를 표현
        }

        
        int result = 1; // 결과를 담을 변수 선언
        for (auto iter = m.begin(); iter != m.end(); iter++) { // map을 처음부터 끝까지 반복자 iter를 통해 순회
            result *= iter->second + 1; // 각 의상 종류가 가진 의상 수(map의 value) + 1만큼 곱해서 result 계산 - 그 의상 종류를 입지 않는 경우를 고려하여 + 1 해준 것
        }

        //출력
        cout << result - 1 << '\n';  //알몸인 경우 제외(-1)한 결과 출력
    }
}