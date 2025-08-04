from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        def backtrack(start: int, curr: List[int], total: int):
            if total == target:
                result.append(list(curr))
                return
            if total > target:
                return
            
            for i in range(start, len(candidates)):
                curr.append(candidates[i])
                backtrack(i, curr, total + candidates[i])
                curr.pop()

        backtrack(0, [], 0)
        return result
    
output = Solution().combinationSum([2,3,5], 8)
print(output)