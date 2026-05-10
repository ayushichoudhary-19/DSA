class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:

        n = len(s)
        m = len(t)
        if n != m: return False

        count1 = Counter(s)
        count2 = Counter(t)
        if len(count1) !=len(count2): return False

        for i in range(len(count1)):
            if count1[i] != count2[i]:
                return False

        return True