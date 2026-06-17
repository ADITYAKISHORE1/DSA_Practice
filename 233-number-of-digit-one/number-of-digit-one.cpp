class Solution {
    int dp[11][2][10];
    int sz;
    int f(int i,int tight,int cnt,vector<int>&v){
        if(i==sz) return cnt;
        if(dp[i][tight][cnt]!=-1) return dp[i][tight][cnt];
        int res=0;
        int lim=tight?v[i]:9;
        for(int d=0;d<=lim;d++){
            int ntight=tight && (d==v[i]);
            res+=f(i+1,ntight,cnt+(d==1),v);
        }
        return dp[i][tight][cnt]=res;
    }
public:
    int countDigitOne(int n) {
        vector<int> v;
        while(n!=0){
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin(),v.end());
        sz=v.size();
        memset(dp,-1,sizeof(dp));
        return f(0,1,0,v);
    }
};