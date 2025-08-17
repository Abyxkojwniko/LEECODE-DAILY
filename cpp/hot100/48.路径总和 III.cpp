class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        unordered_map<long long, int> count{{0,1}};
        auto dfs=[&](this auto&& dfs, TreeNode *node, long long s){
            if(!node) return ;
            s += node->val;
            ans += count[s-targetSum];
            count[s]++;
            dfs(node->left, s);
            dfs(node->right, s);
            count[s]--;
        };
        dfs(root, 0);
        return ans;
    }
};