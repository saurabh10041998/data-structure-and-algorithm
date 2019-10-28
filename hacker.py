import sys
import operator
from itertools import groupby
std = sys.stdin
if __name__ == "__main__":
    stu_data = []
    N = int(std.readline())
    for i in range(N):
        name = std.readline().rstrip('\n')
        mark = float(std.readline())
        stu_data.append((name, mark))
    test = sorted(stu_data, key=operator.itemgetter(1,0))
    it = groupby(test, key=operator.itemgetter(1))
    value = list(it)[1]
    for i in value:
        print(i[1][0])
        
    
    
