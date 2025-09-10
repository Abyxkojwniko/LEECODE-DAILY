class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        ans = []
        path = []
        def dfs(i) -> None:
            if i == n:
                ans.append(path.copy())
                return
            for j in range(i, n):
                t = s[i : j + 1]
                if t == t[::-1]:
                    path.append(t)
                    dfs(j + 1)
                    path.pop()
        dfs(0)
        return ans