class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        jump = 0
        current_end = 0
        forecast = 0
        for i in range(n - 1):
            forecast = max(forecast, i + nums[i])
            if i == current_end:
                current_end = forecast
                jump += 1
                if current_end >= n - 1:
                    break
        return jump