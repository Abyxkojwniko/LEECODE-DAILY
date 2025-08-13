class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        index={x: i for i,x in enumerate(inorder)}
        def dfs(pre_l,pre_r,in_l,in_r)->Optional[TreeNode]:
            if pre_l==pre_r:
                return None
            left_size=index[preorder[pre_l]]-in_l
            left=dfs(pre_l+1,pre_l+left_size+1,in_l,in_l+left_size)
            right=dfs(pre_l+left_size+1,pre_r,in_l+left_size+1,in_r)
            return TreeNode(preorder[pre_l],left,right)
        return dfs(0,len(preorder),0,len(preorder))