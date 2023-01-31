# 정수론: 1213 팰린드롬 만들기
import sys
from collections import Counter, deque
def palindrome(name):
    cnt = Counter(name)
    sorted_cnt = sorted(cnt.items(), reverse=True)
    center = ''
    odd = 0
    result = deque()
    for i in sorted_cnt:
        if i[1] % 2 == 1:
            center = i[0]
            odd += 1
            if odd > 1:
                return "I'm Sorry Hansoo"
    if odd == 1: # odd == 0이면 이 과정 스킵
        result.append(center)
    for i in sorted_cnt: 
        add = i[0] * int(i[1]/2)
        result.appendleft(add)
        result.append(add)
    return result

input = sys.stdin.readline
name = input().rstrip()
ans = palindrome(name)
for i in ans:
    print(i, end='')