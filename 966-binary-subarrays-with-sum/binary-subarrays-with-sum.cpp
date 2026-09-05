class Solution {
    int f(vector<int>& v,int goal){
        int cnt=0,sum=0;
        int l=0;
        for(int r=0;r<v.size();r++){
            sum+=v[r];
            while(l<=r and sum>goal){
                sum-=v[l];
                l++;
            }
            cnt+=r-l+1;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums,goal)-f(nums,goal-1);
    }
};