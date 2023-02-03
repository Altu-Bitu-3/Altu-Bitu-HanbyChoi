# 브루트포스: 1544 사이클 단어
import sys
input = sys.stdin.readline

def isSame(s1, s2):
    if len(s1) != len(s2):
        return False
    for i in range(len(s1)):
        if s1 == s2:
            return True
        else:
            s2 = s2[-1] + s2[:-1]
    return False
    
N = int(input())
word = []
for i in range(N):
    word.append(input().rstrip())
diffword = [word[0]]
for i in word:
    found_same = False
    for j in diffword:
        if isSame(i, j):
            found_same = True
            break
        else:
            continue
    if not found_same:
        diffword.append(i)
print(len(diffword))