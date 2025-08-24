class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        q = deque()
        minutes = 0
        fresh = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.append((i, j))
                if grid[i][j] == 1:
                    fresh += 1
        if not fresh:
            return 0
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while q:
            size = len(q)
            infected = False
            for i in range(size):
                x, y = q.popleft()
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 1:
                        grid[nx][ny] = 2
                        q.append((nx, ny))
                        fresh -= 1
                        infected = True
            if infected:
                minutes += 1
        return minutes if fresh == 0 else -1

        
        