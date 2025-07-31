from collections import defaultdict

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        count = defaultdict(int)

        for c in text:
            if c in "ballon":
                count[c] += 1
        
        for c in "ballon":
            if c not in count:
                return 0
        
        return min(count['b'], count['a'], count['l'] // 2, count['o'] // 2, count['n'])

print(Solution().maxNumberOfBalloons("leetcode"))