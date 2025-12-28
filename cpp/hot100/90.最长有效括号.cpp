class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, left = 0, right = 0;
        for (char ch : s) {
            if (ch == '(') {
                left++;
            } else {
                right++;
            }
            if (left < right) { 
                left = right = 0;
            } else if (left == right) { 
                ans = max(ans, right * 2);
            }
        }

        left = right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                left++;
            } else {
                right++;
            }
            if (left < right) { 
                left = right = 0;
            } else if (left == right) { 
                ans = max(ans, right * 2);
            }
        }
        return ans;
    }
};
