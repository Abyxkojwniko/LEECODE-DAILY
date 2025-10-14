class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int less = 0;
        int ans_left = -1, ans_right = m;
        int count[128]{};
        for(auto c : t){
            if(count[c] == 0) ++less;
            ++count[c];
        }
        int left = 0;
        for(int right = 0; right < m; ++right){
            char c = s[right];
            --count[c];
            if(count[c] == 0) --less;
            while(less == 0){
                if(right - left < ans_right - ans_left){
                    ans_left = left;
                    ans_right = right;
                }
                char c = s[left];
                if(count[c] == 0) ++less;
                ++count[c];
                ++left;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};