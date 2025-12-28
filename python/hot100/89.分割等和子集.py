class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if s % 2 == 1:
            return False
        s //= 2
        f = [True] + [False] * s
        s2 = 0
        for i, x in enumerate(nums):
            s2 = min(s2+x, s)
            for j in range(s2, x-1, -1):
                f[j] = f[j] or f[j-x]
            if f[s]:
                return True
        return False