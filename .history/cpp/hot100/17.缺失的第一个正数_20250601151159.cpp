class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0&&nums[i]<n&&nums[i]!=nums[nums[i]-1]){
                int j=nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=j;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};