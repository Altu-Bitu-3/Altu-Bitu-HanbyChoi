import sys
input = sys.stdin.readline
N = int(input())
dict_in = {} ; arr_out = []
for i in range(N):
	car = input().rstrip()
	dict_in[car] = i # car는 i번째 차의 이름
for i in range(N):
	tmp = input().rstrip()
	arr_out .append(dict_in[tmp])
cnt = 0
for i in range(N-1):
	for j in range(i+1, N):
		if (arr_out[i] > arr_out[j]):
			cnt += 1
			break
print(cnt)