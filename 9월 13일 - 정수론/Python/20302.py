# 정수론: 20302 민트 초코
import sys
input = sys.stdin.readline
"""
[민트초코]
1. 우선 소인수분해 경로를 저장한 배열을 만든다 (is_prime 함수)
2. 들어오는 수를 소인수 분해하여 소인수의 개수를 저장하는 배열을 만든다.
3. * 뒤에 들어오는 수는 소인수 +1, / 뒤에 들어오는 수는 소인수 -1
4. 모든 소인수에 대해 0개 이상이 있으면 민트초코, 아니면 치약!
"""
MAX = 100000

def is_prime():
    # 소인수 분해 경로를 리턴하는 함수
    prime = [0] * (MAX + 1)

    root_MAX = MAX ** (1/2)

    for i in range(2, int(root_MAX)+1):
        # 소수가 아니라면 continue
        if prime[i] > 0:
            continue

        # i가 소수일 경우, i 기록
        for j in range(i*i, MAX, i):
            if prime[j] == 0:
                prime[j] = i
                
    return prime

def calc(prime, arr):
    answer = [0]*(MAX + 1)

    for i in range(1, len(arr), 2):
        if arr[i-1] == '*':
            flag = 1
        else:
            flag = -1
        
        temp = abs(int(arr[i]))     # 곱하거나 나눠지는 수의 부호는 상관이 없다
        
        # 0이 곱해지면 무조건 정수이므로 바로 종료
        if temp == 0:
            return "mint chocolate"
        
        # temp가 소수가 될 때까지
        while prime[temp] > 0:
            answer[prime[temp]] += flag
            temp //= prime[temp]
        
        # 마지막 남은 소수 표기
        answer[temp] += flag

    # 2부터 검사해서 모든 소인수에 대해 0보다 크거나 같은지 확인한다.
    for cnt in answer[2:]:
        if cnt < 0:
            return "toothpaste"
    
    return "mint chocolate"
    

n = int(input())
arr = ('* ' + input()).split()  # 입력 맨 앞에 *를 넣어주어 항상 직전의 연산자를 확인하고 진행한다.
prime = is_prime()
print(calc(prime, arr))


""" 시간초과 코드
def getPrime(N):
    is_prime = [True for i in range(N+1)]
    for i in range(2, int(N**0.5)+1):
        if is_prime[i]:
            for j in range(i*i, N+1, i):
                is_prime[j] = False
    prime = []
    for i in range(2, N+1):
        if is_prime[i]:
            prime.append(i)
    return prime

N = int(input())
form = input().split()
prime = getPrime(100000)
mul = {}; div = {}

def factorization(num, dic):
    if num == 0 or num == 1:
        return
    for i in prime:
        while (num % i == 0):
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1
            num /= i
        if num == 1:
            break
    return

def y_n(mul, div):
    for key in div:
        if key in mul:
            mul[key] -= div[key]
            if (mul[key] < 0):
                return False
        else:
            return False
    return True

for i in range(0, len(form), 2):
    form[i] = abs(int(form[i]))
factorization(form[0], mul) # 첫번째 숫자 곱하기에 넣기
for i in range(1, len(form), 2):
    if form[i] == '*':
        factorization(form[i+1], mul)
    elif form[i] == '/':
        factorization(form[i+1], div)

if y_n(mul, div):
    print("mint chocolate")
else:
    print("toothpaste")
"""