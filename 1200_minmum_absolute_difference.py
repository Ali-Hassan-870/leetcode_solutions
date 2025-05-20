from typing import List
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        min_diff = float('inf')
        output = []

        for i in range(1, len(arr)):
            min_diff = min(min_diff, arr[i]-arr[i-1])
        
        for i in range(1, len(arr)):
            if arr[i] - arr[i-1] == min_diff:
                output.append([arr[i-1], arr[i]])
    
        return output

input = [3,8,-10,23,19,-4,-14,27]
output = Solution().minimumAbsDifference(input)
print(output)