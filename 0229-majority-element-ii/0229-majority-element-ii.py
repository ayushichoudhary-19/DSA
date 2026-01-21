class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        res1 = 0
        res2 = 0
        count1 = 0
        count2 = 0

        for num in nums:
            if count1 == 0 and num != res2:
                res1 = num
                count1 = 1
            elif count2 == 0 and num != res1:
                res2 = num
                count2 = 1
            
            elif res1 == num:
                count1 += 1
            elif res2 == num:
                count2 += 1
            
            else:
                count1 -=1
                count2 -=1
            
        result = []
        threshold = len(nums) //3

        count1 = 0
        count2 = 0
        for num in nums:
            if num == res1:
                count1+= 1
            elif num == res2:
                count2 +=1
            
        if count1 > threshold:
            result.append(res1)
        if count2 > threshold:
            result.append(res2)
            
        return result