class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        current = []
        n = len(nums)
        def dfs(index) -> None:
            if index == n:
                ans.append(current.copy())
                return 
            dfs(index + 1)
            current.append(nums[index])
            dfs(index + 1)
            current.pop()
        dfs(0)
        return ans