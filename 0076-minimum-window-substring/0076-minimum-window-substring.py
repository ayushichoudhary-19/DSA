class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
        need = {}
        window = {}

        minlen = float('inf')
        start = 0

        i=0
        for char in t:
            need[char] = need.get(char,0) + 1

        required = len(need)
        formed = 0

        for j in range(len(s)):
            window[s[j]] = window.get(s[j],0) + 1
            
            if s[j] in need and window[s[j]] == need[s[j]]:
                formed += 1
            
            while formed == required:
                if j - i + 1 < minlen:
                    minlen = j - i + 1
                    start = i

                window[s[i]] -= 1

                if s[i] in need and window[s[i]] < need[s[i]]:
                    formed -= 1
        
                i += 1
                
        return "" if minlen == float('inf') else s[start:start + minlen]