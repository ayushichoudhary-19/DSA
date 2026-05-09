class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i,j = 0,0
        n = len(s)
        ans = 0
        track = {}
        curr = 0
   

        while i<n and j<n and i<=j:
            if s[j] in track and track[s[j]] >= i:
                    i = track[s[j]] + 1
                
            track[s[j]] = j
            j += 1

            curr = j-i
            ans = max(curr,ans)
        
        return ans