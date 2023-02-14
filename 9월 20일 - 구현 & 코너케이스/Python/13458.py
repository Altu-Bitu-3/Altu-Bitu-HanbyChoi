# 구현 & 코너케이스: 13458 시험 감독
import sys, math
input = sys.stdin.readline
N = int(input())
num = list(map(int, input().split()))
B, C = map(int, input().split())
min_num = 0
for i in num:
    if i <= B:
        min_num += 1
    else:
        min_num += math.ceil((i-B)/C) + 1
print(min_num)