class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []
        q=deque([root])
        ans=[]
        while q:
            size=len(q)
            for i in range(size):
                node=q.popleft()
                if i==size-1:
                    ans.append(node.val)
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
        return ans