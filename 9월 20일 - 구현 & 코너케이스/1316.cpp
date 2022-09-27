// 구현 & 코너케이스: 1316 그룹 단어 체커
#include <iostream>
#include <vector>
using namespace std;
void groupCheck(string s, int& cnt){
    vector<int> alnum (26, 0);
    alnum[s[0] - 'a']++;
    for (int i=1; i<s.length(); i++){
        if (s[i-1] != s[i] && alnum[s[i] - 'a'] > 0){ // 이전에 해당 알파벳이 나온 적 있고 직전 알파벳이 같은 알파벳이 아니라면
            return; // 그룹 단어가 아니므로 함수 종료
        } else {
            alnum[s[i] - 'a']++;
        }
    }
    cnt++; // 그룹 단어의 개수 +1
    return;
}

int main(){
    int n, cnt = 0;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        groupCheck(s, cnt);
    }
    cout << cnt;
    return 0;
}