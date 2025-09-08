class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        index = n - 2
        while index >= 0 and nums[index] >= nums[index + 1]:
            index -= 1
        if index >= 0:
            j = n - 1
            while nums[j] <= nums[index]:
                j -= 1
            nums[index], nums[j] = nums[j], nums[index]

        left, right = index + 1, n - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1