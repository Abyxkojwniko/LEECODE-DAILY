class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftmax(n),rightmax(n);
        leftmax[0]=height[0],rightmax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],height[i]);
        }
        for(int i=n-2;i>0;i--){
            rightmax[i]=max(rightmax[i+1],height[i]);
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans+=min(leftmax[i],rightmax[i])-height[i];
        }
        return ans;
    }
};

/*
    这是最简单的解法，首先考虑一个问题，如何确定heigth[i]能接多少雨水
    那么应该是一个差值，这个差值应该是左边最大和右边最大中的最小值减去这个点本身的高度
    如果任何一边没有大于这个点的高度的点，那么这个点就无法街到雨水
    所以max的值应该包括本身的点的高度，最后算的时候这个点会自己减去自己
    不影响最后的答案
*/