class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        n = len(s)
        m = len(t)

        if n!=m:
            return False

        freq = [0]*26

        for char in s:
            idx = ord(char) - ord('a')
            freq[idx] += 1
        
        for char in t:
            idx = ord(char) - ord('a')
            if freq[idx] == 0:
                return False
            
            else:
                freq[idx] -= 1

        return True


            