# 정렬: 1946 신입 사원
import sys
input = sys.stdin.readline
T = int(input())
while (T>0):
	N = int(input())
	arr = []
	for i in range(N):
		arr.append(list(map(int, input().split())))
	arr.sort(key = lambda x: x[0]) # 서류 순위에 대해 오름차순 정렬
	cnt = 1
	interview = arr[0][1]
	for i in range(1, N):
			if (arr[i][1] < interview):
				cnt += 1
				interview = arr[i][1]
	print(cnt)
	T -= 1