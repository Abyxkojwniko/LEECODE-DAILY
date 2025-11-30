class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        maxp, minp, result = nums[0], nums[0], nums[0]
        n = len(nums)
        for i in range(1, n):
            num = nums[i]
            temp = maxp
            maxp = max(num, num * temp, num * minp)
            minp = min(num, num * temp, num * minp)
            result = max(maxp, result)
        return result