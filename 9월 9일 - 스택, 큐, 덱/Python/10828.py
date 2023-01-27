# 스택, 큐, 덱: 10828 스택
import sys
input = sys.stdin.readline
N = int(input())
stack = []
for _ in range(N):
    cmd = input().split()
    if (len(cmd) == 2):
        stack.append(int(cmd[1]))
    else:
        if cmd[0] == 'pop':
            if stack:
                print(stack.pop())
            else:
                print(-1)
        elif cmd[0] == 'size':
            print(len(stack))
        elif cmd[0] == 'empty':
            if not stack: # empty list
                print(1)
            else:
                print(0)
        elif cmd[0] == 'top':
            if stack: # not empty list
                print(stack[-1])
            else:
                print(-1)