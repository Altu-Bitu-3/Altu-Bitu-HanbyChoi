// 브루트포스: 1544 사이클 단어
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

set<string> wordSet;

bool isSameWord(string a, string b){ // 두 단어가 같은지 확인하는 함수
    if (a.length() != b.length()){ // 두 단어의 길이가 다르면
        return false; // 같은 단어일 수 없음
    } else{ // 두 단어의 길이가 같으면
        for(int i=0; i<b.length(); i++){
            if (a == b){
                return true;
            } else { // 시계방향 rotate
                rotate(a.begin(), a.begin()+1, a.end());
            }
        }
    }
    return false;
}

bool check(string& word){ // 주어진 단어가 단어 집합에 있는지 확인하는 함수
    for (const string &src : wordSet){
        if (isSameWord(src, word)){
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string word;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> word;
        if (check(word) == false){ // 만약 이 단어가 아직 단어 집합에 없다면
            wordSet.insert(word); // 집합에 추가
        }
    }
    cout << wordSet.size();
    return 0;
}