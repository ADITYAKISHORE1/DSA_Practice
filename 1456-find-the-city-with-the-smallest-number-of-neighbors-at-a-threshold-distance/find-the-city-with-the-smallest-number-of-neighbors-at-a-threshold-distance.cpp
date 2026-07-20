class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (auto& i : edges) {
            dist[i[0]][i[1]] = i[2];
            dist[i[1]][i[0]] = i[2];
        }
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        int smallest = 1e9;
        int val = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= smallest) {
                smallest = count;
                val = i;
            }
        }
        return val;
    }
};