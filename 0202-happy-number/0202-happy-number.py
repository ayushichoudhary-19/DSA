class Solution:

    def sumSqDig(self,n: int) -> int:
        sum = 0
        while n > 0:
            q = int(n/10)
            digit = n%10
            sum += digit**2

            n = q
        
        return sum


    def isHappy(self, n: int) -> bool:
        slow = self.sumSqDig(n)
        fast = self.sumSqDig(self.sumSqDig(n))

        while slow != fast:
            if fast == 1: return True


            slow = self.sumSqDig(slow)
            fast = self.sumSqDig(self.sumSqDig(fast))

        return slow == 1