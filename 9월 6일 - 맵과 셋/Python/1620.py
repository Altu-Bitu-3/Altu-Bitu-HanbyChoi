import sys
input = sys.stdin.readline
N, M = map(int, input().split())
d = {}
for i in range(1, N+1):
	a = input().rstrip()
	d[i] = a
	d[a] = i
for i in range(M):
	question = input().strip()
	if(question.isdigit()):
		print(d[int(question)])
	else:
		print(d[question])