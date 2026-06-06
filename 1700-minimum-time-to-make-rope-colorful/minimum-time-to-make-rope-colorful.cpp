class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=neededTime.size();
        int l=0;
        int grpMax=neededTime[0];
        int ans=accumulate(neededTime.begin(),neededTime.end(),0);
        for(int i=1;i<n;i++){
            if(colors[i]==colors[l]){
                grpMax=max(grpMax,neededTime[i]);
            }
            else{
                ans-=grpMax;
                l=i;
                grpMax=neededTime[i];
            }
        }
        ans-=grpMax;
        return ans;
    }
};