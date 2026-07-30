class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<bool> dp(n,false);
        // dp[0]=true;
        for(int i=0;i<n;i++){
            bool t=false;
            for(int j=0;j<=i;j++){
                string tmp=s.substr(j,i-j+1);
                if(st.count(tmp)) t|=(j-1<0)?true:dp[j-1];
            }
            dp[i]=t;
        }
        return dp[n-1];
    }
};