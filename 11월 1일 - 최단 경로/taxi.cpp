// 최단 경로: 합승택시요금
#include <iostream> // 입출력 헤더
#include <vector> // 벡터 헤더

using namespace std; // 표준 네임스페이스 선언
const int INF = 1e7 * 2; // 최대 n-1개의 간선을 지나게 됨 - INF 값 상수화

//간선을 인접 행렬 그래프에 삽입
vector<vector<int>> fillGraph(int n, vector<vector<int>>& fares) { // 지점 수와 요금 정보 그래프를 인수로 하는 함수
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); // 인접 행렬 그래프 선언
    for (int i = 1; i <= n; i++) { // 1부터 n까지 (i, i) 요금을
        graph[i][i] = 0; // 0으로 초기화 (이동이 없으므로)
    }

    for (int i = 0; i < fares.size(); i++) { // 양방향 그래프 간선 삽입
        graph[fares[i][0]][fares[i][1]] = fares[i][2]; // 간선의 정보 인접 행렬 그래프에 삽입
        graph[fares[i][1]][fares[i][0]] = fares[i][2]; // 양방향 그래프이므로 반대 방향으로도 삽입
    }
    return graph; // 삽입을 끝낸 인접 행렬 그래프 반환
}

void floydWarshall(vector<vector<int>>& graph, int n) { // 플로이드 워셜 알고리즘 수행할 함수 선언
    for (int k = 1; k <= n; k++) { // 중간 정점
        for (int i = 1; i <= n; i++) { // 출발 정점
            for (int j = 1; j <= n; j++) { // 도착 정점
                int dist = graph[i][k] + graph[k][j]; // k를 중간에 거쳐서 i에서 j로 갈 때 비용
                graph[i][j] = min(graph[i][j], dist); // 기존 값과 k를 중간에 거쳐가는 경로 중 비용이 더 저렴한 경로 선택
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) { // 합승 택시 요금을 계산할 함수 선언
    int answer = INF; // 정답을 저장할 변수를 INF로 초기화
    vector<vector<int>> graph = fillGraph(n, fares); // 인접 행렬에 간선 삽입
    floydWarshall(graph, n); // 플로이드 워셜 수행하여 모든 정점에 대해 최소 비용 계산

    for (int i = 1; i <= n; i++) { // i번째 지점까지 합승
        //지금까지의 최단거리와 합승한 최단거리 비교
        //이동 불가능한 경우(INF)은 min 조건에 의해 자동으로 고려되지 않음
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]); // 지금까지의 최소 비용과 합승했을 경우의 최소 비용 비교 후 더 작은 값 저장
    }
    return answer; // 구한 정답 반환
}

/**
 * [합승 택시 요금]
 *
 * 합승할 수 있는 지점의 개수는 n개
 * 1. s인 경우는 합승을 하지 않을 때
 * 2. a인 경우는 A의 집까지 합승한 뒤, B 혼자 이동
 * 3. b인 경우는 B의 집까지 합승한 뒤, A 혼자 이동
 * 4. 나머지 경우는 특정 지점까지 합승한 뒤, 각자의 집으로 가는 것
 * -> 다익스트라를 사용하면 시간초과이므로 플로이드-워셜 알고리즘 사용
 *
 * 1. 플로이드-워셜 알고리즘으로 모든 지점들 사이의 최단 거리 계산
 * 2. n개의 지점에 대해 n번 지점까지 합승을 하고 각자의 집으로 가는 최단거리 계산
 */

 //프로그래머스 예제 테스트할 수 있는 메인함수
int main() {
    vector<vector<int>> fares = { {4, 1, 10}, // 요금 정보 삽입
                                 {3, 5, 24},
                                 {5, 6, 2},
                                 {3, 1, 41},
                                 {5, 1, 24},
                                 {4, 6, 50},
                                 {2, 4, 66},
                                 {2, 3, 22},
                                 {1, 6, 25} };
    int ans = solution(6, 4, 6, 2, fares); // 주어진 정보에 대해 최소 요금 계산
    cout << ans; // 결과 출력
}