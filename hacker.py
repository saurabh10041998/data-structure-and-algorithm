import sys
std = sys.stdin

N = int(std.readline())

pattern = "" 

space = 2*N-1

for i in range(1, N+1):
    pattern += ("* " * i).center(space, " ") + '\n'
print(pattern)
