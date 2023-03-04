# 구현 & 코너케이스: 2840 행운의 바퀴
import sys
from collections import deque, Counter
input = sys.stdin.readline
N, K = map(int, input().split())
arr = deque(['' for i in range(N)])
index = 0; find = True
while K:
    S, alpha = input().rstrip().split()
    index = (index + int(S)) % N
    if arr[index] == '' or arr[index] == alpha:
        arr[index] = alpha
    else:
        find = False
        break
    K -= 1

alphabet_count = Counter(arr)
for key, value in alphabet_count.items():
    if key != '' and value > 1:
        find = False
        break

if find:
    arr.rotate(N-1-index)
    arr.reverse()
    for i in arr:
        if i == '':
            print('?', end='')
        else:
            print(i, end='')
else:
    print('!')