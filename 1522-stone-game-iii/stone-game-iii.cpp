class Solution {
    vector<int> dp;
    int f(int i,int & n,vector<int>& v){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int t=INT_MIN;
        t=max(t,v[i]-f(i+1,n,v));
        if(i<n-1) t=max(t,v[i]+v[i+1]-f(i+2,n,v));
         if (i<n-2) t=max(t,v[i]+v[i+1]+v[i+2]-f(i+3,n,v));
        return dp[i]=t;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        dp.resize(n,-1);
        int v=f(0,n,stoneValue);
        // cout<<v;
        if(v>0) return "Alice";
        else if(v<0) return "Bob";
        return "Tie";
    }
};