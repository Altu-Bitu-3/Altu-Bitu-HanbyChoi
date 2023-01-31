# 정수론: 9421 소수상근수
import sys
input = sys.stdin.readline
def Prime(n):
    prime = []
    is_prime = [True for i in range(n+1)]
    for i in range(2, n+1):
        if is_prime[i]:
            prime.append(i)
            for j in range(2*i, n+1, i):
                is_prime[j] = False
    return prime
n = (int(input()))
prime = Prime(n)
ans = []
for i in prime:
    visited = dict()
    temp = str(i)
    while True:
        tempSum = sum(map(lambda x: int(x)**2, temp))
        index = int(temp)
        if (tempSum == 1):
            ans.append(i)
            break
        if (visited.get(index)): # 합이 1이 아니고 전에 방문한 적 있는 값이라면
            break # 같은 값이 반복되므로 이 수는 상근수가 아님
        else: # 합이 1은 아니지만 처음 방문하는 수라면
            visited[index] = 1 # 방문 표시
        temp = str(tempSum)
ans.sort()
for i in ans:
    print(i)