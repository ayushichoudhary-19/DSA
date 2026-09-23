class Solution:
    def maxArea(self, height: list[int]) -> int:
        l,r = 0,len(height)-1
        maxarea = 0
        while l<r:
            area = (r-l)*min(height[l],height[r])
            maxarea = max(maxarea,area)
            if height[l]>height[r]:
                r -= 1
            else:
                l += 1

        return maxarea