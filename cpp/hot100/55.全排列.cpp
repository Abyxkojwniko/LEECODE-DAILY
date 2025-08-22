class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> path(n), on_path(n);
        auto dfs = [&](this auto && dfs, int i){
            if (i == n){
                ans.push_back(path);
                return ;
            }
            for (int j = 0; j < n; j++){
                if(!on_path[j]){
                    path[i] = nums[j];
                    on_path[j] = true;
                    dfs(i + 1);
                    on_path[j] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};