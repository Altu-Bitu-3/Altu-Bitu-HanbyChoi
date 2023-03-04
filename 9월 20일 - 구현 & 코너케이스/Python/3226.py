# 구현 & 코너케이스: 3226 전화요금
import sys
input = sys.stdin.readline
N = int(input())
total = 0
while N:
    HM, DD = input().rstrip().split()
    HH, MM = map(int, HM.split(':')); DD = int(DD)
    price = 0
    if 7 <= HH < 18 or (HH == 18 and (MM + DD) <= 60):
        price = DD * 10
    elif HH < 6 or HH >= 19 or (HH == 6 and (MM + DD) <= 60):
        price = DD * 5
    else: 
        diff = 60 - MM
        if HH == 18:
            price = diff * 10 + (DD - diff) * 5
        elif HH == 6:
            price = diff * 5 + (DD - diff) * 10
    total += price
    N -= 1
print(total)