# 구현 & 코너케이스: 14891 톱니 바퀴
import sys
input = sys.stdin.readline
arr = []
for _ in range(4):
    arr.append(input().rstrip())
K = int(input())

def rotate(num, dir):
    original = arr[num]
    if dir == 1:
        arr[num] = original[-1] + original[:-1]
    elif dir == -1:
        arr[num] = original[1:] + original[0]

def compare(num1, num2, dir):
    if ((num1 < num2) and (arr[num1][2] != arr[num2][6])) or ((num1 > num2) and (arr[num1][6] != arr[num2][2])):
        cmd.append((num2, dir))
        return True # rotate
    return False # no rotation

for _ in range(K):
    cmd = []
    num, dir = map(int, input().split())
    cmd.append((num-1, dir))
    if num == 1:
        if (compare(0, 1, -1*dir)):
            if (compare(1, 2, dir)):
                compare(2, 3, -1*dir)
    elif num == 2:
        compare(1, 0, -1*dir)
        if (compare(1, 2, -1*dir)):
            compare(2, 3, dir)
    elif num == 3:
        if compare(2, 1, -1*dir):
            compare(1, 0, dir)
        compare(2, 3, -1*dir)
    elif num == 4:
        if (compare(3, 2, -1*dir)):
            if (compare(2, 1, dir)):
                compare(1, 0, -1*dir)
    while cmd:
        rotate(cmd[0][0], cmd[0][1])
        cmd.pop(0)
score = 1; result = 0
for i in range(4):
    if arr[i][0] == '1':
        result += score
    score *= 2
print(result)