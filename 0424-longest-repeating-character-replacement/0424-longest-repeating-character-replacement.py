class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        maxsize = 0
        maxfreq = 0

        i,j=0,0
        hashmap = {}

        while j<len(s):
            hashmap[s[j]] = hashmap.get(s[j],0)+1
            maxfreq = max(maxfreq, hashmap[s[j]])
            

            while (j-i+1) - maxfreq > k:
                hashmap[s[i]] -= 1
                i += 1
            
            maxsize = max(maxsize,j-i+1)
            j += 1

        return maxsize
