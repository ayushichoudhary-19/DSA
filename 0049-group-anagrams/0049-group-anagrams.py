class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        hashmap = {}
        for word in strs:
            freq = [0]*26

            for char in word:
                idx = ord(char) - ord('a')
                freq[idx] += 1
            
            
            tup = tuple(freq)
            if tup in hashmap:
                hashmap[tup].append(word)

            else:
                hashmap[tup] = [word]
            
        return list(hashmap.values())

        