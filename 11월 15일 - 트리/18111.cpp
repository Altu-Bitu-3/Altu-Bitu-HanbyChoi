// 트리: 18111 마인크래프트
#include <iostream> // 표준 입출력 헤더
#include <vector> // 벡터 헤더
using namespace std; // 표준 네임스페이스

/*
    !주의! 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음.
    시간을 최소로 하는 것이 우선되고, 소요 시간이 같을 경우 높이가 높은 것이 정답임
    => 소요 시간을 최소로 해야 하기 때문에, 완성된 땅의 높이는 입력받은 땅의 높이의 최솟값 ~ 최댓값 사이로 결정된다.
*/

const int INF = 1e9; // 무한대 초기화값 상수 선언

int minimumTime(int height, int block, int n, int m, vector<vector<int>> &ground) { // 기준 높이와 블록 수가 주어졌을 때 땅을 고르는 데 걸리는 최소 시간 계산하는 함수
    int time = 0; // 시간 저장할 변수 선언 및 초기화
    for (int i = 0; i < n; i++) { // n개 줄
        for (int j = 0; j < m; j++) { // m개 땅 (n * m)
            if (height < ground[i][j]) { // 기준 높이보다 땅이 높으면 블록 제거
                block += (ground[i][j] - height); // 땅과 기준 높이의 차이만큼 제거한 블록 추가
                time += 2 * (ground[i][j] - height); // 제거한 블록 수만큼 소요시간 추가
            } else if (height > ground[i][j]) { // 기준 높이보다 땅이 낮으면 블록 추가
                block -= (height - ground[i][j]); // 기준 높이와 땅의 차이만큼 사용한 블록 감소
                time += (height - ground[i][j]); // 추가한 블록 수만큼 소요시간 추가
            }
        }
    }

    if (block < 0) { // 다 계산을 했는데 block이 음수이면 불가능한 경우
        return INF; // 불가능하므로 소요시간 대신 무한대 상수 반환
    }
    return time; // 가능한 경우 소요시간 반환
}

pair<int, int> solution(int min_h, int max_h, int b, int n, int m, vector<vector<int>> &ground) { // 땅을 고르는 데 걸리는 최소 시간과 최고 높이를 계산하는 함수
    pair<int, int> result = {INF, 0}; // 최소 시간, 최대 높이 저장할 변수 선언 및 초기화

    for (int height = min_h; height <= max_h; height++) { // 땅의 최소 높이부터 최대 높이까지 모든 height에 대해 계산
        int time = minimumTime(height, b, n, m, ground); // 해당 height를 기준으로 땅을 고를 경우 최소 시간 계산
        if (time <= result.first) { // 방금 계산한 최소 시간이 지금까지 저장된 최소시간보다 짧은 경우 값 갱신 - 최소 시간이 같을 경우, 최대 높이를 출력해야 하기 때문에 등호 필요
            result = {time, height}; // 새로운 최소 시간과 최대 높이 저장
        }
    }

    return result; // 계산 결과 반환
}

int main() { // 연산을 시행할 메인 함수
    int n, m, b; // 땅의 크기와 블록의 수 입력 받을 변수 선언
    cin >> n >> m >> b; // 값 입력 받기
    vector<vector<int>> ground(n, vector<int>(m, 0)); // 땅의 높이 저장할 이차원 벡터 선언 및 초기화

    int max_h = 0, min_h = INF; // 주어진 땅에서 최대 높이와 최소 높이를 저장할 변수 선언 및 초기화
    for (int i = 0; i < n; i++) { // n개의 줄
        for (int j = 0; j < m; j++) { // m개의 땅에 대해
            cin >> ground[i][j]; // 해당 좌표의 땅 입력 받기
            max_h = max(max_h, ground[i][j]); // 입력 값과 지금까지 저장된 최댓값을 비교해 제일 높은 곳의 높이 저장
            min_h = min(min_h, ground[i][j]); // 입력 값과 지금까지 저장된 최솟값을 비교해 제일 낮은 곳의 높이 저장
        }
    }

    pair<int, int> result = solution(min_h, max_h, b, n, m, ground); // 주어진 정보를 바탕으로 최소 시간, 최대 높이 계산해 변수에 저장

    cout << result.first << " " << result.second; // 계산한 최소 시간과 최대 높이 출력
    return 0; // 메인 함수 종료
}