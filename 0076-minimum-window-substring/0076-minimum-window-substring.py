from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        m = len(t)
        n = len(s)

        if m > n:
            return ""

        wordCount = Counter(t)
        currCount = Counter()

        minlen = float('inf')
        ans = ""

        i, j = 0, 0


        currCount[s[j]] += 1

        while i < n and j < n and i <= j and i >= 0:


            currStr = s[i:j+1]

            if currCount >= wordCount:

                currLen = j - i + 1

                if currLen <= minlen:
                    ans = currStr
                    minlen = currLen
                currCount[s[i]] -= 1
                i += 1

            else:
                j += 1
                if j<n: currCount[s[j]] += 1

        return ans