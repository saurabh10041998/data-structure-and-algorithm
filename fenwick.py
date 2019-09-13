class Fenwick:
    def __init__(self, a):
        for (idx, v) in enumerate(a):
            nextIdx = (idx + 1) + lowestSetBit(idx+1) - 1
            if nextIdx < len(a):
                a[nextIdx] += v
        self.tree = a
    

    def __str__(self):
        return str(self.tree)
    

    # Find the prefix sum of elements from start of array to idx inclusive
    def prefixSum(self, idx):
        if idx < 1:
            raise Exception("Invalid index, must be atleast 1")
        if idx > len(self.tree):
            raise Exception("Index out of exception")
        ans = 0
        while idx > 0:
            ans += self.tree[idx-1]
            idx -= lowestSetBit(idx)
        return ans

    # Find the sum of elements from start to end inclusive
    def range(self, start, end):
        if start < 1:
            raise Exception("Starting index must be atleast 1")
        if end < start:
            raise Exception("End index must be greater than or equal to start")
        if start == 1:
            return self.prefixSum(end)
        else: 
            return self.prefixSum(end) - self.prefixSum(start - 1)
        
    # idx of 1-based array, delta is amount to increment/ decrement
    def update(self, idx, value):
        if idx < 1:
            raise Exception("Invalid index, must be atleast 1")
        if idx > len(self.tree):
            raise Exception("Index out of exception")
        while idx <= len(self.tree):
            self.tree[idx - 1] +=delta
            idx += lowestSetBit(idx)
    
    # idx of 1-based array, value is actual value to change to
    def updateToValue(self, idx, value):
        if idx < 1:
            raise Exception("Invalid index, must be atleast 1")
        if idx > len(self.tree):
            raise Exception("Index out of bound exception")
        delta = value - self.tree[idx - 1]
        while idx <= len(self.tree):
            self.tree[idx -1] += delta
            idx += lowestSetBit(idx)
    
    
def lowestSetBit(idx):
    return (idx & -idx)
    