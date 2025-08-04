class Solution:
    MOD = 10**9 + 7

    def power(self, base, exp):
        if exp == 0:
            return 1
        
        half = self.power(base, exp // 2)
        result = (half * half) % self.MOD
        if exp % 2 == 1:
            result = (result * base) % self.MOD
        return result

    def countGoodNumbers(self, n: int) -> int:
        even_count = (n + 1) // 2
        odd_count = n // 2

        return (self.power(5, even_count) * self.power(4, odd_count)) % self.MOD

output = Solution().countGoodNumbers(1)
print(output)