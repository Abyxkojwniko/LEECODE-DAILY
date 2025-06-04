class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftmax=0,rightmax=0;
        int ans=0;
        int left=0,right=n-1;
        while(left<right){
            leftmax=max(height[left],leftmax);
            rightmax=max(height[right],rightmax);
            if(height[left]<height[right]){
                ans+=leftmax-height[left];
                left++;
            }
            else{
                ans+=rightmax-height[right];
                right--;
            }
        }
        return ans;
    }
};