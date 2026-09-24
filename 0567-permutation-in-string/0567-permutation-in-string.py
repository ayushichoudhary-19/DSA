class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        #here we just need to find if it is there or not
        # so window size is fixed, that is len of s1

        freq1 = [0]*26
        freq2 = [0]*26

        i=0
        for char in s1:
            freq1[ord(char) - ord('a')] += 1

        for j in range(len(s2)):
            freq2[ord(s2[j]) - ord('a')] += 1

            if j-i+1 == len(s1):
                if freq1 == freq2:
                    return True
                else:
                    freq2[ord(s2[i]) - ord('a')] -=1
                    i += 1
        return False
            
            
