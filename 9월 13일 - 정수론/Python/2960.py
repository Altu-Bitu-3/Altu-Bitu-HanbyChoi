# 정수론: 2960 에라토스테네스의 체
import sys
def isPrime(n, k, is_prime):
    is_prime[0] = is_prime[1] = False
    index = 0
    for i in range(2, n+1):
        if (is_prime[i]):
            index += 1
            if (index == k):
                return i
            for j in range(i*i, n+1, i):
                if (is_prime[j]):
                    is_prime[j] = False
                    index += 1
                    if (index == k):
                        return j
input = sys.stdin.readline
N, K = map(int, input().split())
is_prime = [True for i in range(N+1)]
print(isPrime(N, K, is_prime))