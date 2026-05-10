class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:

        n = len(s)
        m = len(t)
        if n != m: return False

        word1, word2 = {},{}
        for i in range(n):
            
            if word1.get(s[i],-1) != word2.get(t[i],-1):
                return False
            
            word1[s[i]] = i
            word2[t[i]] = i
        
        return True
