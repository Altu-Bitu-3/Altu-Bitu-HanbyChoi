# 구현 & 코너케이스: 5397 키로거
import sys
input = sys.stdin.readline
T = int(input())
while T:
    pw = list(input().strip())
    left, right = [], []
    for i in pw:
        if i == '<' and left:
            right.append(left.pop())
        elif i == '>' and right:
            left.append(right.pop())
        elif i == '-' and left:
            left.pop()
        elif i != '<' and i != '>' and i != '-':
            left.append(i)
    left.extend(reversed(right))
    print(''.join(left))
    T -= 1
"""
T = int(input())
while(T):
    pw = list(input().strip())
    ans = []
    index = 0
    for i in pw:
        if i == '<' and index > 0:
                index -= 1
        elif i == '>' and index < len(ans):
                index += 1
        elif i == '-' and index > 0:
            ans.pop(index-1)
            index -= 1
        elif i != '<' and i != '>' and i != '-':
            ans.insert(index, i)
            index += 1
    for i in ans:
        print(i, end='')
    print()
    T -= 1
"""