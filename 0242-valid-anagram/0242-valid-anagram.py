class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        cntS = Counter(s)
        cntT = Counter(t)

        return cntS == cntT
