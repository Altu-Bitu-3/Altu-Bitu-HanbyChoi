// 맵과 셋: 11723 집합
#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    set<int> s;
    int m, input;
    string cmd;
    cin >> m;
    while (m--){
        cin >> cmd;
        if (cmd == "add"){
            cin >> input;
            s.insert(input);
        } else if (cmd == "remove"){
            cin >> input;
            s.erase(input);
        } else if (cmd == "check"){
            cin >> input;
            if (s.find(input) == s.end()){ // input이 존재하지 않으면 true
                cout << "0\n";
            } else { 
                cout << "1\n"; 
            }
        } else if (cmd == "toggle"){
            cin >> input;
            if (s.find(input) == s.end()){
                s.insert(input);
            } else { 
                s.erase(input); 
            }
        } else if (cmd == "all"){
            for(int i=1; i<=20; i++){
                s.insert(i);
            }
        } else if (cmd == "empty"){
            s.clear();
        }
    }
    return 0;
}