# 스택, 큐, 덱: 11866 요세푸스 문제
import sys
from collections import deque
input = sys.stdin.readline
N, K = map(int, input().split())
people = deque([i for i in range(1, N+1)])
print('<', end = '')
while(people): # 덱이 비면 false - while문 종료
    for i in range(K - 1):
        people.append(people.popleft()) # k-1번째까지 맨 앞의 요소를 맨 뒤로 이동
    print(people.popleft(), end='') # k번째 요소를 출력 후 삭제
    if people:
        print(', ', end = '') # 덱이 아직 비지 않았다면 ', ' 추가 출력
print('>')