// 스택, 큐, 덱: 17299 오등큰수
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, input;
    cin >> n;
    vector<int> num, cnt;
    stack<int> compare;
    
    for (int i=0; i<n; i++){ // num
        cin >> input;
        num.push_back(input);
    }
    for (int i=0; i<n; i++){ // count
        cnt.push_back(count(num.begin(), num.end(), num[i])); 
    }
    for (int i=0; i<n; i++){
        for (int j=n-1; j>i; j--){ // 맨 오른쪽 수부터 검사
            if (cnt[i] < cnt[j]){ // 기준이 되는 수보다 등장 횟수가 더 크면
                compare.push(num[j]); // 스택에 삽입
            }
        }
        if (compare.empty()){
            cout << "-1 ";
        } else{
            cout << compare.top() << " "; // 등장 횟수가 큰 수 중 가장 왼쪽에 있는 수 ngf에 저장
                while(!compare.empty()){
                    compare.pop();
                }
        }
    }
    return 0;
}