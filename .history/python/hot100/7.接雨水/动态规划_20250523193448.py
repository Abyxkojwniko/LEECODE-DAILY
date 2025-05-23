class Solution:
    def trap(self, height: List[int]) -> int:
        n=len(height)
        leftmax = [height[0]]*n
        rightmax = [height[-1]] * n
        if n==0: return 0
        leftmax.append(height[0])
        for i in range(1,n):
            leftmax[i]=max(leftmax[i-1],height[i])
        for i in range(n-2,-1,-1):
            rightmax[i]=max(rightmax[i+1],height[i])
        rightmax[n-1]=height[n-1]
        ans=0
        for i in range(n):
            ans+=min(leftmax[i],rightmax[i])-height[i]
        return ans