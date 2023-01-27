# 스택, 큐, 덱: 2164 카드 2
import sys
from collections import deque
input = sys.stdin.readline
N = int(input())
deq = deque([i for i in range(1, N+1)])
while(len(deq) > 1):
    deq.popleft()
    deq.append(deq.popleft())
print(deq[0])

"""
큐를 이용한 코드 (시간초과)
card = [i for i in range(1, N+1)] # 큐 초기화
while(True):
    if len(card) == 1:
        print(card[0])
        break
    card.pop(0) # 맨 앞의 카드 버림
    card.append(card.pop(0)) # 맨 앞의 카드를 맨 뒤로 옮김
"""