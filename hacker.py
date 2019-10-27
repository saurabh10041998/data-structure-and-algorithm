def pattern(n,text):
    for i in range(1,n):
        for j in range((n-1)-i,0,-1):
            print(end=" ")
        for k in range(i,0,-1):
            print("*",end=" ")
        print()
    print(text)
    for i in range(n-1,0,-1):
        for  j in range(n-i-1,0,-1):
            print(end=" ")
        for k in range(0,i,1):
            print("*",end=" ")
        print()
n=int(input())
text = input()
pattern(n,text)