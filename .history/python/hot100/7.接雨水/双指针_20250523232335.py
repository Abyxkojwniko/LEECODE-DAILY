class Solution:
    def trap(self, height: List[int]) -> int:
        n=len(height)
        leftmax,rightmax,left,right=0,0,0,n-1
        ans = 0
        while left < right:
            leftmax=max(height[left],leftmax)
            rightmax=max(height[right],rightmax)
            if leftmax < rightmax:
                ans+=(leftmax-height[left])
                left+=1
            else:
                ans+=(rightmax-height[right])
                right-=1
        return ans