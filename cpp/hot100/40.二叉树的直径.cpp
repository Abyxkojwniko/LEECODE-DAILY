class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxlength=0;
        auto dfs=[&](this auto&& dfs,TreeNode*node)->int{
            if(node==nullptr) return -1;
            int l_len=dfs(node->left)+1;
            int r_len=dfs(node->right)+1;
            maxlength=max(maxlength,l_len+r_len);
            return max(l_len,r_len);
        };
        dfs(root);
        return maxlength;
    }
};
/*
this关键字的含义和作用
​​显式对象参数语法 (C++23 新特性)​​:
这是 C++23 引入的"显式对象参数"(explicit object parameter)语法
this关键字声明一个表示当前函数对象自身的参数
auto&& dfs定义了一个万能引用参数，代表 lambda 对象本身
​​为什么需要 this​​:
解决 lambda ​​递归调用​​的关键问题：常规 lambda 无法直接通过名称引用自身
为递归提供类型安全的"自引用"机制
避免使用 std::function的性能开销（类型擦除、虚函数调用
*/