import sys
std =  sys.stdin

s  = std.readline().rstrip("\n")
kevin,stuart = 0, 0

n = len(s)

for i in range(len(s)):
    if s[i] in ['A','E','I','O','U']:
        kevin += n-i
    else:
        stuart += n-i

if stuart > kevin:
    print("Stuart", stuart)
elif stuart < kevin:
    print("Kevin", kevin)
else:
    print("Draw")