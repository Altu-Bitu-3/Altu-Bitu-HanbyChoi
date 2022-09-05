// 정렬: 11728 배열 합치기
#include <iostream>
#include <vector>
using namespace std;
vector<int> A, B;
int p1 = 0, p2 = 0;
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    A.assign(n, 0);
    B.assign(m, 0);
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    for (int i=0; i<m; i++){
        cin >> B[i];
    }
    while (p1 < n && p2 < m){
        if (A[p1] < B[p2]){
            cout << A[p1++] << " ";
        }
        else{
            cout << B[p2++] << " ";
        }
    }
    while (p1 < n){
        cout << A[p1++] << " ";
    }
    while (p2 < m){
        cout << B[p2++] << " ";
    }
    return 0;
}