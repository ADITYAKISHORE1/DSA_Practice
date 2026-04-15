class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            double dist =
                sqrt((double)(points[i][0] * points[i][0]) + (double)(points[i][1] * points[i][1]));
            pq.push({dist, i});
        }
        int i = 0;
        while (pq.size() > k) pq.pop();
        vector<vector<int>> ans;
        while (!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            ans.push_back(points[idx]);
        }
        return ans;
    }
};
