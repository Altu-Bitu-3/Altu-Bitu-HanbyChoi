// 정수론: 14490 백대열
#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b){
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main(){
    int a, b, gcd_num;
    string str;
    cin >> str;
    for(int i=0; i<str.size(); i++){
        if (str[i] == ':'){
            a = stoi(str.substr(0, i));
            b = stoi(str.substr(i+1, str.length()));
            break;
        }
    }
    gcd_num = gcd(max(a, b), min(a, b));
    cout << a/gcd_num << ":" << b/gcd_num;
    return 0;
}