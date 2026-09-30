class Solution:
    def __init__(self):
        self.mapp = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }

        self.ans = []

    def helper(self,digits,currstr):
        if digits == '':
            self.ans.append(currstr)
            return

        ch = digits[0]
        digits = digits[1:]
        for char in self.mapp[ch]:
            self.helper(digits,currstr+char)
        


    def letterCombinations(self, digits: str) -> list[str]:
        self.helper(digits,'')
        return self.ans
