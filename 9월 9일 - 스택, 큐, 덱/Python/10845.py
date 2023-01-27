# 스택, 큐, 덱: 10845 큐
import sys
input = sys.stdin.readline
N = int(input())
queue = []
for _ in range(N):
    cmd = input().split()
    if len(cmd) == 2:
        queue.append(int(cmd[1]))
    else:
        if cmd[0] == 'pop':
            if queue:
                print(queue.pop(0))
            else:
                print(-1)
        elif cmd[0] == 'size':
            print(len(queue))
        elif cmd[0] == 'empty':
            if not queue: # empty list
                print(1)
            else:
                print(0)
        elif cmd[0] == 'front':
            if queue:
                print(queue[0])
            else:
                print(-1)
        elif cmd[0] == 'back':
            if queue:
                print(queue[-1])
            else:
                print(-1)