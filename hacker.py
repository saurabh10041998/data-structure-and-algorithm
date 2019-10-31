# given  input i upto N
# analyse width from center
# N = 3
# c-b-a-b-c
# space on right side from a 2*N - 1
# space on left side upto a 2*(N-1) = 2*N - 2
# total space = 2*N-1 + 2*N -2 = 4*N - 3 (width)
# upper_dome =
# generate the string upto  loop (correct_loop) times = lst => concatenate  (lst - lst[0])[-1] + lst: center width times
#lower_dome = reverse(upper_dome)
from string import ascii_lowercase
import sys

std = sys.stdin

if __name__ == "__main__":
    N = int(std.readline())
    width = 4*N - 3 
    lst1 = list(ascii_lowercase[:N])    
    lst2 = list(ascii_lowercase[1:N])
    lst2 = lst2[::-1]
    lst2.extend(lst1)
    middle_string = "-".join(lst2)
    
    upper_dome = ""   
    #correct_loop
    for i in range(1,N):        
        lst = list(ascii_lowercase[N-i:N])
        ans = ""
        if len(lst[1:]) != 0:        
            ans = "-".join(lst[1:][::-1]) + "-" +"-".join(lst)
        else:
            ans = "".join(lst)
        upper_dome += ans.center(width, "-") + '\n'       
    

    print(upper_dome+middle_string+upper_dome[::-1])