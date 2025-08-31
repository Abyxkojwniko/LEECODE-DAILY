class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> current;
        auto dfs = [&](this auto&& dfs, int index) -> void{
            if(index == n){
                ans.emplace_back(current);
                return ;
            }
            dfs(index + 1);
            current.emplace_back(nums[index]);
            dfs(index + 1);
            current.pop_back();
        };
        dfs(0);
        return ans;
    }
};