# OrderedCounter: a hybrid class of the OrderedDict and counter
# Counter that remembers the order of the occurance

from collections import OrderedDict,Counter

class OrderedCounter(Counter,OrderedDict):
    pass

d = OrderedCounter(input() for _ in range(int(input())))

print(*d.values())