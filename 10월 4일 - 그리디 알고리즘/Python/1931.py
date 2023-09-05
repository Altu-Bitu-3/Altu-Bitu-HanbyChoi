# 그리디: 1931 회의실 배정
import sys
input = sys.stdin.readline
n = int(input())
arr = [tuple(map(int, input().split())) for _ in range(n)]
def solution(n, arr):
    arr.sort(key = lambda x: (x[1], x[0]))
    ans = 1
    end = arr[0][1]
    for i in range(1, n):
        if end <= arr[i][0]:
            ans += 1
            end = arr[i][1]
    return ans
print(solution(n, arr))