class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root) q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            for(int i=q.size();i!=0;--i){
                root=q.front();
                q.pop();
                tmp.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};