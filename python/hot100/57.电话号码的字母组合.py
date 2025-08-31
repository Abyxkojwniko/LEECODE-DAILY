Mapping = "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        n = len(digits)
        if n == 0:
            return []
        ans = []
        path = [''] * n
        def dfs(i) -> None:
            if i == n:
                ans.append(''.join(path))
                return 
            for c in Mapping[int(digits[i])]:
                path[i] = c
                dfs(i + 1)

        dfs(0)
        return ans