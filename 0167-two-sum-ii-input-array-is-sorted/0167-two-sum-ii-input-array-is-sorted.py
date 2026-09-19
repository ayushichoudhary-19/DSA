class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        start,end = 0, len(numbers)-1

        while start < end:
            total = numbers[start] + numbers[end]
            if total == target:
                return [start+1,end+1]
            elif total < target:
                start += 1
            else:
                end -= 1

        return []
