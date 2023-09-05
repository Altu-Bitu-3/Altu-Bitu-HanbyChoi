// 그리디: 3613 Java vs C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype> 
using namespace std;
int main(){
    bool is_bar = false;
    string str, ans;
    cin >> str;
    if (str.find("__") != string::npos || !isalpha(str[0]) || str[0] == '_' || isupper(str[0]) || str[str.length()-1] == '_'){
        cout << "Error!";
        return 0;
    }
    for (int i=1; i<str.length(); i++){
        if (isalpha(str[i]) || str[i] == '_'){
            continue;
        } else { // 알파벳 혹은 _가 아니면 종료
            cout << "Error!";
            return 0;
        }
    }
    if (find(str.begin(), str.end(), '_') == str.end()){ // _가 없으면 Java
        for (int i=0; i<str.length(); i++){
            if (isupper(str[i])){ // 대문자라면
                ans += '_';
                ans += tolower(str[i]);
            } else { // 소문자라면
                ans += str[i];
            }
        }
    } else { // _가 있으면 C++
        for (int i=0; i<str.length(); i++){
            if (isupper(str[i])){ // 대문자가 있으면 종료
                cout << "Error!";
                return 0;
            }
            if (str[i] == '_'){
                ans += toupper(str[i+1]);
                is_bar = true;
            } else {
                if (is_bar){
                    is_bar = false;
                    continue; // 이전 for문에서 이미 대문자로 변환하여 추가했으므로 스킵
                } else {
                    ans += str[i];
                }
            }
        }
    }
    cout << ans;
    return 0;
}