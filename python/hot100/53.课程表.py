class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        for a, b in prerequisites:
            graph[b].append(a)
        colors = [0] * numCourses
        def dfs(x):
            colors[x] = 1
            for y in graph[x]:
                if colors[y] == 1 or colors[y] == 0 and dfs(y):
                    return True
            colors[x] = 2
            return False
        for i, c in enumerate(colors):
            if c == 0 and dfs(i):
                return False
        return True
