// 그리디 알고리즘: 1931 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm> // sort 사용
using namespace std;

typedef pair<int, int> ci;

int getMaxCount(int n, vector<ci> &meeetings){
    int count = 0;
    int prev_end = 0;
    for (int i=0; i<n; i++){
        // 직전 회의가 끝나는 시간 이후로 시작하는 회의를 선택
        //auto [end, start] = meeetings[i]; // meetings의 첫 값이 end로, 두번째 값이 start로 들어감
        int end = meeetings[i].first;
        int start = meeetings[i].second;
        if (start >= prev_end){
            count++;
            prev_end = end;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<ci> meetings(n, {0, 0});
    // 정렬 기준: 빨리 끝나는 순서대로 / 빨리 시작하는 순서대로
    for(int i=0; i<n; i++){
        cin >> meetings[i].second >> meetings[i].first;
    }
    sort(meetings.begin(), meetings.end());
    cout << getMaxCount(n, meetings);
    return 0;
}