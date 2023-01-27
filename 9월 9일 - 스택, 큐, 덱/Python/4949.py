# 스택, 큐, 덱: 4949 균형잡힌 세상
import sys

def isBalanced(s):
    stack = []
    dict = {}
    dict[']'] = '['; dict[')'] = '('
    for i in s:
        if i == '(' or i == '[':
            stack.append(i)
        elif i == ')' or i == ']':
            if not stack or (stack[-1] != dict[i]):
                return False
            else:
                stack.pop()
    return not stack
            
input = sys.stdin.readline
while True:
    s = ""
    while True:
        s += input().rstrip()
        if s[-1] == '.':
            break
    if len(s) == 1:
        break
    
    if (isBalanced(s)):
        print("yes")
    else:
        print("no")