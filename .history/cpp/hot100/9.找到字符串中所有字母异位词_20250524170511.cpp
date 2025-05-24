class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        array<int,26> count_p{},count_s{};
        for(auto c:p){
            count_p[c-'a']++;
        }
        for(int right=0;right<s.size();right++){
            count_s[s[right]-'a']++;
            int left=right-p.length()+1;
            if(left<0) continue;
            if(count_p==count_s) ans.push_back(left);
            count_s[s[left]-'a']--;
        }
        return ans;
    }
};