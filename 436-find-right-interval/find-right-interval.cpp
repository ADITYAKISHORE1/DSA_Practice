class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>st;
        for(int i=0;i<n;i++){
            st.push_back({intervals[i][0],i});
        }
        sort(st.begin(),st.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            int l=0,r=n-1,mid;
            int as=-1;
            while(l<=r){
                mid=l+(r-l)/2;
                if(st[mid][0]>=intervals[i][1]){
                    as=st[mid][1];
                    r=mid-1;
                }else l=mid+1;
            }
            ans.push_back(as);
        }
        return ans;
    }
};