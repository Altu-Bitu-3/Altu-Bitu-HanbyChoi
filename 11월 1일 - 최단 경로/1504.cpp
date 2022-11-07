// 최단 경로: 1504 특정한 최단 경로
#include<iostream> // 입출력 헤더
#include<queue> // 큐 헤더
#include<vector> // 벡터 헤더

using namespace std; // 표준 입출력 네임스페이스

typedef pair<int, int> pii; // 편의를 위해 int, int형 pair 자료형 선언
const int INF = 1e5 * 8 * 3; // 이 문제에서 나올 수 있는 최댓값을 infinite 초기화 값으로 지정


vector<int> dijkstra(int start,int n, vector<vector<pii>>&graph) { // 다익스트라 알고리즘을 수행할 함수 선언
	vector<int> dist(n+ 1, INF); // 각 정점까지의 최단 경로 저장
	dist[start] = 0; // 시작 정점 초기화
	//pq 선언
	priority_queue < pii, vector<pii>, greater<pii>> pq; // 알고리즘 수행할 우선순위 큐 선언
	pq.push(pii(0, start)); // 탐색을 시작할 정점을 우선순위 큐에 삽입

	//dijstra
	while (!pq.empty()) { // 큐가 빌 때까지 반복
		int d = pq.top().first; // 현재 정점까지의 경로 값
		int v = pq.top().second; // 현재 탐색할 정점
		pq.pop(); // 탐색한 정점 큐에서 제거

		if (d > dist[v]) { // 이미 더 작은 값으로 기록된 정점이라면
			continue; // 연산 스킵
		}

		// 탐색 & 거리 값 갱신
		for (int i = 0; i < graph[v].size(); i++) { // 해당 정점에 연결된 정점에 대해 연산 수행
			int nxt_v = graph[v][i].first; // 다음에 탐색할 정점
			int cost = graph[v][i].second; // 다음에 탐색할 정점의 경로 cost
			// 거리가 작으면 갱신 후 pq에 삽입
			if (dist[nxt_v] > dist[v] + cost) { // 현재 정점에서 다음 정점을 방문한 값이 기존 값보다 작으면
				dist[nxt_v] = dist[v] + cost; // 최단 경로 값 갱신
				pq.push(pii(dist[nxt_v], nxt_v)); // 다음에 탐색할 정점을 큐에 삽입
			}
		}
	}
	return dist; // 구한 최단 경로 값 벡터 반환
}

/*
필수적으로 지나야 하는 v1,v2 노드를 지나가는 방법
1) 1->v1->v2->n
2) 1->v2->v1->n
무방향 그래프이므로 1,v1,v2에 대해 다익스트라를 진행한 뒤 결과를 더해 그 중 min 값 선택
*/
int solve(int v1, int v2,int n, vector<vector<pii>> &graph) { // 문제 조건을 수행할 함수 선언
	vector<int> start = { 1,v1,v2 }; // 1, v1, v2에 대해 다익스트라를 진행하기 위해 start를 벡터로 선언
	vector<vector<int>> dist(3, vector<int>(n + 1, 0)); // 1, v1, v2에 대해 다익스트라를 진행한 경로값을 저장할 벡터

	//1,v1,v2에 대해 다익스트라 진행
	for (int i = 0; i < 3; i++) { // start에 저장한 세 정점 1, v1, v2에 대해
		dist[i] = dijkstra(start[i], n, graph); // 다익스트라 진행 후 dist 벡터에 결과 저장
	}

	int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]); // 필수 정점을 지나는 두 경로 중 더 작은 값을 결과로 저장
	
	if (ans >= INF) { // 만약 구한 결과값이 INF과 같거나 크다면
		return -1; // 답이 없는 경우이므로 -1 반환
	}
	return ans; // 구한 결과값 반환
}

int main() { // 연산을 수행할 메인 함수
	int e, v1, v2, n; // 값을 입력 받을 변수 선언
	cin >> n >> e; // 정점의 개수와 간선의 개수 입력
	vector<vector<pii>> graph(n+1, vector<pii>(0)); // 인접 리스트로 그래프 구현
	while(e--){ // 간선의 개수만큼 정보 입력 받기
		int a, b, c; // a번 정점부터 b번 정점까지의 거리는 c
		cin >> a >> b >> c; // a, b, c 값 입력 받기
		//입력받은 값 저장. 양방향 그래프이므로 a와 b 모두 저장 해주어야함
		graph[a].push_back(pii(b, c)); // 정점 a에 b, c 정보 저장
		graph[b].push_back(pii(a, c)); // 정점 b에 a, c 정보 저장
	}
	cin >> v1 >> v2; // 반드시 거쳐야 하는 두 정점의 번호 입력 받기
	cout << solve(v1, v2,n,graph); // 문제가 요구하는 최단 경로의 길이 계산해서 출력
}