class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        if k<=0 or not root: return -1
        stack=[]
        count=0
        current=root
        while current or stack:
            while current:
                stack.append(current)
                current=current.left
            current=stack.pop()
            count+=1
            if count==k:
                return current.val
            current=current.right
        return -1