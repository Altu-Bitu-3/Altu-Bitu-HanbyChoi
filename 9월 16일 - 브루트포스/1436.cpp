// 브루트포스: 1436 영화감독 숌
#include <iostream>
#include <string>

using namespace std;

int getEndNumber(int n){ // n번째 종말의 수를 찾는 함수
    int num = 666 - 1;
    while (n > 0){
        string s = to_string(++num);
        if (s.find("666") != s.npos){ // 666을 찾았으면
            n--;
        }
    }
    return num;
}

int main(){
    int n;
    cin >> n;
    cout << getEndNumber(n);
    return 0;
}