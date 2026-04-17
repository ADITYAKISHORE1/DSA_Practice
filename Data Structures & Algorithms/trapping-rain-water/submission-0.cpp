class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int ans=0;
        int maxl=height[0],maxr=height[n-1];
        while(l<=r){
            if(maxl<maxr){
                if(height[l]>maxl){
                    maxl=height[l];
                }else{
                    ans+=maxl-height[l];
                }
                l++;
            }else{
                if(height[r]>maxr){
                    maxr=height[r];
                }else{
                    ans+=maxr-height[r];
                }
                r--;
            }
        }
        return ans;
    }
};
