class Solution:
    def maxEnvelopes(self, envelopes: list[list[int]]) -> int:
        

        #sort as order doesnt matter and then find lenght of longest increasing sizes

        # envelopes.sort(key=lambda x: (width ↑, height ↓))
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        print(envelopes)

        n = len(envelopes)


        # We sort width ascending so width violations become monotonic, and for equal widths we sort height descending so equal-width envelopes can never form an increasing height subsequence. This lets us safely reduce the 2D problem to a 1D strict LIS on height.

        def length_of_lis(nums):
            if not nums:
                return 0
                
            sub = []
            
            for w, h in nums:
                left, right = 0, len(sub) - 1

                while left <= right:
                    mid = (left + right) // 2

                    if sub[mid] >= h:
                        right = mid - 1
                    else:
                        left = mid + 1
                
                if left == len(sub):
                    sub.append(h)
                else:
                    sub[left] = h
                    
            return len(sub)

        return length_of_lis(envelopes)