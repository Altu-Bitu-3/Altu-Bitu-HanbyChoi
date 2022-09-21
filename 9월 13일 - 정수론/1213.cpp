// 정수론: 1213 펠린드롬 만들기
#include <iostream> // c++ 표준 입출력 헤더
#include <vector> // vector 사용을 위한 헤더
#include <algorithm> //reverse() 함수 사용을 위한 헤더
using namespace std; // 표준 네임스페이스 선언

const int MAX_ALPHA=26; // 알파벳 대문자 종류 개수

vector<int> countAlpha(string input) { // 사용된 알파벳 개수 세기 위한 함수

    vector<int> alpha(MAX_ALPHA, 0);  // 문자열에 대해 사용된 문자별 개수 저장할 vector

    for(int i=0; i<input.length(); i++) { // input 문자열 길이만큼 연산
        //i번째 문자(input[i])가 'A'라면 아스키코드(혹은 유니코드)는 65
        //'A'의 개수를 0번째 인덱스에, 'Z'의 개수를 25번째 인덱스에 저장
        alpha[input[i]-'A']++; // 빼기 연산을 이용해 인덱스 지정
    }

    return alpha; // 알파벳 개수를 저장한 벡터 반환
}

string makePalindrome(string input) { // 펠린드롬 생성 함수
    
    vector<int> alpha = countAlpha(input); // 위에 선언한 함수를 이용해 알파벳 개수 벡터에 저장
    string center="", str="", ans;   // center: 가운데에 위치할 문자 저장, str: 앞뒤로 사용할 문자열, ans: 완성한 문자열 (str/center/뒤집은 str)
    
    for(int i=0; i<MAX_ALPHA; i++) { //'A'부터 'Z'까지 사용된 알파벳 개수 파악

        if(alpha[i]%2) { // 해당 알파벳 개수가 홀수라면 (연산 결과가 1 -> true)
            if(center.length()) { // 앞선 연산에서 center에 저장된 문자가 1개 이상이라면 true (즉 홀수인 알파벳이 2개 이상이라면)
                return "I'm Sorry Hansoo"; // 펠린드롬을 만들 수 없으므로 sorry 반환
            }

            center=(char)(i+'A'); // 알파벳 개수가 홀수고 center에 저장된 문자가 아직 존재하지 않는다면 해당 알파벳을 center에 저장
        } 

        for(int j=0; j<alpha[i]/2; j++) { // (사용된 알파벳의 개수/2)만큼 str에 추가
            //'A'부터 'Z' 순으로 for문을 통과하므로 알파벳 순으로 str 저장
            str += (char)(i + 'A'); // i번째 알파벳을 (사용된 알파벳의 개수/2)만큼 str에 추가
        }
    }

    ans = str + center; // 펠린드롬 문자열 생성 : str + center + (뒤집은 str)
    reverse(str.begin(), str.end()); // str 뒤집기
    ans += str; // 뒤집은 str까지 더해주기
    
    return ans; // 만들어진 펠린드롬 반환
}

int main() { // main 함수에서 실행
    string input, ans;   // 입력 받은 문자열 저장할 input, 결과 저장할 ans
    cin>>input; // 문자열 입력 받기

    ans = makePalindrome(input); // input을 인자로 하여 위에서 만든 펠린드롬 생성 함수 호출
    cout << ans; // 만들어진 문자열 출력
    return 0; // main 함수 종료
}