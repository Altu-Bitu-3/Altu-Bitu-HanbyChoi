# 브루트포스: 2858 기숙사 바닥
import sys
input = sys.stdin.readline
R, B = map(int, input().split())
for l in range(1, 2502):
    for w in range(l, 2502):
        if (2*l+2*w-4) == R and (l*w-R) == B:
            print(w, l)
            break 