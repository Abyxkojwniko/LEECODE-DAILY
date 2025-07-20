class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:return []
        q=deque([root])
        ans=[]
        while q:
            level=[]
            for _ in range(len(q)):
                cur=q.popleft()
                level.append(cur.val)
                if(cur.left): q.append(cur.left)
                if(cur.right): q.append(cur.right)
            ans.append(level)
        return ans
