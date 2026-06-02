class Solution {
    bool pred(int div,vector<int>&v,int thr){
        int sum=0;
        for(auto& i:v){
            sum+=(i+div-1)/div;
        }
        return sum<=thr;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=1e9,mid; 
        while(l<r){
            mid=l+(r-l)/2;
            if(pred(mid,nums,threshold)){
                r=mid;
            }else l=mid+1;
        }
        return l;
    }
};