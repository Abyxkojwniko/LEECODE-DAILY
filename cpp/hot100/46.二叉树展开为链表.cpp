class Solution {
public:
vector<TreeNode*> ans;
    void dfs(TreeNode *root){
        if(!root) return ;
        ans.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        dfs(root);
        for(int i=0;i<ans.size()-1;i++){
            ans[i]->right=ans[i+1];
            ans[i]->left=nullptr;
        }
        if(!ans.empty()){
            ans.back()->left=nullptr;
            ans.back()->right=nullptr;
        }
    }   
};