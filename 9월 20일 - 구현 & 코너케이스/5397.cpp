// 구현 & 코너케이스: 5397 키로커
#include <iostream> // c++ 표준 입출력 헤더
#include <stack> // 스택 사용을 위한 헤더
#include <vector> // 벡터 사용을 위한 헤더

using namespace std; // 표준 네임스페이스 선언

string stackToString(stack<char>& left, stack<char>& right) { // 두 스택을 하나의 문자열로 합치기 위해 두 스택의 주소를 인자로 받음
    // 두 개의 스택을 하나의 문자열로 합치는 함수

    string password; // 두 스택을 합친 비밀번호를 저장할 문자열
    // 왼쪽 스택의 top 부터 하나씩 오른쪽 스택에 삽입
    while (!left.empty()) { // 왼쪽 스택이 빌 때까지
        right.push(left.top()); // 왼쪽 스택의 원소를 오른쪽 스택에 삽입
        left.pop(); // 왼쪽 스택 탑을 오른쪽에 삽입 후 왼쪽 스택에서는 지움
    }
    // 현재 오른쪽 스택의 top에는 password의 앞글자부터 저장된 상태
    while (!right.empty()) { // 오른쪽 스택이 빌 때까지
        password += right.top(); // 오른쪽 스택의 문자를 password 문자열로 옮김
        right.pop(); // 옮긴 문자는 스택에서 제거
    }
	return password; // 완성된 문자열 리턴
}

string findPassword(string log) { // 입력에서 비밀번호를 구하는 함수
    stack<char> left;   //커서 이전 내용을 저장할 스택
    stack<char> right;  //커서 이후 내용을 저장할 스택

    for (int i = 0; i < log.length(); i++) { // 입력의 길이만큼 반복
        switch (log[i]) { // 입력된 문자에 따라 다르게 처리
        case '-':  //현재 커서 앞에 있는 글자 삭제(백스페이스)
            if (!left.empty()) { // 왼쪽 스택이 비어있지 않다면
                left.pop(); // 왼쪽 스택 탑의 원소 삭제
            }
            break; // 해당 경우에 대한 연산 종료
        case '<':  // 커서를 왼쪽으로 이동
            if (!left.empty()) { // 왼쪽 스택이 비어있지 않다면
                right.push(left.top()); // 왼쪽 스택 탑을 오른쪽 스택으로 옮김
                left.pop(); // 옮긴 왼쪽 스택 탑 원소 삭제
            }
            break; // 해당 경우에 대한 연산 종료
        case '>':  //커서를 오른쪽으로 이동
            if (!right.empty()) { // 오른쪽 스택이 비어있지 않다면
                left.push(right.top()); // 오른쪽 스택 탑을 왼쪽 스택으로 옮김
                right.pop(); // 옮긴 오른쪽 스택 탑 원소 삭제
            }
            break; // 해당 경우에 대한 연산 종료
        default:  //문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 left에 삽입
            left.push(log[i]); // 왼쪽 스택에 해당 문자 삽입
        }
    }

    string password = stackToString(left, right); // 왼쪽 스택과 오른쪽 스택에 있는 문자를 합쳐 비밀번호 문자열 생성
    return password; // 완성된 비밀번호 문자열 리턴
}

/**
 * [키로거]
 *
 * 해당 풀이는, 글자 삽입 삭제 시 이동시키는 과정에서 생기는 코너케이스를 해결하기 위해 커서를 기준으로 왼쪽, 오른쪽으로 나눠서 값을 저장함
 *
 * 1. 커서 앞의 글자를 지울 때, 글자가 없는 경우 주의
 * 2. 커서를 왼쪽으로 이동할 때, 이미 가장 왼쪽에 커서가 있는 경우 주의
 * 3. 커서를 오른쪽으로 이동할 때, 이미 가장 오른쪽에 커서가 있는 경우 주의
 */

int main() { // 메인 함수에서 입출력 및 함수 호출
    int tc; // 테스트 케이스 숫자 저장할 변수
    //입력
    cin >> tc; // 테스트 케이스 수 입력

    // 출력
    while(tc--) { // 테스트 케이스 수만큼 반복
        string s; // 입력 받은 문자열 저장할 변수
        cin >> s; // 테스트 케이스 문자열 입력
        cout << findPassword(s) << '\n'; // 입력 받은 문자열을 함수의 인자로 넘겨 비밀번호 문자열 구하고 출력
    }
    return 0; // 메인함수 종료
}