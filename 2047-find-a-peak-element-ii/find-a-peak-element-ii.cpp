class Solution {
    int maxElement(int r,vector<vector<int>>& mat){
        int maxVal=INT_MIN;
        int maxIdx=-1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][r]>maxVal){
                maxVal=mat[i][r];
                maxIdx=i;
            }
        }
        return maxIdx;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int row=maxElement(mid,mat);
            int left=(mid-1>=0)?mat[row][mid-1]:INT_MIN;
            int right=(mid+1<n)?mat[row][mid+1]:INT_MIN;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }else if(mat[row][mid]<left){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return {-1,-1};
    }
};