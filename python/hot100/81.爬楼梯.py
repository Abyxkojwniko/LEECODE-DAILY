class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        a ,b = 1, 2
        ans = 0
        for i in range(n-2):
            ans = a + b
            a = b
            b = ans
        return ans