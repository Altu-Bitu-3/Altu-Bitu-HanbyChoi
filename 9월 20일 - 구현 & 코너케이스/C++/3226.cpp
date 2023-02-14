// 구현 & 코너케이스: 3226 전화 요금
#include <iostream>
#include <string>
using namespace std;
void calcCost(int hour, int minute, int time, int& cost){
    if ((hour >= 7 && hour <= 17) || (hour == 18 && (minute + time) <= 60)){ // 분당 10원인 경우
        cost += time * 10;
    } else if (hour <= 5 || hour >= 19 || (hour == 6 && (minute + time) <= 60)){ // 분당 5원인 경우
        cost += time *5;
    } else { // 5원과 10원이 혼합된 경우
        int diff = 60 - minute;
        if (hour == 6){
            cost += diff * 5 + (time - diff) * 10;
        } else if (hour == 18){
            cost += diff * 10 + (time - diff) * 5;
        }
    }
    return;
}

int main(){
    int n, hour, minute, time, cost = 0;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s >> time;
        hour = stoi(s.substr(0, 2));
        minute = stoi(s.substr(3, 2));
        calcCost(hour, minute, time, cost);
    }
    cout << cost;
    return 0;
}