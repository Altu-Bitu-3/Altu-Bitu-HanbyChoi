# 정렬: 1758 알바생 강호
import sys 
input = sys.stdin.readline
N = int(input().strip())
tip = []
for i in range(N):
	tip.append(int(input().strip()))
tip.sort(reverse = True)
cnt = 0; sum = 0
while ((cnt < len(tip)) and ((tip[cnt] - cnt) >= 0)):
	sum += (tip[cnt] - cnt)
	cnt += 1
print(sum)