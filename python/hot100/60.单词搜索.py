class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        def dfs(i, j, k) -> bool:
            if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[k]:
                return False
            if k + 1 == len(word):
                return True
            board[i][j] = ' '
            for dx, dy in directions:
                nx, ny = i + dx, j + dy
                if 0 <= nx < m and 0 <= ny < n and dfs(nx, ny, k + 1):
                    return True
            board[i][j] = word[k]
            return False
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False