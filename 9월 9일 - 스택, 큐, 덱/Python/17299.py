# 스택, 큐, 덱: 17299 오등큰수
import sys
from collections import Counter
input = sys.stdin.readline
N = int(input())
A = list(map(int, input().split()))
cnt = Counter(A)
stack = [0]
result = [-1] * N
for i in range(N):
    while stack and cnt[A[stack[-1]]] < cnt[A[i]]: # 
        result[stack.pop()] = A[i]
    stack.append(i)
for r in result:
    print(r, end = ' ')