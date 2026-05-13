class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)
        if n == 0: return []
        if n == 1: return [f'{nums[0]}']

        ans = []
        currStart = nums[0]
        for i in range(1,n+1):
            if i == n or nums[i] != nums[i-1] + 1 :
                end = nums[i-1]

                if currStart != end:
                    ans.append(f'{currStart}->{end}')
                else:
                    ans.append(f'{currStart}')
                
                if i<n:
                    currStart = nums[i]

        return ans