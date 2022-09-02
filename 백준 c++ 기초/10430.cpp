# include <iostream>
using namespace std;
int a, b, c;
int main(){
    cin >> a >> b >> c;
    cout << (a+b)%c << "\n" << ((a%c)+(b%c))%c << "\n" << (a*b)%c << "\n" << ((a%c)*(b%c))%c;
    return 0;
}