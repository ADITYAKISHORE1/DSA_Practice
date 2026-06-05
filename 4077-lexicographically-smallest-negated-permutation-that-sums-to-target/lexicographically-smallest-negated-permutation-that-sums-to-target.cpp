class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int> perm;
        long long sum=0;
        for(int i=n;i>=1;i--){
            sum+=i;
            perm.push_back(i);
        }
        if(target>sum or (sum-target)&1) return {};
        long long diff=(sum-target)/2;
        for(int i=0;i<n;i++){
            if(diff>=perm[i]){
                diff-=perm[i];
                perm[i]=-perm[i];
            }
        }
        if(diff!=0) return {};
        sort(perm.begin(),perm.end());
        return perm;
    }
};