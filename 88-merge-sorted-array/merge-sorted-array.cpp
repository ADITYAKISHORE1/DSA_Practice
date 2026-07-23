class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1;
        int r=m+n-1;
        while(i>=0 and j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[r]=nums1[i];
                i--;
            }else{
                nums1[r]=nums2[j];
                j--;
            }
                r--;
        }
        while(i>=0){
            nums1[r]=nums1[i];
            r--;
            i--;
        }
        while(j>=0){
            nums1[r]=nums2[j];
            r--;
            j--;
        }
    }
};