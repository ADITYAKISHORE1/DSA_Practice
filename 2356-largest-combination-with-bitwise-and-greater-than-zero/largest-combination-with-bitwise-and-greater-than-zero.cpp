class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        for(int b=0;b<32;b++){
            int cnt=0;
            for(auto& i:candidates){
                if((i>>b)&1) cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};