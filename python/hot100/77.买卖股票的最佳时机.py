class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minv= prices[0];
        for(auto p : prices){
            ans = max(ans, p - minv);
            minv = min(minv, p);
        }
        return ans;
    }
};