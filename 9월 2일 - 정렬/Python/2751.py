# 정렬: 2751 수 정렬하기 2
import sys
input = sys.stdin.readline
n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))
arr.sort()
# arr = merge_sort(arr)
for i in range(len(arr)):
    print(arr[i])
"""
def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    # 재귀함수를 이용해 끝까지 분할
    mid = len(arr)
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    i, j= 0, 0
    array = []
  
    # 둘중 하나조건에 부합하지 않을경우 while문 빠져나감 
    while i < len(left) and j < len(right): 
        if left[i] < right[j]:
            array.append(left[i])
            i+=1
        else:
            arr.append(right[j])
            j+=1

    # while문 빠져 나온 후, left혹은 right에 남은 요소들 arr에 넣어주기
    array += left[i:] 
    array += right[j:]
    
    return array"""