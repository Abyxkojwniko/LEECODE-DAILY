class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int sum=0;
        for(auto num:nums){
            sum=max(sum+num,num);
            ans=max(sum,ans);
        }
        return ans;
    }
};