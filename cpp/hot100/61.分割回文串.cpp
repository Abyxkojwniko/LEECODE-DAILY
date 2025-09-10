class Solution {
public:
    bool panduan(const string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;
        auto dfs = [&](this auto&& dfs, int i){
            if(i == n){
                ans.emplace_back(path);
                return;
            }
            for(int j = i; j < n; ++j){
                if(panduan(s, i, j)){
                    path.push_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};