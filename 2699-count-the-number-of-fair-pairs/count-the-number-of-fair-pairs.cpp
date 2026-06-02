class Solution {
    long long ctPairs(vector<int>&v,long long target){
        int l=0,r=v.size()-1;
        long long cnt=0;
        while(l<r){
            if((long long)(v[l]+v[r])<=target){
                cnt+=(r-l);
                l++;
            }else r--;
        }
        return cnt;
    }
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        sort(v.begin(), v.end());
        return ctPairs(v,upper)-ctPairs(v,(long long)lower-1);
    }
};