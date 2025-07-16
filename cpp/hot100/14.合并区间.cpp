class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals); 
        vector<vector<int>> ans;
        for (auto& p : intervals) {
            if (!ans.empty() && p[0] <= ans.back()[1]) { 
                ans.back()[1] = max(ans.back()[1], p[1]); 
            } else { 
                ans.emplace_back(p); 
            }
        }
        return ans;
    }
};