# 브루트포스: 14888 연산자 끼워넣기
import sys
from itertools import permutations
input = sys.stdin.readline
N = int(input())
num = list(map(int, input().split()))
oper_num = list(map(int, input().split()))
oper = []
oper += ['+' for i in range(oper_num[0])]
oper += ['-' for i in range(oper_num[1])]
oper += ['*' for i in range(oper_num[2])]
oper += ['/' for i in range(oper_num[3])]
"""
op_list = ['+', '-', '*', '/']
op = []

for k in range(len(op_num)):
    for i in range(op_num[k]):
        op.append(op_list[k])
"""
comb = list(set(permutations(oper, N-1)))
min_res = 1e9 + 1; max_res = -1e9 - 1
for com in comb:
    form = ''
    res = num[0]
    index = 0
    for op in com:
        index += 1
        if op == '+':
            res += num[index]
        elif op == '-':
            res -= num[index]
        if op == '*':
            res *= num[index]
        if op == '/':
            if res < 0 and num[index] > 0:
                res = int(res*(-1)/num[index]) * (-1)
            else:
                res = int(res/num[index])
    min_res = min(min_res, res)
    max_res = max(max_res, res)
print(max_res); print(min_res)