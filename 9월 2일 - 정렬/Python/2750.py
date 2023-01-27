# 정렬: 2750 수 정렬하기
import sys

input = sys.stdin.readline
n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))
arr.sort()
# arr = sorted(arr)
# arr = bubble_sort(arr)
for i in range(len(arr)):
    print(arr[i])

"""
def bubble_sort(arr):
    for i in range(len(arr)-1, 0, -1):
        for j in range(i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr
"""