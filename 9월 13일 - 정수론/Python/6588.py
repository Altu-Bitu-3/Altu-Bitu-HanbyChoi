# 정수론: 6588 골드바흐의 추측
import sys, math
def isPrime(n):
    is_prime = [True for i in range(n+1)]
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(math.sqrt(n))+1):
        if (is_prime[i]):
            for j in range(i*i, n+1, i):
                is_prime[j] = False
    return is_prime
input = sys.stdin.readline
prime = isPrime(1000000)
while(True):
    num = int(input())
    if num == 0:
        break
    for i in range(3, len(prime)):
        if prime[i] and prime[num-i]: # 둘 다 소수면
            print(num, '=', i, '+', num-i)
            break