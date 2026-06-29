class Solution {
    int ans=INT_MAX;
    vector<int> tmp;
    void f(int i,int k,vector<int>&v){
        if(i<0){
            int maxm=INT_MIN;
            for(auto& val:tmp){
                maxm=max(maxm,val);
            }
            ans=min(ans,maxm);
            return;
        }
        for(int j=0;j<k;j++){
            tmp[j]+=v[i];
            f(i-1,k,v);
            tmp[j]-=v[i];
        }
        return;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        tmp.resize(k,0);
        f(cookies.size()-1,k,cookies);
        return ans;
    }
};