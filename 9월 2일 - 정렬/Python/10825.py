# 정렬: 10825 국영수
import sys 
input = sys.stdin.readline
N = int(input())
table = [list(input().split()) for _ in range(N)]
table.sort(key = lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))
for student in table:
	sys.stdout.write(str(student[0]) + "\n")