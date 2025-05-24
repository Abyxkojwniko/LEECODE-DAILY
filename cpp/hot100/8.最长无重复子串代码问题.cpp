class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_ser<char> map;
        int left=0,right=0;
        for(right;right<n;right++){
            char ch=s[right];
            while(map.count(ch)){
                char c=s[left++];
                map.erase(c);
            }
            set.insert(ch);
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};