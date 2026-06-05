class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> st;
        vector<int> idx(n);
        for(int i=n-1;i>=0;i--){
            if(st.size()>k){
            //For associative containers (set, multiset, map, multimap), almost always prefer the container's member functions
                auto lb=st.lower_bound(idx[i+k+1]); // use member lower_bound function
                                                    // bcz general lower_bound here cost O(n)
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