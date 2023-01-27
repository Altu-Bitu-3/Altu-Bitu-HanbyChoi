#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    int n, m;
    string input;
    map<string, int> pocket_name; // 이름이 key, 번호가 value
    map<int, string> pocket_num; // 번호가 key, 이름이 value

    // 입력
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> input;
        pocket_name[input] = i;
        pocket_num[i] = input;
    }

    while (m--){
        cin >> input; // 입력이 섞여있는 경우 문자열로 입력 받는 것이 좋음
        if (isdigit(input[0])) { // 해당 문자가 숫자면 true 리턴
            int number = stoi(input); // 문자열을 숫자로 변환
            cout << pocket_num[number] << '\n'; // number에 대응하는 value(이름) 출력
            // cout << pocket_num[stoi(input)] -> 한번만 쓰이는 경우
        } else { // 입력이 문자열이라면
            cout << pocket_name[input] << '\n'; // input(이름)에 대응하는 value(번호) 출력
        }
    }

    return 0;
}