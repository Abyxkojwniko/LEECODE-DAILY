class Solution {
public:
    bool dfs(TreeNode *root,long long left,long long right){
        if(!root) return true;
        if(root->val<=left||root->val>=right) return false;
        return dfs(root->left,left,root->val)&&dfs(root->right,root->val,right);
    }
    bool isValidBST(TreeNode* root) {
        return  dfs(root,LONG_MIN,LONG_MAX);
    }
};

//中序遍历
class Solution {
public:
    long pre=LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValidBST(root->left)) return false;
        if(root->val<=pre) return false;
        pre=root->val;
        return isValidBST(root->right);
    }
};