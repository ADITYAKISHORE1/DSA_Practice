class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<long long> dp(n,0);
        vector<long long> best(n+1,0);
        vector<int> st;
        for(auto& i:meetings) st.push_back(i[0]);

        for(int i=n-1;i>=0;i--){
            int lb=lower_bound(st.begin(),st.end(),meetings[i][1])-st.begin();
            dp[i]=meetings[i][2];
            if(lb<n){
                dp[i]=max(dp[i],meetings[i][2]-meetings[i][1]+best[lb]);
            }
            best[i]=max(best[i+1],st[i]+dp[i]);
        }
        long long maxm=0;
        for(auto&i: dp) maxm=max(i,maxm);
        return maxm;
    }
};

/*
dp[i]=revenue[i]+(start[j]-end[i])+dp[j];
here dp[j] means earnings starting from j
so we can rewrite->
dp[i]=(revenue[i]-end[i])+(start[j]+dp[j]);
                          '--------------' (we need this to be maximum possible)
    so for it lets take best[j]=max(start[j]+dp[j]) from j->n-1;
*/