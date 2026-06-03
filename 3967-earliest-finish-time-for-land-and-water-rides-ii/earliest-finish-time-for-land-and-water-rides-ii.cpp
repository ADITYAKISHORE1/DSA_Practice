class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();
        int minWaterEnd = INT_MAX, minLandEnd = INT_MAX;
        for (int i = 0; i < m; i++) {
            minLandEnd = min(minLandEnd, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < n; i++) {
            minWaterEnd =
                min(minWaterEnd, waterStartTime[i] + waterDuration[i]);
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; i++) {
            ans =min(ans, max(minWaterEnd, landStartTime[i]) + landDuration[i]);
        }
        for (int i = 0; i < n; i++) {
            ans =min(ans, max(minLandEnd, waterStartTime[i]) + waterDuration[i]);
        }
        return ans;
    }
};