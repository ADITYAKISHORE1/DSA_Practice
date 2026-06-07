class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> pref(n,1),suf(n,1);
        pref[0]=1;
        suf[n-1]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) pref[i]=pref[i-1]+1;
            int j=n-i-1;
            if(ratings[j]>ratings[j+1]) suf[j]=suf[j+1]+1;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=max(pref[i],suf[i]);
        }
        return sum;
    }
};