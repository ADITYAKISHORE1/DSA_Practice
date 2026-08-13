class Solution {
public:
    int reversePairs(vector<int>& arr) {
        int n=arr.size();
        vector<int> original=arr;
        //normalisation (making the vals between 1-size of array(maxm m))
        map<long long,int> mpp;
        for(auto i:arr) {
            mpp[2LL*i];
            mpp[i];}
        int c=1;
        for(auto& m:mpp){
            m.second=c++;
            }
        for(auto& i:arr) i=mpp[i];
        int m=mpp.size();
        vector<long long> bit(m+1,0);
        
        auto update=[&](int i) {
            while(i<=m){
                bit[i]+=1;
                i+=(i&-i);
            }
        };
        
        auto sum=[&](long long i) {
            long long s=0;
            while(i>0){
                s+=bit[i];
                i-=(i&-i);
            }  
            return s;
        };
        
        long long cnt=0;
        for(int i=0;i<n;i++){
            cnt+=sum(m)-sum(mpp[2LL*original[i]]);
            update(arr[i]);
        }
        return cnt;
    }
};