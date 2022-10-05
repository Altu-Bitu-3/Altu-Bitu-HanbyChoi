// 동적 계획법: 20923 숫자 할리갈리 게임
#include <iostream> // 표준 입출력 헤더
#include <deque> // 덱 사용을 위한 헤더

using namespace std; // 표준 네임스페이스 선언
// src의 합치는 카드 더미를 des의 카드 더미로 합치는 함수
void mergeCards(deque<int>& src, deque<int>& des) // 카드 더미를 합치는 함수
{
    while (!src.empty()) // src 카드 더미가 빌 때까지
    {
        des.push_back(src.back()); // 상대방 덱을 뒤집어서(맨 뒤부터) 아래로 합치기
        src.pop_back(); // 합친 카드는 덱에서 삭제
     }
}
string playGame(int m, deque<int>& dodo, deque<int>& su) // 게임을 진행하는 함수
{
    deque<int> do_gr; // 그라운드에 있는 도도의 카드 더미
    deque<int> su_gr; // 그라운드에 있는 수연의 카드 더미
    bool flag = true; // true일 때는 도도의 차례, false 일 때는  수연의 차례
    while (m--) // m번 게임 진행
    {
        if (flag) // 도도의 차례인 경우
        {
            do_gr.push_front(dodo.front()); // 도도의 덱에 있는 맨 위의 카드를 그라운드에 놓는다
            dodo.pop_front(); // 그라운드에 놓은 카드를 덱에서 제거
            if (dodo.empty()) { // 도도의 덱이 비게 된다면 (카드 수 0)
                return "su"; // 덱에 있는 카드의 수가 0이 되면 상대방이 즉시 승리 - 수연이의 승리
            }
        }
        else // 수연이의 차례인 경우
        {
            su_gr.push_front(su.front()); /// 수연이의 덱에 있는 맨 위의 카드를 그라운드에 놓는다
            su.pop_front(); // 그라운드에 놓은 카드를 덱에서 제거
            if (su.empty()) { // 수연이의 덱이 비게 된다면 (카드 수 0)
                return "do"; // 덱에 있는 카드의 수가 0이 되면 상대방이 즉시 승리 - 도도의 승리
            }
        }
        flag = !flag; // 둘의 순서 바꾸기
        // 도도와 수연이가 종을 칠 수 있는지 검사
        // 도도가 종을 쳤을 때 
        if (!do_gr.empty() && do_gr.front() == 5 || !su_gr.empty() && su_gr.front() == 5) { // 도도의 그라운드에 카드가 놓여있고 맨 위에 놓인 카드에 적힌 수가 5거나 수연이의 그라운드에 카드가 놓여있고 맨 위에 놓인 카드에 적힌 수가 5라면
            mergeCards(su_gr, dodo); // 수연이의 그라운드에 놓인 카드를 도도의 덱에 합침
            mergeCards(do_gr, dodo); // 도도의 그라운드에 놓인 카드를 도도의 덱에 합침
        }
        // 수연이가 종을 쳤을 때
        if (!do_gr.empty() && !su_gr.empty() && do_gr.front() + su_gr.front() == 5) { // 도도와 수연이의 그라운드 모두에 카드가 놓여있고 두 그라운드의 맨 위에 놓인 카드에 적힌 수의 합이 5인 경우
            mergeCards(do_gr, su); // 도도의 그라운드에 놓인 카드를 수연이의 덱에 합침
            mergeCards(su_gr, su); // 수연이의 그라운드에 놓인 카드를 수연이의 덱에 합침
        }
    }

    // m번의 게임이 끝났을 때
    if (dodo.size() > su.size()) { // 도도의 덱에 있는 카드가 수연이의 덱에 있는 카드보다 많으면
        return "do"; // 도도의 승리
    }
    else if (dodo.size() < su.size()) { // 도도의 덱에 있는 카드보다 수연이의 덱에 있는 카드가 더 많으면
        return "su"; // 수연이의 승리
    }
    return "dosu"; // 둘 다 아니라면 무승부
}
/*
 *[숫자 할리갈리 게임] : 구현, 시뮬레이션
 * 도도,수연이의 덱과 그라운드에 있는 도도,수연의 덱 총 4개의 덱을 관리해주면 됩니다
 * deque 라이브러리를 사용하면 카드 덱에서 일어나는 일들을 쉽게 구현할 수 있습니다
 * 문제에서 주어진 게임 진행 순서대로 구현하면 됩니다
 * 게임 순서와 종료 조건을 주의하셔야 합니다
 */
int main() // 입출력 및 연산을 진행할 메인 함수
{
    int n, m; // 카드의 개수 n, 게임 진행 횟수 m
    cin >> n >> m; // n, m 입력 받기
    deque<int> dodo; // 도도의 카드 더미를 저장할 덱
    deque<int> su; // 수연이의 카드 더미를 저장할 덱
    for (int i = 0; i < n; i++) // 도도와 수연이의 카드 덱에 포함될 카드에 적힌 수 입력 받기
    {
        int a, b; // 카드에 적힌 수 저장할 변수
        cin >> a >> b; // 도도와 수연이 카드 덱에 들어갈 정보 입력 받기
        dodo.push_front(a); // 도도의 덱에 카드 추가
        su.push_front(b); // 수연이의 덱에 카드 추가
    }
    cout << playGame(m, dodo, su); // 할리갈리 게임의 결과 출력
    return 0; // 메인 함수 종료
}