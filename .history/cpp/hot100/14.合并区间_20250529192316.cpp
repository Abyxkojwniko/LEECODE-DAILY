class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> temp1=intervals[0];
        for(int i=1;i<intervals.size();i++){
            auto temp2=intervals[i];
            if(temp2[0]<=temp1[1]){
                temp1[1]=max(temp1[1],temp2[1]);
            }
            else{
                ans.push_back(temp1);
                temp1=temp2;
            }
        }
        ans.push_back(temp1);
        return ans;
    }
};