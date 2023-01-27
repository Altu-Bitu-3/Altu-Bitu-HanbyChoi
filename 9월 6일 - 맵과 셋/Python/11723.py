import sys
input = sys.stdin.readline
M = int(input())
s = set()
for i in range(M):
	cmd = input().split()
	if len(cmd) == 1:
		if (cmd[0] == "all"):
			s = set([i for i in range(1, 21)])
		elif (cmd[0] == "empty"):
			s = set()
	else:
		cmd[1] = int(cmd[1])
		if (cmd[0] == "add"):
			s.add(cmd[1])
		elif (cmd[0] == "remove"):
			s.discard(cmd[1])
		elif (cmd[0] == "check"):
			print(1 if cmd[1] in s else 0)
		elif (cmd[0] == "toggle"):
			if (cmd[1] in s):
				s.discard(cmd[1])
			else:
				s.add(cmd[1])