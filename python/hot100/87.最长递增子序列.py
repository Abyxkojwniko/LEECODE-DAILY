class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        ng = 0
        for x in nums:
            j = bisect_left(nums, x, 0, ng)
            nums[j] = x
            if j == ng:
                ng += 1
        return ng