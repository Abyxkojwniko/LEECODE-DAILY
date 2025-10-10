class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int last = nums.back();
        while(left < right){
            int mid = left + (right - left) / 2;
            int x = nums[mid];
            if(target > last && x <= last){
                right = mid;
            }
            else if(target <= last && x > last){
                left = mid + 1;
            }
            else if(x >= target){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return nums[right] == target ? right : -1;
    }
};