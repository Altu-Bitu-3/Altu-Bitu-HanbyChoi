// 구현 & 코너케이스: 2607 비슷한 단어
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int cntWord(vector<string> &word){
    int wordCnt = 0;
    vector<vector<int>> alphabet (word.size(), vector<int>(26, 0));
    for (int i=0; i<word.size(); i++){ // 알파벳 개수 세기
        for (int j=0; j<word[i].length(); j++){
            alphabet[i][word[i][j] - 'A']++; // i번째 단어의 j번째 알파벳
        }
    }
    for (int i=1; i<word.size(); i++){
        if (abs((int)(word[0].length() - word[i].length())) > 1){ // 단어 길이가 2 이상 차이나면
            continue; // 비슷한 구성일 수 없음
        } else{
            int diff = 0;
            for (int j=0; j<26; j++){
                diff += (alphabet[0][j] - alphabet[i][j]);
            }
            if (abs(diff) <= 1){
                wordCnt++;
            }
        }   
    }
    return wordCnt;
}

int main(){
    int n;
    cin >> n;
    vector<string> word(n, "");
    for (int i=0; i<n; i++){
        cin >> word[i];
    }
    cout << cntWord(word);
    return 0;
}