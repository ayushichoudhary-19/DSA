from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str):
        m = len(t)
        n = len(s)

        if m > n:
            return ""

        wordCount = Counter(t)
        currCount = Counter()

        need = len(wordCount)
        have = 0

        minlen = float('inf')
        ans = ""

        i, j = 0, 0

        currCount[s[j]] += 1

        if s[j] in wordCount and currCount[s[j]] == wordCount[s[j]]:
            have += 1

        while i < n and j < n and i <= j:

            currStr = s[i:j+1]

            if have == need:

                currLen = j - i + 1

                if currLen <= minlen:
                    ans = currStr
                    minlen = currLen

                if s[i] in wordCount and currCount[s[i]] == wordCount[s[i]]:
                    have -= 1

                currCount[s[i]] -= 1
                i += 1

            else:
                j += 1

                if j < n:

                    currCount[s[j]] += 1

                    if s[j] in wordCount and currCount[s[j]] == wordCount[s[j]]:
                        have += 1

        return ans