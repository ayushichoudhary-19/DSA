class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        arr = s.split(' ')
        n = len(arr)
        for i in range(n-1,-1,-1):
            if arr[i] == '':
                continue
            else: return len(arr[i])