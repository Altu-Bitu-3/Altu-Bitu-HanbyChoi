# 맵과 셋 : 9375 패션왕 신해빈
import sys
input = sys.stdin.readline
t = int(input().strip())
for i in range(t):
	dict = {}
	n = int(input().strip())
	for j in range(n):
		name, type = input().split()
		if type in dict:
			dict[type] += 1
		else:
			dict[type] = 1
	result = 1
	for value in dict.values():
		result *= (value+1)
	print(result-1)