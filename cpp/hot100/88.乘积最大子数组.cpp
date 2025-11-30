class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        long long maxp = nums[0], minp = nums[0], result = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; ++i){
            long long num = nums[i];
            auto temp = maxp;
            maxp = max(num, max(num * temp, num * minp));
            minp = min(num, min(num * temp, num * minp));
            result = max(maxp, result);
        }
        return result;
    }
};