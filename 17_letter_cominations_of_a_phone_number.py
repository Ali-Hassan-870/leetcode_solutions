from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        phone_map = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}

        result = []
        def backtrack(index, curr):
            if index == len(digits):
                result.append(curr)
                return
            
            for char in phone_map[digits[index]]:
                backtrack(index + 1, curr + char)

        backtrack(0, "")
        return result

output = Solution().letterCombinations("2378")
print(output)