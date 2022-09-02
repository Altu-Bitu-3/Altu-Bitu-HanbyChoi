#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;

void bubbleSort(int n){
    for (int i=0; i<n-1; i++){ //i: 전체 회전 수: n-1번
        // 0~n-1, 0~n-2, ..., 0~1 까지 정렬
        for (int j=0; j<n-1-i; j++){ //j: 각 회전당 비교 횟수
            if (arr[j] > arr[j+1]){
                /* 두 원소를 swap
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp; */
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    arr.assign(n, 0);

    for (int i=0; i<n; i++){
        cin >>arr[i];
    }

    bubbleSort(n);
    for (int i=0; i<n; i++){
        cout<<arr[i]<<"\n";
    }
    return 0;
}