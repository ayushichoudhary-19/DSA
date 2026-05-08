class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i,j = 0,0
        n1,n2 = len(s), len(t)

        if n1 > n2: return False

        cnt = 0

        while i < n1 and j < n2:
            if s[i] == t[j]:
                cnt += 1
                i += 1
            j+=1

        return cnt == n1

        
        