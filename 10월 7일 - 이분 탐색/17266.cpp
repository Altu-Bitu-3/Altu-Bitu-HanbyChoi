// 이분 탐색 - 17266: 어두운 굴다리
#include <iostream>
#include <vector>
using namespace std;

int calcHeight(int n, int m, vector<int> &light){
    int height = 1;
    while (light[0] > height)
        {
            height++;
        }
    for (int i=0; i<m-1; i++){
        while ((light[i+1] - light[i] + 1) / 2 > height)
        {
            height++;
        }
    }
    while (n - light[m-1] > height)
    {
        height++;
    }
    return height;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> light(m, 0);
    for (int i=0; i<m; i++){
        cin >> light[i];
    }
    cout << calcHeight(n, m, light);
    return 0;
}