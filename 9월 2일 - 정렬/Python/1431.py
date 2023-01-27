# 정렬: 1431 시리얼 번호
import sys
def getSum(input):
	result = 0
	for i in range(len(input)):
		if input[i].isdigit():
			result += int(input[i])
	return result
input = sys.stdin.readline
N = int(input().strip())
serial = []
for i in range(N):
	serial.append(input().strip())
serial.sort(key = lambda x: (len(x), getSum(x), x))
for i in serial:
	print(i)