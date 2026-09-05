class Solution {
    vector<vector<int>> dp;
    int n;
    bool f(int i,int cnt,string& s){
        if(cnt<0) return false;
        if(i==s.size()){
            if(cnt==0) return true;
            return false;
        }
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        if(s[i]=='('){
            return dp[i][cnt]=f(i+1,cnt+1,s);
        }
        else if(s[i]==')'){
            return dp[i][cnt]=f(i+1,cnt-1,s);
        }
        return dp[i][cnt]=f(i+1,cnt+1,s)|f(i+1,cnt-1,s)|f(i+1,cnt,s);
    }
public:
    bool checkValidString(string s) {
        n=s.size();
        dp.resize(n,vector<int>(n,-1));
        return f(0,0,s);
    }
};
// ((*))())