class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int n = s.size();
        int ans = 0;
        unordered_set<char> map;
        for(; right < n; ++right){
            char ch = s[right];
            while(map.count(ch)){
                char c = s[left++];
                map.erase(c);
            }
            map.insert(ch);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};