# css parsing 
# format => 
"""
selector
{ ===> start flag = true
    property: value,
} ===> start flag = false

"""
# pattern for css color parsing =>
# pat = ​^#[0-9A-Fa-f]{3,6}$

import re
x = re.compile(r"​^#[0-9A-Fa-f]{3,6}$")
bo = re.compile(r'\{')
bc = re.compile(r'\}')
if __name__ == "__main__":
    start = False
    N = int(input())
    for i in range(N):
        string = input()
        #check for curly braces
        if bo.search(string):
            start = True
        elif bc.search(string):
            start = False
        elif start:
             prop, value = string.split(":")
             y = re.findall(x, value)
             print(y)
        else:
            continue      