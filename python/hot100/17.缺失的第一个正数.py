class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        for i in range(n):
            while 1<=nums[i]<=n and nums[i]!=nums[nums[i]-1]:
                j=nums[i]-1
                nums[i],nums[j]=nums[j],nums[i]
        for i in range(n):
            if nums[i]!=i+1:
                return i+1
        return n+1