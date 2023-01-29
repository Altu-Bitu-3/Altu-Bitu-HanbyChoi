# 정수론: 9613 GCD 합
import sys
from itertools import combinations
def gcdIter(a, b):
    while(b):
        a %= b
        a, b = b, a
    return a
input = sys.stdin.readline
t = int(input().rstrip())
while (t):
    case = list(map(int, input().split()))
    n = case.pop(0)
    case.sort(reverse=True)
    combi = list(combinations(case, 2))
    gcdSum = 0
    for i in range(len(combi)):
        gcd = gcdIter(combi[i][0], combi[i][1])
        gcdSum += gcd
    print(gcdSum)
    t -= 1