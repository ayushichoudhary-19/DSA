class Solution:

    def letterCombinations(self, digits: str) -> List[str]:
        mapping = {
            '2' : ['a','b','c'],
            '3' : ['d','e','f'],
            '4' : ['g','h','i'],
            '5' : ['j','k','l'],
            '6' : ['m','n','o'],
            '7' : ['p','q','r','s'],
            '8' : ['t','u','v'],
            '9' : ['w','x','y','z']
        }
        
        ans = []
        currword = ''
        def dfs(start, currword):
            if len(currword) == len(digits):
                ans.append(currword[:])
                return
            
            digit = digits[start]
            for letter in mapping[digit]:
                dfs(start+1,currword + letter)

        dfs(0,currword)
        return ans