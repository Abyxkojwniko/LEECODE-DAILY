class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=0;j<(n+1)/2;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
                matrix[j][n-i-1]=temp;
            }
        }
    }
};

//matrix[row][col]，在旋转后，它的新位置为 matrix[col][n−row−1]
//经历4次旋转，变回原位置