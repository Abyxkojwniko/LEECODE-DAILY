class Solution {
public:
    int minDistance(string s, string t) {
        int m = t.length();
        vector<int> f(m + 1);
        for (int j = 0; j < m; j++) {
            f[j + 1] = j + 1;
        }
        for (char x : s) {
            int pre = f[0];
            f[0]++; // f[0] = i + 1
            for (int j = 0; j < m; j++) {
                int tmp = f[j + 1];
                f[j + 1] = x == t[j] ? pre : min({f[j + 1], f[j], pre}) + 1;
                pre = tmp;
            }
        }
        return f[m];
    }
};