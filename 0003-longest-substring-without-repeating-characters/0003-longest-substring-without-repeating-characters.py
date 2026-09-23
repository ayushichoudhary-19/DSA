class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        hashmap = {}
        ans =  0

        i,j = 0,0
        while j < len(s) and i<=j:
            if s[j] in hashmap:
                # start new window from duplicate's already existing's next
                i = max(i, hashmap[s[j]] + 1)
            
            ans = max(ans,j-i+1)
            hashmap[s[j]] = j
            
            j += 1
                
        return ans