# 정수론: 14490 백대열
import sys
def getGcd(n, m):
    if n < m:
        n, m = m, n
    while(m):
        n %= m
        n, m = m, n
    return n
input = sys.stdin.readline
n, m = map(int, input().split(':'))
gcd = getGcd(n, m)
print(int(n/gcd), int(m/gcd), sep = ':')