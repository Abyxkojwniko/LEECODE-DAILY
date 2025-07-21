class Solution {
public:
    TreeNode* dfs(vector<int> &nums,int left,int right){
        if(left==right) return nullptr;
        int middle=left+(right-left)/2;
        return new TreeNode(nums[middle],dfs(nums,left,middle),dfs(nums,middle+1,right));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0,nums.size());
    }
};