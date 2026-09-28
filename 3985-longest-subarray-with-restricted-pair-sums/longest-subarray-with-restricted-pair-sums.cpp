class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxLen=0;
        int l=0;
        unordered_map<int,int> mpp;
        for(int r=0;r<n;r++){
            vector<int> v;
            for(int i=l;i<r;i++){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                if(mpp.count(nums[i]+nums[r]) or mpp.count(abs(nums[i]-nums[r]))){
                    l=i+1;
                    v.clear();
                }else{
                    v.push_back(nums[i]);
                }
            }
            maxLen=max(maxLen,r-l+1);
            for(auto& i:v) mpp[i]++;
            mpp[nums[r]]++;

        }
        return maxLen;
    }
};