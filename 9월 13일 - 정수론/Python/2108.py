# 정수론: 2108 통계학
import sys, statistics
from collections import Counter
def getMode(arr):
    cnt = Counter(arr)
    most_cnt = cnt.most_common(2)
    if (len(cnt) > 1):
        if most_cnt[0][1] == most_cnt[1][1]:
            return most_cnt[1][0]
        else:
            return most_cnt[0][0]
    else:
        return most_cnt[0][0]
input = sys.stdin.readline
N = int(input())
arr = []
for i in range(N):
    num = int(input())
    arr.append(num)
arr.sort()
print(round(statistics.mean(arr)))
print(statistics.median(arr))
print(getMode(arr))
print(arr[-1] - arr[0])
"""
def getMode(arr):
    cnt = Counter(arr)
    most_cnt = cnt.most_common()
    most = 0
    most = most_cnt[0][1]
    most_num = []
    for i in most_cnt:
        if i[1] == most:
            most_num.append(i[0])
    if len(most_num) == 1:
        return most_num[0]
    else:
        most_num.sort()
        return most_num[1]
"""