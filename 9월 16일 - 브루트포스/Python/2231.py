# 브루트포스: 2231 분해합
import sys
input = sys.stdin.readline
def getNum(n):
    num = str(n)
    ans = n
    ans += sum(map(lambda x: int(x), num))
    return ans
N = int(input())
find = False
for i in range(N):
    if getNum(i) == N:
        find = True
        print(i)
        break
if not find:
    print(0)