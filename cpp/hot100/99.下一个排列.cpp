class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = n - 2;
        while(index >= 0 && nums[index] >= nums[index+1]){
            --index;
        }
        if(index >= 0){
            int j = n-1;
            while(nums[j] <= nums[index]){
                --j;
            }
            swap(nums[j], nums[index]);
        }
        reverse(nums.begin() + index + 1, nums.end());

    }
};