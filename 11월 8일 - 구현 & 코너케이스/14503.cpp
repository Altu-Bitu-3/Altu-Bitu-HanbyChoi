// 구현 & 코너케이스 14503 로봇 청소기
#include <iostream> // 표준 입출력 헤더
#include <vector> // 벡터 헤더
#include <stack> // 스택 헤더

using namespace std; // 표준 네임스페이스 선언

int simulate(int n,int m,vector<vector<int>> & board, int r,int c,int d) { // 로봇 청소기가 청소하는 영역의 개수 계산할 함수

	// 북 동 남 서 방향 저장
	int dr[4] = { -1,0,1,0, }; // 세로 좌표
	int dc[4] = { 0,1 ,0, -1,}; // 가로 좌표

	int ans = 0; // 청소하는 칸의 개수 저장할 변수 선언

	while (true) { // 무한 루프
		if (board[r][c] == 0) { // 현재 있는 공간이 빈 칸이고 아직 청소하지 않았다면
			board[r][c] = 2; //현재 위치 청소
			ans++; // 청소한 칸의 개수 하나 증가
		}

		int step; // 현재 방향 기준으로 왼쪽 방향부터 청소할 공간 탐색 - 탐색 상태 저장할 변수 선언
		// 왼쪽 방향에 아직 청소하지 않은 공간이 남아있는지
		for (step = 0; step < 4; step++) { // 네 방향에 대해 검사
			d = (d + 3) % 4; // 현재 방향의 왼쪽 좌표
			int nr = r + dr[d]; // 현재 좌표에서 왼쪽 방향으로 회전 (세로)
			int nc = c + dc[d]; // 현재 좌표에서 왼쪽 방향으로 회전 (가로)

			if (!board[nr][nc]) { // 청소되지 않은 곳이라면
				// 그 방향으로 회전하고 한칸을 전진
				r = nr; // 회전 후 전진
				c = nc; // 회전 후 전진
				break; // 탐색 종료 후 다시 1번부터 시작
			}
		}

		if (step == 4) { //네 방향 모두 벽이거나 청소가 되어있는 경우
			//바라 보는 방향을 유지한채로 한 칸 후진
			r = r - dr[d]; // 방향 유지한채로 후진
			c = c - dc[d]; // 방향 유지한채로 후진

			if (board[r][c] == 1) { //뒤쪽 방향이 벽인 경우 작동 멈춤 
				break; // 작동 멈춤
			}
		}
	}
	return ans; // 청소하는 영역의 개수 반환
}

int main() { // 연산을 실행할 메인 함수

	int n, m, r, c, d; // 입력 값을 저장할 변수 선언

	cin >> n >> m >> r >> c >> d; // 정보 입력 받기

	vector<vector<int>> board(n, vector<int>(m, 0)); // 장소의 상태 (빈 칸, 벽) 입력 받을 이차원 벡터 선언 및 초기화

	//입력
	for (int i = 0; i < n; i++) { // 세로 크기 n
		for (int j = 0; j < m; j++) { // 가로 크기 m인 공간에 대해
			cin >> board[i][j]; // 장소의 상태 입력
		}
	}

	cout << simulate(n,m,board,r,c,d); // 로봇 청소기가 청소하는 칸의 개수 계산 후 출력
    return 0; // 함수 종료
}