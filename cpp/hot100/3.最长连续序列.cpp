class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int length=0;
        for(auto x:st){
            if(st.contains(x-1)) continue;
            int y=x+1;
            while(st.contains(y)) y++;
            length=max(length,y-x);
        }
        return length;
    }
};