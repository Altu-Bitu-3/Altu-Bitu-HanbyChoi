# 정수론: 2609 최대공약수와 최소공배수
import sys
def gcdIter(a, b):
    while(b):
        a %= b
        a, b = b, a
    return a
input = sys.stdin.readline
a, b = map(int, (input().split()))
gcd = gcdIter(a, b)
print(gcd)
print(int(a*b/gcd))