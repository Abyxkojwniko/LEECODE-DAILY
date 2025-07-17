class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        maxlength=0
        def dfs(node):
            nonlocal maxlength#这样设定是为了表示这个值能够保证在这里面被修改和调用，是一个闭包变量
            if not node:
                return -1
            l_len=dfs(node.left)+1
            r_len=dfs(node.right)+1
            maxlength=max(l_len+r_len,maxlength)
            return max(l_len,r_len)
        dfs(root)
        return maxlength