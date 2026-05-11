class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        mapping = {}
        for s in strs:
            freq = [0]*26

            for ch in s:
                freq[ord(ch) - ord('a')] += 1

            
            if tuple(freq) in mapping:
                mapping[tuple(freq)].append(s)
            else:
                mapping[tuple(freq)] = [s]

        return list(mapping.values())