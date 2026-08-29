class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int maxVal = 0;
        int bestPrev = 0;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().first < events[i][0]) {
                bestPrev = max(bestPrev, pq.top().second);
                pq.pop();
            }
            maxVal = max(maxVal, events[i][2] + bestPrev);
            pq.push({events[i][1], events[i][2]});
        }
        return maxVal;
    }
};