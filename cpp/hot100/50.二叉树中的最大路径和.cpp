class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> int{
            if(node == nullptr){
                return 0;
            }
            int left = dfs(node->left);
            int right = dfs(node->right);
            ans = max(ans, left + right + node->val);
            return max(max(left, right) + node->val, 0);
        };
        dfs(root);
        return ans;
    }
};