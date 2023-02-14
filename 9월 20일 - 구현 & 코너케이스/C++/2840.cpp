// 구현 & 코너케이스 2840 행운의 바퀴
#include <iostream>
#include <vector>
using namespace std;

int index = 0;
bool isNone = false; // 주어진 케이스에 해당하는 바퀴가 없으면 true

void findWheel(int n, int num, char alphabet, vector<char> &wheel){
    index = (index + num) % n;
    if (wheel[index] == ' ' || wheel[index] == alphabet){
        wheel[index] = alphabet;
    } else {
        isNone = true;
    }
    return;
}

int main(){
    int n, k, num;
    char alphabet;
    cin >> n >> k;
    vector<char> wheel(n, ' ');
    vector<int> alnum(26, 0);
    while (k--)
    {
        cin >> num >> alphabet;
        if(!isNone){
            findWheel(n, num, alphabet, wheel);
        } else{
            break;
        }
    }

    // 완성된 바퀴에 중복된 문자가 있는지 탐색
    for (int i=0; i<n; i++){
        if (wheel[i] == ' '){
            continue;
        }
        alnum[wheel[i]-'A']++;
        if (alnum[wheel[i]-'A'] > 1){
            isNone = true;
            break;
        }
    }

    if (isNone){
        cout << '!';
        return 0;
    }
    for (int i=0; i<n; i++){
        index %= n;
        if (wheel[index] == ' '){
            cout << '?';
        } else {
            cout << wheel[index];
        }
        index--;
        if(index < 0){
            index += n;
        }
    }
    return 0;
}