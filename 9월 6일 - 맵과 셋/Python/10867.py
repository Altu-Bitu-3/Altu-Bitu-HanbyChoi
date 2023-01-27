import sys
input = sys.stdin.readline
N = int(input())
arr = list(set(map(int, input().split())))
arr.sort()
for i in arr:
	print(i, end = ' ')