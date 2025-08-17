class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.ans = 0
        prefix_sum = defaultdict(int)
        prefix_sum[0] = 1
        def dfs(node, pre_sum):
            if not node:
                return
            
            pre_sum += node.val
            self.ans += prefix_sum[pre_sum-targetSum]
            prefix_sum[pre_sum] += 1
            dfs(node.left, pre_sum)
            dfs(node.right,pre_sum)
            prefix_sum[pre_sum]-=1
        dfs(root, 0)
        return self.ans