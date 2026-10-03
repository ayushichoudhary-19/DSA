class Solution:
    def findNumberOfLIS(self, nums: list[int]) -> int:

        n = len(nums)

        prev = [0] * (n+1)
        prev_count = [1] * (n+1)

        # as last taken index can be from -1 to n-1 so we have n+1 options
        # but we do index shift by making +1, so that -1 is represented by 0
        # in dp and so on

        for i in range(n-1,-1,-1):

            curr = [0] * (n+1)
            curr_count = [0] * (n+1)

            for lasttakenidx in range(i-1,-2,-1):

                # take in subsequence
                take = -1
                take_count = 0

                if lasttakenidx == -1 or nums[lasttakenidx] < nums[i]:
                    take = 1 + prev[i+1]
                    take_count = prev_count[i+1]

                # don't take
                dont_take = prev[lasttakenidx+1]
                dont_take_count = prev_count[lasttakenidx+1]

                if take > dont_take:
                    curr[lasttakenidx+1] = take
                    curr_count[lasttakenidx+1] = take_count

                elif dont_take > take:
                    curr[lasttakenidx+1] = dont_take
                    curr_count[lasttakenidx+1] = dont_take_count

                else:
                    curr[lasttakenidx+1] = take
                    curr_count[lasttakenidx+1] = take_count + dont_take_count

            prev = curr
            prev_count = curr_count

        return prev_count[0]