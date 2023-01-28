# 스택, 큐, 덱: 1918 후위 표기식
import sys

def priority(n):
    if (n == '(' or n == ')'):
        return 0
    elif (n == '+' or n == '-'):
        return 1
    elif (n == '*' or n == '/'):
        return 2

input = sys.stdin.readline
s = input().rstrip()
stack = []

for i in s:
    if (i == '+' or i == '-' or i == '*' or i == '/'):
        while(stack and priority(i) <= priority(stack[-1])): # 스택 탑에 있는 연산자가 나보다 우선순위가 높거나 같은 연산자라면
            print(stack.pop(), end = '') # 그 연산자들 출력
        stack.append(i) # 스택에 나를 넣기
    elif i == '(':
        stack.append(i)
    elif i == ')':
        t = stack.pop()
        while(t != '('): # (가 나올 때까지 pop
            print(t, end = '')
            t = stack.pop()
    else:
        print(i, end = '')
while(stack):
    print(stack.pop(), end = '')