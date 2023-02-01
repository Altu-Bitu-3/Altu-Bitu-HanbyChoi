// 브루트포스: 2858 기숙사 바닥
#include <iostream>
#include <tuple>
using namespace std;

tuple<int, int> findSize(int r, int b){
    int calc_r = 0, calc_b = 0;
    for (int w=3; w<=2502; w++){
        for (int l=w; l<=2502; l++){
            calc_r = 2*l + 2*w - 4;
            calc_b = l*w - calc_r;
            if (calc_r == r && calc_b == b){
                return tuple<int, int>(l, w);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, b;
    cin >> r >> b;
    tuple<int, int> result = findSize(r, b);
    cout << get<0>(result) << " " << get<1>(result);
}