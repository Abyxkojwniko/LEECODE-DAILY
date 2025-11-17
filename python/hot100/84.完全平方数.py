class Solution:
    def numSquares(self, n: int) -> int:
        if n == 0:
            return 0
        f = [float('inf')] * (n + 1)
        f[0] = 0
        for i in range(1, n + 1):
            j = 1
            while j * j <= i:
                f[i] = min(f[i], f[i - j * j] + 1)
                j += 1

        return f[n]