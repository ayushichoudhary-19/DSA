class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        mapping = {}
        for s in strs:
            newS = "".join(sorted(s))

            if newS in mapping:
                mapping[newS].append(s)
            else:
                mapping[newS] = [s]

        ans = []

        for key in mapping:
            ans.append(mapping[key])

        return ans