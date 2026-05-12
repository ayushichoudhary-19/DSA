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
        visit = set()

        while n not in visit:
            visit.add(n)
            n = self.sumSqDig(n)
            if n == 1:
                return True

        return False