// 정렬: 11651 - 좌표 정렬하기 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct position{
    int x, y;
};

bool cmp(const position& a, const position& b){
    if (a.y != b.y){
        return a.y < b.y; // y 좌표가 증가하는 순
    } else { // 두 점의 y 좌표가 같은 경우
        return a.x < b.x; // x 좌표가 증가하는 순
    }
}

int main(){
    int n;
    cin >> n;
    vector<position> arr(n);
    for (int i=0; i<n; i++){
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i=0; i<n; i++){
        cout << arr[i].x << " " << arr[i].y << "\n";
    }
    return 0;
}