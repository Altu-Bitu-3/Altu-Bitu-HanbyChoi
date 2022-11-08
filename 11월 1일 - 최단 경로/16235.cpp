// 최단 경로: 16235 나무 재테크
#include <iostream> // 표준 입출력 헤더
#include <deque> // 덱 헤더
#include <vector> // 벡터 헤더

using namespace std; // 표준 입출력 네임스페이스 선언
typedef vector<vector<int>> matrix; // 행렬 사용을 위한 자료형 선언

int countTrees(int n, vector<deque<int>>& trees) { // 살아있는 나무의 개수를 세는 함수
	int answer = 0; // 개수 저장할 변수 선언 및 초기화
	for (int i = 0; i < n; i++) // i행
	{
		for (int j = 0; j < n; j++) // j열
		{
			answer += trees[i * 10 + j].size(); // i행 j열에 있는 나무의 개수만큼 더해주기
		}
	}
	return answer; // 총 살아남은 나무 개수 반환
}

void reproduceTree(int n, int x, int y, vector<deque<int>>& trees) // 번식할 나무 정보 추가하는 함수
{
	for (int i = x - 1; i <= x + 1; i++) // 인접한 8개의 칸
	{
		for (int j = y - 1; j <= y + 1; j++) // 인접한 8개의 칸
		{
			if ((i == x) && (j == y)) { // 가운데 칸은
				continue; // 연산 스킵
			}
			if (i >= 0 && j >= 0 && i < n && j < n) // 인접한 8개의 칸 중 범위 안의 칸에 대해
			{
				trees[i * 10 + j].push_front(1); // 나이가 1인 나무 정보 추가
			}
		}
	}
}

void solution(int n, vector<deque<int>>& trees, matrix& food, matrix& a, vector<pair<int, int>>& breeding_tree) // 계절의 흐름에 따른 나무 정보 변화 계산할 함수
{
	for (int i = 0; i < n; i++){ // 0 ~ n-1 행
		for (int j = 0; j < n; j++){ // 0 ~ n-1 열
			int leftover = 0; // 남은 양분 계산할 변수 선언 및 초기화
			deque<int> dq; // 정보 갱신에 쓰일 덱 선언
			for (auto age : trees[i * 10 + j]) // 각 트리에 대해 연산 수행
			{
				if (food[i][j] < age) { // 양분을 먹을 수 없다면
					leftover += age / 2; // 나무는 죽고 양분으로 변함
					continue;
				}
				food[i][j] -= age; // 양분을 나이만큼 먹음
				dq.push_back(age + 1); // 나이를 1 증가시킴
				if ((age + 1) % 5 == 0) // 나이가 5의 배수라 번식 가능하다면
				{
					breeding_tree.push_back({ i, j }); // 그 자리에 나무 번식
				}
			}
			trees[i * 10 + j] = dq; // 나무 정보 갱신
			food[i][j] += (a[i][j] + leftover); // 로봇이 주는 양분 양 + 죽은 나무가 남긴 양분 양을 food에 더해줌
		}
	}
}
/**16235 나무 재테크
 * [문제 설명] - 단순 구현 문제
 * 봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
 *    각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
 * 여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
 * 가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김
 * 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가
 *
 * K년이 지난 후 상도의 땅에 살아있는 나무의 개수
 *
 * [문제 풀이]
 * A : 로봇(S2D2)가 겨울에 주는 양분의 양
 * food : 땅의 양분
 * breeding_tree: 나이가 5의 배수인 트리 (번식할 트리)
 * tree: 땅에 심은 나무 나이, 행, 열 정보
 * -> deque 컨테이너를 활용해 번식한 나무를 앞에 넣어주면 입력 후에만 정렬해서 사용 가능
 *
 * 문제의 설명대로 계절별 연산을 진행
 */
int main() // 연산 수행할 메인 함수
{
	int n, m, k; // 값을 입력 받을 변수 선언
	//입력
	cin >> n >> m >> k; // n, m, k값 입력 받기
	matrix a(n, vector<int>(n, 0)); // 로봇이 겨울에 주는 양분의 양 저장할 행렬 선언 및 초기화
	matrix food(n, vector<int>(n, 5)); // 땅의 양분 저장할 행렬 선언 및 초기화
	vector<deque<int>> trees(n * 10 + n); // 땅에 심은 나무의 나이, 행, 열 정보 저장할 덱 벡터 선언 및 초기화

	for (int i = 0; i < n; i++) // i번째 줄
	{
		for (int j = 0; j < n; j++) // j번째 값
		{
			cin >> a[i][j]; // a 배열의 값 입력 받기
		}
	}
	for (int i = 0, x, y, z; i < m; i++) // m개의 줄에 심은 나무의 정보 주어짐
	{
		cin >> x >> y >> z; // 심은 나무의 정보 입력
		x--; y--; // 행렬 삽입을 위해 1씩 빼기 (0부터 시작)
		trees[x * 10 + y].push_front(z); // x행 y열에 위치한 나무 나이 z 삽입
	}
	while (k--) { // k년만큼 계산
		vector<pair<int, int>> breeding_tree; // 번식할 나무 정보 저장할 벡터
		solution(n, trees, food, a, breeding_tree); // 계절의 흐름에 따른 나무 변화 계산
		for (auto [i, j] : breeding_tree) // 번식할 나무에 대해
		{
			reproduceTree(n, i, j, trees); // 함수 호출로 나무의 번식 계산
		}
	}
	cout << countTrees(n, trees); // 살아있는 나무 개수 세어 반환
	return 0; // 메인 함수 종료
}