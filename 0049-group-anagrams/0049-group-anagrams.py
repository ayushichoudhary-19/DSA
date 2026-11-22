class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        

        hashmap = {}

        for word in strs:
            key = "".join(sorted(word))
            if key not in hashmap:
                hashmap[key] = []
            hashmap[key].append(word)

        ans = list(hashmap.values())
        
        return ans


            