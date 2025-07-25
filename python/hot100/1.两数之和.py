class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map=dict()
        for i,num in enumerate(nums):
            if target-num in map:
                return [map[target-num],i]
            map[nums[i]]=i
        return []