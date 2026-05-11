class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        sList = s.split(' ')
        mapping = {}
        m = len(pattern)
        n = len(sList)
        if m!=n: return False

        for i in range(n):
            if pattern[i] in mapping and mapping[pattern[i]] != sList[i]+'*' or sList[i]+'*' in mapping and mapping[sList[i]+'*'] != pattern[i]:
                        return False
            
            else:
                mapping[pattern[i]] = sList[i]+'*'
                mapping[sList[i]+'*'] = pattern[i]
         

        return True

