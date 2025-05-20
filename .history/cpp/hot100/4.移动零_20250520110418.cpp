class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        int length=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) count++;
            else nums[i-count]=nums[i];
        }
        for(int i=length-count;i<length;i++){
            nums[i]=0;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int &x:nums){
            if(x){
                swap(x,nums[j]);
                j++;
            }
        }
    }
};