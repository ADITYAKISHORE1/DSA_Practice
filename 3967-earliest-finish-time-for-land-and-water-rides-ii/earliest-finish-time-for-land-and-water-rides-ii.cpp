class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m=landStartTime.size();
        int n=waterStartTime.size();
        vector<pair<int,int>> land,water;
        for(int i=0;i<m;i++){
            land.push_back({landStartTime[i],landDuration[i]});
        }
        for(int i=0;i<n;i++){
            water.push_back({waterStartTime[i],waterDuration[i]});
        }
        sort(land.begin(),land.end());
        sort(water.begin(),water.end());
        vector<int> prefLand(m),prefWater(n);
        vector<int> sufLand(m),sufWater(n);
        prefLand[0]=land[0].second;
        for(int i=1;i<m;i++){
            prefLand[i]=min(prefLand[i-1],land[i].second);
        }
        prefWater[0]=water[0].second;
        for(int i=1;i<n;i++){
            prefWater[i]=min(prefWater[i-1],water[i].second);
        }
        sufLand[m-1]=land[m-1].first+land[m-1].second;
        for(int i=m-2;i>=0;i--){
            sufLand[i]=min(sufLand[i+1],land[i].first+land[i].second);
        }
        sufWater[n-1]=water[n-1].first+water[n-1].second;
        for(int i=n-2;i>=0;i--){
            sufWater[i]=min(sufWater[i+1],water[i].first+water[i].second);
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            int landEnd=land[i].first+land[i].second;
            int ub=upper_bound(water.begin(),water.end(),make_pair(landEnd,-1))-water.begin();
            if(ub>0){
                ans=min(ans,landEnd+prefWater[ub-1]);
            }
            if(ub<n){
                ans=min(ans,sufWater[ub]);
            }
        }
        for(int i=0;i<n;i++){
            int waterEnd=water[i].first+water[i].second;
            int ub=upper_bound(land.begin(),land.end(),make_pair(waterEnd,-1))-land.begin();
            if(ub>0){
                ans=min(ans,waterEnd+prefLand[ub-1]);
            }
            if(ub<m){
                ans=min(ans,sufLand[ub]);
            }
        }
        return ans;
    }
};