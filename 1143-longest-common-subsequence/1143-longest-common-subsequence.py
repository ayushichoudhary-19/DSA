class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        arr1 = []
        arr2 = []

        def dfs(i,curr,mainstr,arr):
            
            if i == len(mainstr):
                arr.append(curr[:])
                return

            #take
            dfs(i+1,curr + mainstr[i],mainstr,arr)

            #not take
            dfs(i+1,curr,mainstr,arr)

        dfs(0,"",text1,arr1)
        dfs(0,"",text2,arr2)

        maxlen = 0
        #now compare to get longest string common in both
        for subseq in arr2:
            if subseq in arr1:
                maxlen = max(maxlen,len(subseq))
        
        return maxlen
