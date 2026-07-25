class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,1e9);
        v[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int mn=1e9;
            for(int j=0;j<=nums[i];j++){
                if(i+j<n) mn=min(mn,v[i+j]);
            }
            v[i]=1+mn;
        }
        return v[0];
    }
};