# hotel room: captain + number of k membered family..
# one room => captain and one room per group
# room entry(groups) => k times per group
# except captains room 
# set{lst} = room num of all
# K*sum(set) - sum_cal = (K*group + K*captain) - (K*group + captain) = (K-1)*captain // (K-1) = captain
import sys
std = sys.stdin
if __name__ == "__main__":
    K = int(std.readline())
    lst = [int(x) for x in std.readline().split()]
    sum_list = 0
    data_set  = set()
    for i in lst:
        data_set.add(i)
        sum_list += i
    print((sum(data_set) * K - sum_list) // (k-1))

    