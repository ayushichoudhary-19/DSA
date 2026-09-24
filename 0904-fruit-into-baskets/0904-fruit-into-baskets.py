class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        n = len(fruits)
        if n == 1:
            return 1
        
        i,j = 0,0
        hashmap = {}
        currcount = 0
        maxcount = 0

        for j in range(n):
            hashmap[fruits[j]] = hashmap.get(fruits[j], 0) + 1
            currcount += 1
            
            while len(hashmap) > 2:
                currcount -= 1
                hashmap[fruits[i]] -= 1

                if hashmap[fruits[i]] == 0:
                    del hashmap[fruits[i]]
            
                i += 1
                
            maxcount = max(maxcount,currcount)
        return maxcount