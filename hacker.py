import re
import sys
first_multiple_input = input().rstrip().split()

n = int(first_multiple_input[0])

m = int(first_multiple_input[1])

matrix = []

for _ in range(n):
    matrix_item = input()
    matrix.append(matrix_item)
string = ""
for t in zip(*matrix):
    string += "".join(t)

string = re.sub(r"([a-zA-Z0-9])[^a-zA-Z0-9]+([a-zA-Z0-9])", r"\1 \2",string)
print(string)

