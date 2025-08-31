class Solution {
public:
    static constexpr string Mapping[10]= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0) return {};
        vector<string> ans;
        string path(n, 0);
        auto dfs = [&](this auto&& dfs, int i) -> void{
            if(i == n){
                ans.emplace_back(path);
                return ;
            }
            for(char c : Mapping[digits[i] - '0']){
                path[i] = c;
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};