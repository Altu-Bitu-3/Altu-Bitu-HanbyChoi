# 정렬: 11651 좌표 정렬하기 2
import sys 
input = sys.stdin.readline
N = int(input())
arr = []
for i in range(N):
    arr.append(list(map(int, input().split())))
arr.sort(key = lambda x : (x[1], x[0]))
for i in arr:
	print(i[0], i[1])