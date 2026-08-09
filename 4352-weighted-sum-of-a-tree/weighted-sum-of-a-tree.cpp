class Solution {
    long long maxDepth=1;
    long long f(int i,vector<int>& par,vector<long long>&dep){
        if(par[i]==-1) return 1;
        if(dep[i]!=-1) return dep[i];
        long long d=1+f(par[i],par,dep);
        maxDepth=max(maxDepth,d);
        return dep[i]=d;
    }
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        vector<long long> depth(n,-1);
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                depth[i]=1;
            }else{
                if(depth[i]==-1){
                    depth[i]=f(i,parent,depth);
                }
            }
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=nums[i]*(maxDepth-depth[i]+1);
        }
        return ans;
    }
};