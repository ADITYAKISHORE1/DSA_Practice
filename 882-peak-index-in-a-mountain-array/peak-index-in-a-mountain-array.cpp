class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(mid>0 and mid<n-1 and arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]) return mid;
            else if(mid>0 and arr[mid]<arr[mid-1]){
                r=mid-1;
            }else if(mid<n-1 and arr[mid]<arr[mid+1]){
                l=mid+1;
            }
        }
        return -1;
    }
};