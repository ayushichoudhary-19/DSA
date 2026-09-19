class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        hashmap = {}

        for word in strs:
            freq = [0]*26
            for letter in word:
                index = ord(letter) - ord('a')
                freq[index] += 1
            
            #Python lists cannot be used as dictionary keys, but tuples can.
            tup = tuple(freq)
            if tup in hashmap:
                hashmap[tup].append(word)
            else:
                hashmap[tup] = [word]

        return list(hashmap.values())