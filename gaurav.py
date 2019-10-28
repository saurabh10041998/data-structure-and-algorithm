import sys
std = sys.stdin

marksheet = []
scoresheet = []

N = int(std.readline())

for i in range(N):
    name = input()
    score = float(std.readline())
    marksheet += [[name, score]]
    scoresheet += [score]
marksheet.sort()
x=sorted(set(scoresheet))
y = x[1] 
for n,s in marksheet:
    if s == y:
        print(n)
    