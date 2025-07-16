class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals); // 按照左端点从小到大排序
        vector<vector<int>> ans;
        for (auto& p : intervals) {
            if (!ans.empty() && p[0] <= ans.back()[1]) { // 可以合并
                ans.back()[1] = max(ans.back()[1], p[1]); // 更新右端点最大值
            } else { // 不相交，无法合并
                ans.emplace_back(p); // 新的合并区间
            }
        }
        return ans;
    }
};