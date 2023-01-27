# 맵과 셋: 2910 빈도 정렬
import sys
input = sys.stdin.readline
N, C = map(int, input().split())
message = list(map(int, input().split()))
num_set = set()
dict = {}
for i in range(N):
	if message[i] in num_set:
		dict[message[i]]['cnt'] += 1
	else:
		dict[message[i]] = {'cnt' : 1, 'order' : i}
		num_set.add(message[i])
result = sorted(dict.items(), key = lambda x : (-x[1]['cnt'], x[1]['order']))
for i in range(len(result)):
	for j in range(result[i][1]['cnt']):
		print(result[i][0], end = ' ')