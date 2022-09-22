// 브루트포스: 14889 스타트와 링크
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_DIFF = 1000;
void permutation(){
    int arr[] = {1, 2, 3, 4};
    do{
        for(int i=0; i<4; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }while (next_permutation(arr, arr+4));
}

void combination(){
    int arr[] = {1, 2, 3, 4};
    bool temp[] = {false, false, true, true};
    do{
        for(int i=0; i<4; i++) {
            if (temp[i]){
                cout << arr[i] << ' ';
            }
        }
        cout << '\n';
    }while (next_permutation(temp, temp+4));   
}

int calcDiff(int n, vector<bool> &is_teamA){
    vector<int> teamA;
    vector<int> teamB;
    for(int i=0; i<n; i++){
        if(is_teamA[i]){
            teamA.push_back(i);
        } else {
            teamB.push_back(i);
        }
    }
    return 0;
}

int findMinDiff(int n){
    //1. 팀 나누기 / 2. 각 팀 마다 능력치 합 구하기 / 3.  능력치 차이의 최소 기록하기
    vector<bool> is_teamA(n, true);
    for (int i=0; i<n/2; i++){
        is_teamA[i] = false;
    }

    int answer = MAX_DIFF;

    do{
        // 팀이 나눠진 상황 - 팀 간의 능력치 차이 구하고 최솟값을 기록
        answer = min(answer, calcDiff(n, is_teamA));
    } while(next_permutation(is_teamA.begin(), is_teamA.end()));
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> power(n, vector<int>(n, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> power[i][j];
        }
    }
    // 브루트포스로 팀을 나눈 후 나눌 수 있는 차이의 최솟값을 기록
}