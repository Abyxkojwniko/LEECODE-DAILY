class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.ans = -inf
        def dfs(node):
            if not node:
                return 0
            left = dfs(node.left)
            right = dfs(node.right)
            self.ans = max(left + right + node.val, self.ans)
            return max(max(left, right) + node.val, 0)
        dfs(root)
        return self.ans