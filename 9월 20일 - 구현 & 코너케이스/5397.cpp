// 구현 & 코너케이스: 5397 키로커
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string findPwd(string s){
    stack<char> left, right;
    string leftStr = "", rightStr = "", answer;
    for(int i=0; i<s.length(); i++){
        if (s[i] == '<'){ // 왼쪽 스택에 있는 문자를 오른쪽 스택으로 이동
            if (!left.empty()){
                right.push(left.top());
                left.pop();
            }
        } else if (s[i] == '>'){ // 오른쪽 스택에 있는 문자를 왼쪽 스택으로 이동
            if (!right.empty()){
                left.push(right.top());
                right.pop();
            }
        } else if (s[i] == '-'){ // 왼쪽 스택에 있는 문자를 하나 삭제
            if (!left.empty()){
                left.pop();
            }
        } else { // 왼쪽 스택에 문자 하나 추가
            left.push(s[i]);
        }
    }
    for (int i=0; i<left.size(); i++){
        leftStr.push_back(left.top());
        left.pop();
    }
    reverse(leftStr.begin(), leftStr.end());
    for (int i=0; i<right.size(); i++){
        rightStr.push_back(right.top());
        right.pop();
    }
    answer = leftStr + rightStr;
    return answer;
}

int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        cout << findPwd(s) << '\n';
    }
    return 0;
}