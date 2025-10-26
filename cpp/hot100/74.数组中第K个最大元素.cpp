class Solution {
pair<int, int> partition(vector<int>& nums, int left, int right) {
    swap(nums[left + rand() % (right - left + 1)], nums[left]);
    int pivot = nums[left];
    int lt = left;      // nums[left..lt] < pivot
    int gt = right;     // nums[gt..right] > pivot
    int i = left + 1;   // nums[lt+1..i-1] = pivot
    while (i <= gt) {
        if (nums[i] < pivot) {
            // 小于基准值，与 lt+1 交换，lt 和 i 同步右移
            swap(nums[i], nums[lt + 1]);
            lt++;
            i++;
        } else if (nums[i] > pivot) {
            // 大于基准值，与 gt 交换，gt 左移，i 不动 (因为换回来的 nums[i] 还没检查)
            swap(nums[i], nums[gt]);
            gt--;
        } else {
            // 等于基准值，i 右移
            i++;
        }
    }
    
    // 将基准值换到正确位置
    swap(nums[left], nums[lt]);
    
    return {lt, gt}; // 返回等于 pivot 的元素的范围
}

public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        int n = nums.size();
        int target = n - k; // 目标索引 (第 k 大转换为第 n-k 小)
        int left = 0, right = n - 1;

        while (left <= right) {
            pair<int, int> range = partition(nums, left, right);
            int start_idx = range.first;  // = pivot 区域的起始
            int end_idx = range.second;   // = pivot 区域的结束
            
            if (target >= start_idx && target <= end_idx) {
                // 目标索引在 = pivot 的区域内，找到了！
                return nums[target];
            } else if (target < start_idx) {
                // 目标在 < pivot 的区域内
                right = start_idx - 1;
            } else { // target > end_idx
                // 目标在 > pivot 的区域内
                left = end_idx + 1;
            }
        }
        return -1; // 不可能发生
    }
};