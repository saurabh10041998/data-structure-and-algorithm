import copy
class Fenwick:
    def __init__(self, a) :
        for(idx, v) in enumerate(a):
            nextIdx = (idx + 1) + lowestSetBit(idx + 1) - 1
            if nextIdx < len(a):
                a[nextIdx] += v
        
        self.tree = a
    
    def __str__(self):
        return str(self.tree)
    
    # calculate the prefix sum upto index i
    def prefixSum(self, idx):
        if idx < 1:
            raise Exception("Invalid index, must be atleast 1")
        if idx > len(self.tree):
            raise Exception("Index out of bound exception")

        ans = 0
        while idx > 0:
            ans += self.tree[idx - 1]
            idx -= lowestSetBit(idx)
        
        return ans
    
    # calculate range sum
    def range(self, start, end):
        if start < 1:
            raise Exception("Invalid index, must be atleast 1")
        if end > len(self.tree):
            raise Exception("Index out of bound exception")
        if start > end:
            raise Exception("End must be greater than equal to start")
        if start == 1:
            return self.prefixSum(end)
        
        return self.prefixSum(end) - self.prefixSum(start - 1)
    
    #for idx of 1 based index, delta is amount to be incremented or decremented
    def update(self, idx, delta):
        if idx < 1:
            raise Exception("Invalid index, must be atleast 1")
        if idx > len(self.tree):
            raise Exception("Index out of bound exception")
        while idx <= len(self.tree):
            self.tree[idx-1] += delta
            idx += lowestSetBit(idx)
        
    def updateToValue(self, idx, value):
        if idx < 1:
            raise Exception("Invalid index, must be atleast 1")
        if idx > len(self.tree):
            raise Exception("Index out of bound exception")
        delta = value - self.tree[idx-1]
        while idx <= len(self.tree):
            self.tree[idx-1] += delta
            idx += lowestSetBit(idx)
    
    
def lowestSetBit(idx):
    return (idx & -idx)
    
if __name__ == "__main__":
    a = [1,2,3,4,5,6,7,8,9,10]
    tree = Fenwick(copy.deepcopy(a))
    print(tree)