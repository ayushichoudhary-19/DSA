class RandomizedSet:

    def __init__(self):
        self.set1 = set()

    def insert(self, val: int) -> bool:
        ans = val in self.set1
        if ans == False:
            self.set1.add(val)
        return not ans

    def remove(self, val: int) -> bool:
        ans = val in self.set1
        if ans == True:
            self.set1.remove(val)
        return ans

    def getRandom(self) -> int:
        tup = tuple(self.set1)
        return random.choice(tup)
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()