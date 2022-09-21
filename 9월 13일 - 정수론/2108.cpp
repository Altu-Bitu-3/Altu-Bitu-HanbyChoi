// 정수론: 2108 통계학
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int mean(int n, vector<int> &v){
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += v[i];
    }
    return round(float(sum)/n);
}

int mid(int n, vector<int> &v){
    sort(v.begin(), v.end()); // 오름차순 정렬
    return v[floor(n/2)]; // n은 홀수
}

int mode(int n, vector<int> &v){
    bool not_first = false;
    int mode_num = -4001;
    vector<int> cnt (8001, 0); // -4000 ~ 4000
    for (int i=0; i<n; i++){ // 빈도수 저장
        cnt[v[i] + 4000]++;
    }
    int max = *max_element(cnt.begin(), cnt.end());
    for (int i=0; i<8001; i++){
        if (cnt[i] != max){
            continue;
        } else{
            if (!not_first){
                not_first = true;
                mode_num = i-4000;
            } else {
                return i-4000;
            }
        }
    }
    return mode_num;
}

int range(vector<int> &v){
    sort(v.begin(), v.end()); 
    return v.back() - v.front();
}

int main(){
    int n;
    cin >> n;
    vector<int> num (n, 0);
    for (int i=0; i<n; i++){
        cin >> num[i];
    }
    cout << mean(n, num) << "\n" << mid(n, num) << "\n" << mode(n, num) << "\n" << range(num);
    return 0;
}