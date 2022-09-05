#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int kor, eng, math;
};

// cmp가 true를 반환하면 왼쪽이 오른쪽보다 먼저 나오게 된다
/* bad 버전 비교함수
bool cmp(student a, student b){ // a가 b보다 먼저 나오는게 맞아? -> true -> 위치 변동 x / false면 swap
    if(a.kor == b.kor){ // 국어 점수가 같다면
        if (a.eng == b.eng){ // 영어 점수가 같다면
            if (a.math == b.math){ // 수학 점수가 같다면
                return a.name < b.name; // 이름이 사전순으로 증가하는 순서
            }
            return a.math > b.math; // 수학 점수가 감소하는 순서대로
        }
        return a.eng < b.eng; // 영어 점수가 증가하는 순서
    } 
    return a.kor > b.kor; // 국어 점수가 감소하는 순서대로 정렬
}*/

bool cmp(const student& a, const student& b){ // 같을 때 말고 다를 떄를 처리해주면 인덴테이션이 깊어지지 않음
    if (a.kor != b.kor){
        return a.kor > b.kor; // 국어 점수 감소 순
    }
    if (a.eng != b.eng){
        return a.eng < b.eng; // 영어 점수 증가 순
    }
    if (a.math != b.math){
        return a.math > b.math; // 수학 점수 감소 순
    }
    // 모든 점수가 같으면
    return a.name < b.name;
}

int main(){
    int n;
    cin >> n;
    vector<student> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;   
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i=0; i<n; i++){
        cout << arr[i].name << "\n";
    }
}