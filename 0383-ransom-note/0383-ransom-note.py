class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:

        if len(ransomNote) > len(magazine): return False
        freq = Counter(magazine)

        for ch in ransomNote:
            if freq[ch] == 0:
                return False

            freq[ch] -= 1

        return True