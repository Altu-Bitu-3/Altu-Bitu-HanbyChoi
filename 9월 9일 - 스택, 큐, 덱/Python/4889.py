# 스택, 큐, 덱: 4889 안정적인 문자열
import sys
input = sys.stdin.readline
answer = []
while True:
    stack = []
    cnt = 0
    s = input().rstrip()
    if (s[0] == '-'):
        break
    s = s.replace('{}', '')
    for i in s:
        if i == '{':
            stack.append(i)
        elif i == '}':
            if stack: # not empty
                stack.pop()
            else: # empty
                cnt += 1
                stack.append(i)
    cnt += int(len(stack)/2)
    answer.append(cnt)
for i in range(len(answer)):
    print(str(i+1) + '.', answer[i])