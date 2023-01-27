# 맵과 셋: 14911 궁합 쌍 찾기
import sys
from itertools import combinations
input = sys.stdin.readline
num = list(map(int, input().split())).sort()
N = int(input().rstrip())
comb = list(combinations(num, 2))
result = []
for i in range(len(comb)):
	if ((comb[i][0] + comb[i][1]) ==  N):
		 result.append(comb[i])
result = list(set(result)) # 중복 제거
result.sort(key = lambda x : (x[0], x[1])) # 튜플 사전순 정렬
for i in range(len(result)):
	print(result[i][0], result[i][1]) # 순서쌍 출력
print(len(result)) # 순서쌍 개수 출력