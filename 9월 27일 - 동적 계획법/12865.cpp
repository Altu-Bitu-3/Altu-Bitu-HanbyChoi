// 동적 계획법: 12865 평범한 배낭
#include <iostream>
#include <vector>

using namespace std;

struct info {
    int w, v;
};

int knapsack_2(int n, int k, vector<info> &product){
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for (int i=1; i<=n; i++){
        for (int j=0; j<product[i].w ;)
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<info> product(n+1, {0, 0});
    for (int i=1; i<=n; i++){
        cin >> product[i].w >> product[i].v;
    }
}