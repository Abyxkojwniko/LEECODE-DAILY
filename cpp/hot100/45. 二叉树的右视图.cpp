class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *p=root;
        int count=1;
        while(!q.empty()){
            int temp=0;
            while(count--){
                p=q.front();
                q.pop();
                if(p->left){
                    q.push(p->left);
                    temp++;
                }
                if(p->right){
                    q.push(p->right);
                    temp++;
                }
            }
            ans.push_back(p->val);
            count=temp;
        }
        return ans;
    }
};