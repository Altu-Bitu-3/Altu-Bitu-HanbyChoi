// 투 포인터: 6159 코스튬 파티
#include <iostream>
#include <vector>
using namespace std;

int countPair(vector<int> &cow, int n, int s){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if ((cow[i] + cow[j]) <= s){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int n, s;
    cin >> n >> s;
    vector<int> cow(n, 0);
    for(int i=0; i<n; i++){
        cin >> cow[i];
    }
    cout << countPair(cow, n, s);
    return 0;
}