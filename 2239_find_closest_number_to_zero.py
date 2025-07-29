from typing import List

class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        closest = nums[0]
        for num in nums:
            if abs(num) < abs(closest):
                closest = num
        
        if closest < 0 and abs(closest) in nums:
            return abs(closest)
        else:
            return closest

s = Solution()
print(s.findClosestNumber([-4,-2,1,4,8]))