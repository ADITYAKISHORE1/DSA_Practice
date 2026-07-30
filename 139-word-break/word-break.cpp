class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            bool t=false;
            for(int j=1;j<=i;j++){
                string tmp=s.substr(j-1,i-j+1);
                if(st.count(tmp)) t|=dp[j-1];
            }
            dp[i]=t;
        }
        return dp[n];
    }
};