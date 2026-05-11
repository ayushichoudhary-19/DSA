class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        n = len(s)
        m = len(t)

        if n!=m: return False

        freq = [0]*26

        for i in range(n):
            freq[ord(s[i])-ord('a')] += 1
            freq[ord(t[i])-ord('a')] -= 1

        for i in range(26):
            if freq[i] != 0:
                return False
            
        return True