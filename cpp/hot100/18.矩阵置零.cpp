class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int flag=false;
        for(int i=0;i<m;i++){
            if(!matrix[i][0]) flag=true;
            for(int j=1;j<n;j++){
                if(!matrix[i][j]) matrix[i][0]=matrix[0][j]=0;
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=1;j<n;j++){
                if(!matrix[i][0]||!matrix[0][j]){
                    matrix[i][j]=0;
                }
            }
            if(flag){
                matrix[i][0]=0;
            }
        }
    }
};