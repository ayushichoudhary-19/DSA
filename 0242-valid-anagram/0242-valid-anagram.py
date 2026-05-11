class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        print(sorted(s))
        
        
        newS =  "".join(sorted(s))
        newT =  "".join(sorted(t))

        return newS == newT