class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        hashmap = {}

        for word in strs:
            temp = "".join(sorted(word))
            if temp in hashmap:
                hashmap[temp].append(word)
            else:
                hashmap[temp] = [word]

        ans = []
        for key in hashmap:
            ans.append(hashmap[key])

        return ans