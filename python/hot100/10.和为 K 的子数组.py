class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        counts=defaultdict(int)
        counts[0]=1
        sum,ans=0,0
        for num in nums:
            sum+=num
            ans+=counts[sum-k]
            counts[sum]+=1
        return ans