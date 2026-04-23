class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        unordered_map<long long, pair<long long, long long>> mpp;
        for(int i=0;i<n;i++){
            auto& it=mpp[nums[i]];
            it.first+=1;
            it.second+=i;
            arr[i]=(it.first*i)-it.second;
        }
        mpp.clear();
        for(int i=n-1;i>=0;i--){
            auto& it=mpp[nums[i]];
            it.first+=1;
            it.second+=i;
            arr[i]+=it.second-(it.first*i);
        }
        return arr;
    }
};