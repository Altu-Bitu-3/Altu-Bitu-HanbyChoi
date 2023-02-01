# 브루트포스: 14889 스타트와 링크
import sys
from itertools import combinations
input = sys.stdin.readline
N = int(input())
arr = []
team = [i for i in range(N)]
for i in range(N):
    arr.append(list(map(int, input().split())))
start = list(combinations(team, int(N/2)))
mindiff = float("inf")
for i in start:
    link = []
    for j in team:
        if j not in i: 
            link.append(j)
    start_sum = 0; link_sum = 0
    srt = list(combinations(i, 2))
    lnk = list(combinations(link, 2))
    for j in srt:
        start_sum += arr[j[0]][j[1]] + arr[j[1]][j[0]]
    for j in lnk:
        link_sum += arr[j[0]][j[1]] + arr[j[1]][j[0]]
    mindiff = min(mindiff, abs(start_sum - link_sum))
print(mindiff)