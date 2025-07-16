class Solution {
    static constexpr int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> ans(m*n);
        int i=0,j=0,dir=0;
        for(int k=0;k<m*n;k++){
            ans[k]=matrix[i][j];
            matrix[i][j]=INT_MAX;
            int x=i+DIRS[dir][0];
            int y=j+DIRS[dir][1];
            if(x<0||x>=m||y<0||y>=n||matrix[x][y]==INT_MAX){
                dir=(dir+1)%4;
            }
            i+=DIRS[dir][0];
            j+=DIRS[dir][1];
        }
        return ans;
    }
};