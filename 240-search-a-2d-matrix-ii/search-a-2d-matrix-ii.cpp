class Solution {
    bool f(int i,vector<vector<int>>& mat,int target){
        int lb=lower_bound(mat[i].begin(),mat[i].end(),target)-mat[i].begin();
        if(lb==mat[i].size()) return false;
        return (mat[i][lb]==target);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,r=m-1;
        int v=0;
        while(l<=r){
            int mid=(r+l)/2;
            if(matrix[mid][0]<=target){
                v=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        for(int i=v;i>=0;i--){
            if(f(i,matrix,target)) return true;
        }
        return false;
    }
};