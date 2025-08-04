from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []

        def backtrack(curr, open_count, close_count):
            if open_count <= 0 and close_count <= 0:
                result.append(curr)
                return
            
            if open_count > 0:
                backtrack(curr + '(', open_count - 1, close_count)
            
            if close_count > open_count:
                backtrack(curr + ')', open_count, close_count - 1)

        backtrack("", n, n)
        return result
    
output = Solution().generateParenthesis(5)
print(output)