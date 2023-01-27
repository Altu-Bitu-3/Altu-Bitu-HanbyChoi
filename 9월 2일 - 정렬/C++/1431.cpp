// 정렬: 1431 - 시리얼 번호
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b){
    if (a.length() != b.length()){ // 둘의 길이가 다르면
        return (a.length() < b.length()); // 짧은 것이 먼저 옴
    } else{ // 둘의 길이가 같으면
        int a_sum = 0, b_sum = 0;
        for (int i=0; i<a.length(); i++){
            if (isdigit(a[i]) != 0){ // 해당 자리의 시리얼 번호가 숫자라면
                a_sum += (a[i] - '0'); // 문자를 정수로 변환하여 더해주기
            }
        }
        for (int i=0; i<b.length(); i++){
            if (isdigit(b[i]) != 0){ // 해당 자리의 시리얼 번호가 숫자라면
                b_sum += (b[i] - '0'); // 문자를 정수로 변환하여 더해주기
            }
        }
        if (a_sum != b_sum){ // 자리수의 합이 다르면
            return (a_sum < b_sum); // 작은 합을 가지는 것이 먼저 옴
        } else { // 자리수의 합도 같으면
            return (a < b); // 사전순으로 비교
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> serial(n, "");
    for (int i=0; i<n; i++){
        cin >> serial[i];
    }
    sort(serial.begin(), serial.end(), cmp);
    for (int i=0; i<n; i++){
        cout << serial[i] << "\n";
    }
    return 0;
}