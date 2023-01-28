# 스택, 큐, 덱: 18115 카드 놓기
import sys
from collections import deque
input = sys.stdin.readline
N = int(input())
A = deque(map(int, input().split()))
after = deque([i for i in range(1, N+1)])
before = deque()
for i in range(N):
    cmd = A.pop()
    a = after.popleft()
    if cmd == 1:
        before.appendleft(a)
    elif cmd == 2:
        before.insert(1, (a))
    elif cmd == 3:
        before.append(a)
print(*before)