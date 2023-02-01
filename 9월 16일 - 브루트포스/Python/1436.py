# 브루트포스: 1436 영화감독 숌
import sys
input = sys.stdin.readline
N = int(input())
cnt = 0
for i in range(666, 6669999):
    if '666' in str(i):
        cnt += 1
    if cnt == N:
        print(i)
        break