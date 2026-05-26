class NumMatrix {
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat=matrix;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j]+=mat[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=mat[row2][col2];
        if(row1>0) sum-=mat[row1-1][col2];
        if(col1>0) sum-=mat[row2][col1-1];
        if(row1>0 and col1>0) sum+=mat[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */