class Solution:
    def maxArea(self, height: List[int]) -> int:
        i,j = 0, len(height)-1
        maxArr = 0

        while i < j:
            area = (j-i) * min(height[i],height[j])
            maxArr = max(maxArr, area)
        
            if(height[i] <= height[j]): i+=1
            else: j-=1
        
        return maxArr