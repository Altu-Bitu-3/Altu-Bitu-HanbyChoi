# 스택, 큐, 덱: 17298 오큰수
import sys
input = sys.stdin.readline
N = int(input())
A = list(map(int, input().split()))
cnt = [0]
res = [-1] * N
for i in range(1, N):
    while cnt and A[cnt[-1]] < A[i]:
        res[cnt.pop()] = A[i]
    cnt.append(i)
print(*res)

"""
두번째 for문을 처음부터 끝을 다 탐색하고 계신대 그러지 마시고 탐색에 필요한 정보를 스택에 넣고 비교하는 방식을 선택하는 게 좋을 것 같아요
예를 들어서 자신보다 큰 숫자가 나오기 전까지 스택에 숫자를 받아들이고 큰 숫자가 나왔을 때 스택에서 해당 숫자보다 작은 값들을 전부 pop하는 방식이죠
이렇게 한다면 예를들어 모든 숫자가 111111111이라고 할 때
O(n^2) 걸리던 방식이 O(n)만에 끝나지 않을까요? 한번의 탐색이면 오큰수가 없다는 것을 알 수 있으니까요

5 4 4 2 6 7 8 1 1 8 이렇게 있다고 하고 stack이 있다고 합시다.

먼저 5를 스택에 넣습니다. cnt = [0]

그 후 4를 확인합니다 5보다 작죠? 스택에 넣습니다. (A[0] < A[1]), cnt = [0, 1], i = 1

그 후 4를 확인합니다 4와 같죠? 스택에 넣습니다. (A[1] < A[2]), cnt = [0, 1, 2], i = 2

2를 확인합니다. 4보다 작습니다 스택에 넣습니다. (A[2] < A[3]), cnt = [0, 1, 2, 3], i = 3

6을 확인합니다. 2보다 큽니다! 이때 while문으로 스택의 가장 마지막 요소가 현재 6보다 작다면 전부 pop해줍니다.
이때 pop해주는 값들의 오큰수는 모두 6임을 알 수 있습니다. (A[3] < A[4]), cnt = [4], res = [6, 6, 6, 6, -1, ...]

이제 또 스택이 비었습니다. 7을 넣습니다.

그 후 8을 확인합니다 7보다 큽니다. while문으로 위의 과정을 또 합니다. pop되는 숫자의 오큰수는 8임을 알 수 있습니다.

이제 1을 넣습니다.

그 후 1을 확인합니다. 1과 같습니다. 스택에 넣습니다.

8을 확인합니다. 1보다 큽니다 while문을 돌려줍니다.

8은 마지막 숫자이기에 오큰수가 없습니다.
"""