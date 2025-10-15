class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int m = nums1.size(), n = nums2.size();
        int left = -1, right = m;
        while (left + 1 < right) { 
            int i = left + (right - left) / 2;
            int j = (m + n + 1) / 2 - i - 2;
            if (nums1[i] <= nums2[j + 1]) {
                left = i; 
            } else {
                right = i; 
            }
        }
        int i = left;
        int j = (m + n + 1) / 2 - i - 2;
        int ai = i >= 0 ? nums1[i] : INT_MIN;
        int bj = j >= 0 ? nums2[j] : INT_MIN;
        int ai1 = i + 1 < m ? nums1[i + 1] : INT_MAX;
        int bj1 = j + 1 < n ? nums2[j + 1] : INT_MAX;
        int max1 = max(ai, bj);
        int min2 = min(ai1, bj1);
        return (m + n) % 2 ? max1 : (max1 + min2) / 2.0;
    }
};