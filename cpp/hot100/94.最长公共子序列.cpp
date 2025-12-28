class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int m = t.length();
        vector<int> f(m + 1);
        for (char x : s) {
            for (int j = 0, pre = 0; j < m; j++) {
                int tmp = f[j + 1];
                f[j + 1] = x == t[j] ? pre + 1 : max(f[j + 1], f[j]);
                pre = tmp;
            }
        }
        return f[m];
    }
};