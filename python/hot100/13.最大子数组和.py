class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans=nums[0]
        sum=0
        for num in nums:
            sum=max(sum+num,num)
            ans=max(ans,sum)
        return ans