def check(l, r, bit):
    left = [0] * 26
    right = [0] * 26
    while r > 0:
        for i in range(26):
            right[i] += bit[r][i]
        r -= lowestSetBit(r)
    
    while l > 0:
        for i in range(26):
            left[i] += bit[l][i]
        l -= lowestSetBit(l)
    
    for i in range(26):
        right[i] = right[i] - left[i]
    
    odd = False
    
    for i in range(26):
        if right[i] % 2 == 1 and not odd:
            odd = True
        elif right[i] % 2 == 1:
            return False
    
    return True


def updateBit(S, i, newval, bit):
    oldval = ord(S[i-1]) - 97
    S = list(S)
    S[i-1] = chr(97 + newval)
    S = "".join(S)
    while i <= len(S):
        bit[i][oldval]-= 1
        bit[i][newval]+= 1
        i += lowestSetBit(i)
    for l in bit:
        print(l)             
    result = {'S': S, 'bit': bit}
    return result



def construct(S):
    bit = [[0]*26 for _ in range(len(S) + 1)]
    for i in range(len(S)):
        bit = update(i, len(S), bit, ord(S[i]) - 97)
    for l in bit:
        print(l)
    return bit
    

def update(i, n, bit, val):
    i += 1
    while i <= n:
        bit[i][val]+= 1
        i += lowestSetBit(i)
    return bit


def lowestSetBit(idx):
    return (idx & -idx)


def main():
    N, Q = map(int, input().split())

    S = input()

    bit = construct(S)

    for i in range(Q):
        a,b,c = input().split()
        if a == '1':
            b = int(b)
            c = ord(c) - 97
            result = updateBit(S, b, c, bit)
            bit = result['bit']
            S = result['S']
            print(S)
            for l in bit:
                print(l)        
        else:
            l = int(b)
            r = int(c)
            if check(l-1, r, bit):
                print("yes")
            else:
                print("no")


if __name__ == "__main__":
    main()

