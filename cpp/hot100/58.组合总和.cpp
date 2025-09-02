class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        auto dfs = [&](this auto&& dfs, int i, int sum) -> void{
            if(sum == target){
                ans.emplace_back(path);
                return;
            }
            if(sum > target || i == n) return;
            dfs(i + 1, sum);
            path.emplace_back(candidates[i]);
            dfs(i, sum + candidates[i]);
            path.pop_back();
        };
        dfs(0, 0);
        return ans;
    }
};