class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        vector<pair<long long, long long>> left(n);
        vector<pair<long long, long long>> right(n);
        unordered_map<long long, pair<long long, long long>> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].first+=1;
            mpp[nums[i]].second+=i;
            left[i]={mpp[nums[i]].first,mpp[nums[i]].second};
        }
        mpp.clear();
        for(int i=n-1;i>=0;i--){
            mpp[nums[i]].first+=1;
            mpp[nums[i]].second+=i;
            right[i]={mpp[nums[i]].first,mpp[nums[i]].second};
        }
        for(int i=0;i<n;i++){
            long long l=(left[i].first*i)-left[i].second;
            long long r=right[i].second-(right[i].first*i);
            arr[i]=l+r;
        }
        return arr;
    }
};