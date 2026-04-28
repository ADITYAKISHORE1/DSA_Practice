class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (auto& i : grid)
            for (auto& j : i)
                v.push_back(j);
        int rem=v[0]%x;
        for(auto& i:v){
            if(i%x!=rem) return -1;
            i=i/x;
        }
        auto cost =[&](int target){
            int a=0;
            for(auto& i:v){
                a+=abs(i-target);
            }
            return a;
        };
        int l=*min_element(v.begin(),v.end());
        int r=*max_element(v.begin(),v.end());
        while(l<r){
            int mid=l+(r-l)/2;
            int c1=cost(mid);
            int c2=cost(mid+1);
            if(c1<=c2) r=mid;
            else l=mid+1;
        }
        return cost(l);
    }
};