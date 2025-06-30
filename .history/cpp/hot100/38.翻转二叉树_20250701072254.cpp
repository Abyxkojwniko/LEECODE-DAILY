class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        if(root->left||root->right){
            TreeNode *temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};