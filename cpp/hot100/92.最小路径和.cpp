class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector f(m+1, vector<int>(n+1, INT_MAX));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 && j == 0){
                    f[1][1] = grid[i][j];
                }
                else{
                    f[i+1][j+1] = min(f[i+1][j], f[i][j+1]) + grid[i][j];
                }
            }
        }
        return f[m][n];
    }
};