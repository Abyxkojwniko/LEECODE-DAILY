class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        ranges::reverse(nums);
        ranges::reverse(nums.begin(),nums.begin()+k);
        ranges:;reverse(nums.begin()+k,nums.end());
    }
};