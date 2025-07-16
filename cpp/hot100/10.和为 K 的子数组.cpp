class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1;
        int ans=0,sum=0;
        for(auto num:nums){
            sum+=num;
            if(map.find(sum-k)!=map.end()){
                ans+=map[sum-k];
            }
            map[sum]++;
        }
        return ans;
    }
};