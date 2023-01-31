# 정수론: 2168 타일 위의 대각선
import sys
def getGCD(x, y):
    if x < y:
        x, y = y, x
    while(y):
        x %= y
        x, y = y, x
    return x
input = sys.stdin.readline
x, y = map(int, input().split())
gcd = getGCD(x, y)
print(gcd * int(x/gcd+y/gcd-1))