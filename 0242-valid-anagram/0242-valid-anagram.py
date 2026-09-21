class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq = {}
        if len(s) != len(t):
            return False

        for l in s:
            if l in freq:
                freq[l] += 1
            else:
                freq[l] = 1

        for l in t:
            if l in freq:
                freq[l] -= 1
                if freq[l] == 0:
                    del freq[l]

            else:
                return False
            

        return True
            