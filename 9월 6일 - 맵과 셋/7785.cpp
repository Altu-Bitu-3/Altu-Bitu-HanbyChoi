// 맵과 셋: 7785 회사에 있는 사람
#include <iostream>
#include <set>
using namespace std;
int main(){
    set<string, greater<string>> people;
    int n;
    string name, cmd;
    cin >> n;
    while(n--){
        cin >> name >> cmd;
        if(cmd == "enter"){
            people.insert(name);
        } else if (cmd == "leave"){
            people.erase(name);
        }
    }
    for (auto iter:people){
        cout << iter << '\n';
    }
    return 0;
}