class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>> interval;
        for(int i=0;i<points.size();i++){
            if(interval.empty() or (interval.back()[1]<points[i][0])){
                interval.push_back(points[i]);
            }else{
                interval.back()[1]=min(interval.back()[1],points[i][1]);
            }
        }
        return interval.size();
    }
};