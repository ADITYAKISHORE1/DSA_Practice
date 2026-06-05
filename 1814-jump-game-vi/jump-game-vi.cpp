class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> st;
        vector<int> idx(n);
        for(int i=n-1;i>=0;i--){
            if(st.size()>k){
                auto lb=st.lower_bound(idx[i+k+1]);
                st.erase(lb);
            }
            int mx=0;
            if(!st.empty())
                mx=*st.rbegin();
            st.insert(mx+nums[i]);
            idx[i]=mx+nums[i];
        }
        return idx[0];
    }
};