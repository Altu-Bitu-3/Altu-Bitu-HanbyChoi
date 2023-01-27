# 맵과 셋: 7785 회사에 있는 사람
import sys
input = sys.stdin.readline
n = int(input().rstrip())
s = set()
for i in range(n):
	name, state = input().split()
	if name in s:
		s.remove(name)
	else:
		s.add(name)
s = list(s)
s.sort(reverse=True)
for i in s:
	print(i)