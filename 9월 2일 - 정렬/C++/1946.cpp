// 정렬: 1946 신입사원
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> order;

int maxNum(vector<order>& arr){
    return max_num;
}

int main(){
    int t, n;
    cin >> t;
    while (t--)
    {   
        cin >> n;
        vector<order> arr(n, {0, 0});
        for (int i=0; i<n; i++){
            cin >> arr[i].first >> arr[i].second;
        }
        cout << maxNum() << "\n";
    }
    
    return 0;
}