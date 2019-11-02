# piling up cube(i) on top cube(j) side(j) >= side(i)
# stacking leftmost or rightmost (popleft, pop) ===> deque 
# 4 3 2 1 3 4
# order : 4(L)[4,3,2,1,3,4] => 4(R)[3,2,1,3,4] => 3(L)[3,2,1,3] => 3(R) => 2(L) => 1(L/R) ===> yes
# 1 3 2
# order: 2(R) => 1(L)

# logic: select left or right depending upon current top

from collections import deque
import sys

std = sys.stdin

T = int(std.readline())
for i in range(T):
    data = deque(map(int, std.readline().rstrip('\n').split(' ')))
    possible = True
    x = sys.maxsize     # initially ground

    while len(data) > 0 and possible:
        if x >= max(data[0], data[-1]): #current top x
            if data[0] > data[-1]:
                x =  data.popleft()
            else:
                x = data.pop()
        else:
            possible = False
    if len(data) == 0 and possible:
        print("Yes")
    else:
        print("No")