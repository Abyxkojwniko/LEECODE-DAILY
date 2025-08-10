class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        if(k<=0) return -1;
        stack<TreeNode*> stack;
        TreeNode* current=root;
        int count=0;
        while(current||!stack.empty()){
            while(current){
                stack.push(current);
                current=current->left;
            }
            current=stack.top();
            stack.pop();
            count++;
            if(count==k) return current->val;
            current=current->right;
        }
        return -1;
    }
};