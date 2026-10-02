class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:

        prev = [0]*(len(text2)+1)

        for i in range(len(text1)-1,-1,-1):
            curr = [0]*(len(text2)+1)
            for j in range(len(text2)-1,-1,-1):

                if text1[i] == text2[j]:
                    #this letter can be a part of common subsequence
                    curr[j] = 1 + prev[j+1]
                else:
                    curr[j] = max(prev[j], curr[j+1])

            prev = curr
        return prev[0]
