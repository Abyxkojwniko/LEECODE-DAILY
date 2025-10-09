class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int left = 0, right = nums.size() - 1;
        int start = 0, end = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) right = mid - 1;
            else{
                left = mid + 1;
            }
        }
        if(left < nums.size() && nums[left] == target){
            start = left;
        }
        else{
            return {-1, -1};
        }
        right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }
        end = right;
        return {start, end};
    }
};