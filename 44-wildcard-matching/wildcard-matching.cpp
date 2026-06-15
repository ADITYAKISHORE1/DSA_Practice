class Solution {
    vector<vector<int>> dp;
    bool f(int i,int j,string&s,string&p){
        if(i<0 and j<0) return true;
        if(i<0 or j<0){
            if(j>=0 and p[j]=='*') return f(i,j-1,s,p);
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool take=0;
        if(s[i]==p[j] or p[j]=='?'){
            take=f(i-1,j-1,s,p);
        }else if(p[j]=='*'){
            take=f(i-1,j,s,p)|f(i-1,j-1,s,p)|f(i,j-1,s,p);
        }
        return dp[i][j]=take;
    }
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        dp.resize(m,vector<int>(n,-1));
        // int chk=0;
        // for(auto& c:p) if(c=='*'){ chk++;}
        if(n==0 and m>0) return false;
        return f(m-1,n-1,s,p);
    }
};