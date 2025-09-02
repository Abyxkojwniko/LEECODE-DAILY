class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        n = len(candidates)
        sum = 0
        ans = []
        path = []
        def dfs(i, sum) -> None:
            if sum is target:
                ans.append(path.copy())
                return
            if sum > target or i == n:
                return 
            dfs(i + 1, sum)
            path.append(candidates[i])
            dfs(i, sum + candidates[i])
            path.pop()
        dfs(0, 0)
        return ans