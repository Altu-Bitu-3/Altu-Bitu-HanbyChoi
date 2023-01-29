# 정수론: 16563 어려운 소인수분해
import sys, math
MAX = 5000000
def findPrime(n, prime):
    prime[0] = prime[1] = -1
    for i in range(2, int(math.sqrt(n))+1):
        if (prime[i] == 0): # i가 소수면
            for j in range(i*i, n+1, i):
                if (prime[j] == 0):
                    prime[j] = i # i의 배수를 제거
input = sys.stdin.readline
N = int(input())
num = list(map(int, input().split()))
prime = [0 for i in range(MAX+1)]
findPrime(MAX, prime)
for i in num:
    while (prime[i] != 0):
        print(prime[i], end = ' ')
        i = int(i/prime[i])
    print(i, end = ' ')
    print()