class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> bool{
            if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]){
                return false;
            }
            if(k + 1 == word.size()){
                return true;
            }
            board[i][j] = 0;
            for(auto& [dx, dy] : directions){
                int x = i + dx, y = j + dy;
                if(x >= 0 && x < m && y >= 0 && y < n && dfs(x, y, k + 1)){
                    return true;
                }
            }
            board[i][j] = word[k];
            return false;
        };
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(dfs(i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};