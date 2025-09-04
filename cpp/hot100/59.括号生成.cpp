class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        auto dfs = [&](this auto&& dfs, int left, int right) -> void{
            if(left == 0 && right == 0){
                ans.push_back(path);
                return;
            }
            if(left > 0){
                path.push_back('(');
                dfs(left - 1, right);
                path.pop_back();
            }
            if(right > left){
                path.push_back(')');
                dfs(left, right - 1);
                path.pop_back();
            }
        };
        dfs(n, n);
        return ans;
    }
};