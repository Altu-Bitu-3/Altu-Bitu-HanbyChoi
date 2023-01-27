# 맵과 셋: 14425 문자열 집합
import sys
input = sys.stdin.readline
N, M = map(int, input().split())
s = set(); cnt = 0
for i in range(N):
	s.add(input().rstrip())
for i in range(M):
	check = input().rstrip()
	if check in s:
		cnt += 1
print(cnt)