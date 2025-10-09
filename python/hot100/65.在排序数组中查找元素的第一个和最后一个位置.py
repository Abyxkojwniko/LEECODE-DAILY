class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums: return [-1, -1]
        n = len(nums)
        left, right = 0, n - 1
        start, end = 0, 0
        while left <= right:
            mid = (left + right) // 1
            if nums[mid] >= target:
                right = mid - 1
            else:
                left = mid + 1
        if left >= n or nums[left] != target:
            return [-1, -1]
        start = left
        right = n - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        end = right
        return [start, end]