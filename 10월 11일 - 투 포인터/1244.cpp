// 투 포인터: 1244 스위치 켜고 끄기
#include <iostream>
#include <vector>
using namespace std;

void switchFlip(vector<int> &switchOn, int i){
    if (switchOn[i] == 0){
        switchOn[i] = 1;
    } else {
        switchOn[i] = 0;
    }
}

void boySwitch(vector<int> &switchOn, int num, int n){
    for (int i=0; i<n; i++){
        if ((i+1) % num == 0){ // 스위치 번호가 자기가 받은 수의 배수이면
            switchFlip(switchOn, i);
        }
    }
}

void girlSwitch(vector<int> &switchOn, int num, int n){
    int cnt = 1, left = 0, right = 0;
    switchFlip(switchOn, num - 1);
    while (true)
    {
        left = num - cnt - 1;
        right = num + cnt - 1;
        if (left >= 0 && right < n && switchOn[left] == switchOn[right]){
            switchFlip(switchOn, left);
            switchFlip(switchOn, right);
            cnt++;
        } else {
            break;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, gender, num;
    cin >> n;
    vector<int> switchOn(n, 0);
    for (int i=0; i<n; i++){
        cin >> switchOn[i];
    }
    cin >> m;
    while (m--)
    {
        cin >> gender >> num;
        if (gender == 1){ // 남학생이면
            boySwitch(switchOn, num, n);
       } else if (gender == 2){ // 여학생이면
            girlSwitch(switchOn, num, n);
       }
    }
    for (int i=0; i<n; i++){
        cout << switchOn[i] << " ";
        if ((i+1) % 20 == 0){
            cout << '\n';
        }
    }
    return 0;
}